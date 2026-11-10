/*
Función: generar la interrupción periódica de hardware que fija el período de muestreo.

Responsabilidades:

Configurar una alarma del timer del RP2040 a la frecuencia pedida (100 Hz).
Contener la ISR real, que solo llama al callback registrado y reprograma la siguiente alarma.
Garantizar un período fijo, que es la hipótesis con la que se diseña el PID discreto.

Notas: para la prueba PA-01, esta ISR puede conmutar un GPIO de prueba al entrar y al salir, y así medir el tiempo en alto con el osciloscopio.
*/