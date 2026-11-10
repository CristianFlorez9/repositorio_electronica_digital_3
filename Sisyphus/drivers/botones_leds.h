/*Función: gestionar el pulsador físico y los LEDs de estado.

Responsabilidades:

Atender el pulsador por interrupción de flanco (GPIO IRQ) con antirrebote.
Avisar a la aplicación mediante un callback o una bandera volatile; la ISR no hace nada más.
Encender y apagar los LEDs de estado según lo que indique la aplicación.
*/