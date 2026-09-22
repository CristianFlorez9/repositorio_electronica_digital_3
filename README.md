# Stabilix
**Sistema de balanceo activo: mantiene una bola en el centro de una plataforma inclinable mediante control PID**

Proyecto de aula — Electrónica Digital 3 · 2026-2
**Equipo:** *Cristian Florez, Holman Londoño y Victor Ledezma* (Equipo Lobos)

---

## Idea inicial del proyecto

Este proyecto consiste en un sistema **ball & plate**: una bola se ubica libremente sobre una plataforma plana que puede inclinarse, y el sistema debe mantenerla en una posición de referencia (el centro) corrigiendo la inclinación en tiempo real.

Por su dinámica, la bola nunca se queda quieta por sí sola: en lazo abierto es inestable, y sin una corrección constante se sale del borde en cuestión de segundos. Por eso el proyecto exige un **lazo cerrado de retroalimentación** propiamente dicho —sensor midiendo la posición, controlador calculando la corrección, actuadores aplicándola sobre la plataforma, una y otra vez— para que la bola se mantenga balanceada en el centro.

### Mecánica

La plataforma superior es un disco de **acrílico transparente**, sostenido por brazos articulados sobre una base inferior donde están montados los servomotores de accionamiento, distribuidos para poder inclinar el disco en más de un eje.

### Estrategia de control

La posición de la bola sobre la plataforma se mide con *(pendiente confirmar: pantalla táctil resistiva / cámara cenital / otro sensor — la sección de abajo asume pantalla resistiva, la opción más común en este tipo de montajes)*, y ese error de posición respecto al centro alimenta un **controlador PID** (uno por eje, X y Y) que ajusta la inclinación de la plataforma a través de los servomotores.

### Microcontrolador y uso de interrupciones

Todo el lazo corre en una **Raspberry Pi Pico (RP2040)**, encargada de leer el sensor de posición, calcular el PID y generar las señales hacia los servomotores. La idea es apoyarse en los periféricos e interrupciones del RP2040 en vez de resolverlo todo por software en un `while(1)` que sondea:

- **Interrupción de temporizador (timer/alarm) para el lazo de control:** el PID no se ejecuta "tan rápido como el programa alcance", sino disparado por una interrupción de hardware a una frecuencia fija (p. ej. 100 Hz). Eso fija el período de muestreo, que es justamente una de las hipótesis con las que se diseña el controlador.
- **ADC para leer la posición de la bola:** con pantalla resistiva, medir X y Y implica alternar qué par de bordes se excita y cuál se lee, y convertir esa tensión con el ADC interno de la Pico. Esa conmutación de pines se sincroniza con la misma interrupción del temporizador, para no mezclar una lectura de X con una de Y.
- **Interrupción externa (GPIO IRQ):** un pulsador físico (recalibrar el centro de la plataforma, pausar el balanceo) se atiende por interrupción de flanco en vez de revisarlo por *polling* en el lazo principal.
- **PWM por hardware:** los tres servomotores se accionan con los canales de PWM del RP2040 (periodo y ciclo útil configurados por registro), no con PWM generado por software.
- **ISR cortas:** dentro de las rutinas de interrupción solo se actualiza una variable `volatile` o se levanta una bandera; el cálculo del PID y cualquier procesamiento más pesado se dejan para el lazo principal.

*(Pendiente: si el sensor final no es la pantalla resistiva, ajustamos el punto del ADC por lo que corresponda.)*

### Fabricación

*(Pendiente: material y método de fabricación de la base y los soportes — impresión 3D, corte láser, mecanizado, etc.)*

### Modos, entregables y riesgos

*(Pendiente: modos de operación — p. ej. calibración, balanceo automático, ajuste manual — y riesgos o condiciones de seguridad relevantes.)*

---

## Motivación

Nos parece que los sistemas embebidos y la teoría de control son una pareja casi perfecta: uno sin el otro se queda corto. La teoría de control te dice qué hacer con el error de la bola, pero es la parte embebida —temporizadores, interrupciones, ADC, PWM— la que decide si esa teoría realmente se ejecuta con la precisión que el modelo supone. Un balancín de bola es honesto en ese sentido: si el muestreo no es constante o el PWM tiembla, la bola simplemente no se queda quieta, sin importar qué tan bien esté sintonizado el PID en el papel.

Nos llamó la atención justo por eso: es un proyecto pequeño y de mesa, pero que obliga a tomarse en serio cada detalle de electrónica digital que hemos visto en el curso —desde cuándo usar una interrupción en vez de sondear un pin, hasta cómo sincronizar una lectura de ADC con el resto del lazo—, porque cualquier descuido se nota de inmediato en cómo se mueve la bola.
