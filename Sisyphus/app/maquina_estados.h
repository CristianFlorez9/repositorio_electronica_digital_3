/*maquina_estados

Función: controlar los modos de operación del sistema.

Modos:

INIT (calibración): servos en posición plana; se registra la lectura del panel como origen (x0, y0).
RUN (control): lazo PID activo a 100 Hz.
PAUSE (seguridad): servos vuelven a plano y se pausa el acumulador integral.

Responsabilidades:

Atender los eventos del pulsador (calibrar, pausar, reanudar).
Detectar la pérdida de la bola por más de 500 ms y pasar a PAUSE.
Indicar a sisyphus si debe ejecutar el control o mantener la plataforma plana.
Informar el modo actual para los LEDs y la telemetría
*/