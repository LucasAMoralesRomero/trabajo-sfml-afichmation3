#include "koopa.h"
#include <stdlib.h>

koopa::koopa()
{
	//iniciamos el koopa
	//generamos un valor random para el shell
	textureKoopa = new Texture;
	spriteKoopa = new Sprite;
	int num = 0 + rand() % (4 - 1);
	switch (num) {
	case 0:
		textureKoopa->loadFromFile("recursos/imagenes/shell_amarillo.png");
		break;
	case 1:
		textureKoopa->loadFromFile("recursos/imagenes/shell_azul.png");
		break;
	case 2:
		textureKoopa->loadFromFile("recursos/imagenes/shell_rojo.png");
		break;
	case 3:
		textureKoopa->loadFromFile("recursos/imagenes/shell_verde.png");
		break;
	default:

		textureKoopa->loadFromFile("recursos/imagenes/shell_unknown.png");
	}
	//asignamos la textura al sprite
	spriteKoopa->setTexture(*textureKoopa);

}

Sprite koopa::getSprite()
{
	return *spriteKoopa;
}

Vector2f koopa::getPosition()
{
		Vector2f  posicion = spriteKoopa->getPosition();
		return posicion;
}

void koopa::setPosition(float x, float y)
{
	spriteKoopa->setPosition(x, y);
}

void koopa::runLeft()
{
	//movimiento basado en movimiento de mario.cpp
	velocidadActual = velocidadActual + aceleracion;//aceleramos el movimiento del personaje
	if (velocidadActual > velocidadMaxima)//si la aceleracion es mayor a la maxima, la seteamos nuevamente
	{
		velocidadActual = velocidadMaxima;
	}
	spriteKoopa->setPosition(spriteKoopa->getPosition().x - velocidadActual, spriteKoopa->getPosition().y);
}

void koopa::runRight()
{
	//movimiento basado en movimiento de mario.cpp
	velocidadActual = velocidadActual + aceleracion;//aceleramos el movimiento del personaje
	if (velocidadActual > velocidadMaxima)//si la aceleracion es mayor a la maxima, la seteamos nuevamente
	{
		velocidadActual = velocidadMaxima;
	}
	spriteKoopa->setPosition(spriteKoopa->getPosition().x + velocidadActual, spriteKoopa->getPosition().y);
}
