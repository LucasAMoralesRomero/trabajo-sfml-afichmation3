#include "SFML\Graphics.hpp"
#include "juego.h"
/*

Funcionalidad:
Crear seis (6) plataformas por donde nuestro personaje pueda desplazarse. OK
Las plataformas pueden ser atravesados por el player de abajo hacia arriba con la opción de salto. Las plataformas solo se pueden subir una a una. No se puede volver a plataformas inferiores. OK
El player inicia el juego en el piso cero (0) y debe finalizar el juego colisionando con la puerta de salida que está ubicada en el piso seis (6). OK
Colocar un contador en reversa de treinta (30) segundos (límite para alcanzar el objetivo). OK
Colocar los enemigos en cada piso. Los enemigos se desplazan de derecha a izquierda o viceversa. Máximo de enemigos por piso: cuatro (4).
Un solo enemigo a la vez puede desplazarse en un piso. Cuando ese enemigo termine de desplazarse recién ahí inicia el desplazamiento de otro.
Aplicar en tres (3) pisos a los enemigos la siguiente funcionalidad de colas, emplear una cola para insertarle como nodos Sprites de los enemigos.
Cuando el player es tocado por algún enemigo, este debe caer hasta el piso cero 0.
Las condiciones de fin de juego son dos:
Tiempo en cero (0), derrota. OK
Colisionar contra la puerta de salida, victoria. OK

*/



using namespace sf;
using namespace std;

int main(int argc, char * args[])
{
	srand(time(NULL));
	juego * partida1;
	partida1 = new juego(640, 480, "Juego de mario 2");
	return 0;
}