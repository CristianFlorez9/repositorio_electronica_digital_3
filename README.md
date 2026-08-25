# repositorio_electronica_digital_3

Repositorio Proyecto Final – Electrónica Digital III (Equipo Lobos)

# PicoRider

**Motocicleta a control remoto con autoequilibrio activo, basada en Raspberry Pi Pico W**

Proyecto de aula — Electrónica Digital 3 · 2026-2
**Equipo:** *Cristian Florez, Holman Londoño y Victor ledezma*

---

## Idea inicial del proyecto

PicoRider es el **diseño, fabricación e integración de una motocicleta a escala, controlada por Bluetooth y capaz de mantenerse en equilibrio sobre sus dos ruedas mediante control activo**.

A diferencia de un carro RC —estable por construcción— una moto es mecánicamente inestable: si el lazo de control se detiene, el vehículo se cae. Eso convierte el proyecto en un caso real de **sistema embebido de tiempo real**, donde el firmware no es un accesorio sino la condición para que el producto funcione. Toda la lógica corre en una **Raspberry Pi Pico W (RP2040)**, que concentra sensado, control, accionamiento y enlace inalámbrico. El resultado esperado: un prototipo que se conduce desde un control remoto para acelerar, frenar y girar mientras el firmware se encarga de que no se caiga.

### Estrategia de control

El equilibrio se logrará con un **volante de inercia (*reaction wheel*)** montado transversalmente: al acelerar o frenar ese disco, la moto recibe un par de reacción que corrige la inclinación lateral. Es la única solución que funciona también con el vehículo detenido.

El control se plantea en **cascada**: un lazo de equilibrio (PID sobre el ángulo de alabeo, estimado con filtro complementario entre acelerómetro y giroscopio), un lazo de descarga que mantiene la velocidad del volante cerca de cero para que no sature, y un lazo de conducción que traduce los comandos del usuario.

Un punto clave: **la referencia de inclinación no es cero**. Al pedir giro, el lazo de conducción calcula la inclinación necesaria para esa curva y se la ordena al lazo de equilibrio, de modo que la moto se recuesta hacia adentro como una moto real. Los comandos entran como *solicitud* y se limitan según la velocidad, porque el par del volante es finito.

### Fabricación

Chasis y carrocería **impresos en 3D**, con el centro de masa lo más bajo posible, y **PCB propia** en KiCad que integra la Pico W, los drivers y la regulación.

### Modos, entregables y riesgos

**Modos:** standby (equilibrio detenido) · manual (conducción por Bluetooth) · seguro (paro de emergencia, pérdida de enlace, batería baja o sobrecorriente).

---

## Motivación

Nos gustan las motos y la electrónica. A ninguno de nosotros nos hizo ilusión la idea de otro proyecto que se quedara en una protoboard mostrando datos en una pantalla: queríamos algo que se pudiera tomar con las manos, encender y conducir.

De todas las ideas que barajamos, la moto fue la que más nos costó dar por sentada. Un carro a control remoto es un ejercicio conocido y resuelto; una moto que se sostiene sola no lo es, y esa dificultad fue justamente lo que nos convenció. Nos atrae que el equilibrio dependa por completo de lo que escribamos en el firmware: si el lazo está mal ajustado, el proyecto literalmente se cae al piso. Sumado a eso, queríamos un proyecto donde se abarcaran varios temas y retos y al final, queremos terminar el semestre con algo que se entienda sin explicar.
