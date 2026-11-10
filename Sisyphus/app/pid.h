/*Función: controlador PID discreto genérico, usado una vez por eje (X e Y).

Responsabilidades:

Mantener el estado de cada instancia (ganancias, integral, error anterior, límites de salida).
Calcular la salida a partir del error y el período de muestreo.
Aplicar anti-windup para evitar la acumulación del término integral al saturar.
Permitir pausar y reiniciar el acumulador integral.
Ser independiente del hardware, por lo que se puede probar en el computador.
*/