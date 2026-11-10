/* 
  Funcion : leer la posicion de la bola en el panel resistivo  de 4 hilos mediante digitalizador por SPI

  Responsabilidades:
     Inicializar el SPI y le sellecion de chip
     Realizar la lectura secuencial de X e Y y entregarla en unidades crudas al ADC
     Indicar si hay contacto(bola presente o no)
     NO filtra, no calibra y no interpreta: solo entrega la medida.
     
     Notas: medir cuánto dura una lectura completa de X e Y; debe caber con holgura dentro de los 10 ms del período.
*/

