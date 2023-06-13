#include "mario.h"
#include <stdlib.h>
//340 es el floor
mario::mario()
{
	//sprite y textura de mario
	textureMario = new Texture;
	//inicializamosd a mario
	textureMario->loadFromFile("recursos/imagenes/spritesheet.png");
	spriteMario = new Afichmation(*textureMario, true, 104, 125);

	//a�adimos las animaciones que se van a usar
	spriteMario->Add("idle", {0,1,2,1,0}, 8, true);
	spriteMario->Add("run", { 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7 }, 8, true);
	spriteMario->Add("jump", { 12, 13, 14, 13, 12 }, 8, false);
	//reproduzco la animacion idle
	spriteMario->Play("idle");
	//seteo la escala del sprite con setScale
	spriteMario->setScale(Vector2f(0.5f, 0.5f));
	//ubicamos al personaje
	spriteMario->move(500, 340);

}

void mario::update()//updateamos a mario
{
	spriteMario->Update();
}

Afichmation mario::getMario()
{
	return *spriteMario;
}

