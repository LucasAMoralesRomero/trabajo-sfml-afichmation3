#include "SFML\Graphics.hpp"
#include "juego.h"

using namespace sf;
using namespace std;

int main(int argc, char * args[])
{
	//srand(time(NULL));
	juego * partida1;
	partida1 = new juego(640, 480, "Juego de mario");
	return 0;
}