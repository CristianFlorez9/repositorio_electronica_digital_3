/*Función: punto de entrada. Mantenerlo corto.

Secuencia:

Inicializar drivers (panel_iniciar, servos_iniciar, botones_leds_iniciar, uart_iniciar).
Inicializar la aplicación (sisyphus_iniciar, estados_iniciar).
Arrancar el temporizador registrando sisyphus_ciclo como callback.
Lazo principal: revisar banderas del pulsador, actualizar la máquina de estados, enviar telemetría cada 50 ms y actualizar LEDs.
*/


#include <stdio.h>
#include "pico/stdlib.h"


int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
