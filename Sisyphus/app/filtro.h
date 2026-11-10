/*Función: suavizar la posición medida antes de llegar al PID, ya que el panel resistivo es ruidoso.

Responsabilidades:

Implementar un filtro simple (media móvil o pasa-bajas de primer orden).
Mantener su propio estado por canal (x e y).
Permitir reiniciarse cuando la bola se retira, para no arrastrar valores viejos.
*/