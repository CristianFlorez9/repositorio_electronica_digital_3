/*Función: armar los mensajes de monitoreo y enviarlos por UART cada 50 ms.

Responsabilidades:

Formatear en una línea de texto o CSV la posición, el error, la salida del PID y el modo.
Pasar el texto a uart_serial sin bloquear.
Generar un formato que sirva para el Serial Plotter y para guardar el .csv de las pruebas.
*/