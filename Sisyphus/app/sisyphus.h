/*Función: unir los módulos y ejecutar el ciclo de control. Es el callback que se registra en el temporizador.

Responsabilidades:

Leer el panel, filtrar, calcular el error respecto al origen (x0, y0) y evaluar los dos PID.
Aplicar la cinemática y escribir los ángulos en los servos.
Si no hay contacto, avisar a la máquina de estados y no actualizar el PID con datos inválidos.
Guardar en variables volatile lo que el lazo principal necesita leer (posición, error, salidas).
Mantener un tiempo de ejecución menor a 2 ms, que es lo que mide RNF-03.*/