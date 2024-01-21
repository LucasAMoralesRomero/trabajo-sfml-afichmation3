#include "koopa.h"
#include <stdlib.h>

koopa::koopa()
{
	//iniciamos el koopa
	//generamos un valor random para el shell
	int num = 0 + rand() % (4 - 1);
	switch (num) {
	case 0:
		textureKoopa.loadFromFile("recursos/imagenes/shell_amarillo.png");
		break;
	case 1:
		textureKoopa.loadFromFile("recursos/imagenes/shell_azul.png");
		break;
	case 2:
		textureKoopa.loadFromFile("recursos/imagenes/shell_rojo.png");
		break;
	case 3:
		textureKoopa.loadFromFile("recursos/imagenes/shell_verde.png");
		break;
	default:

		textureKoopa.loadFromFile("recursos/imagenes/shell_unknown.png");
	}
	//asignamos la textura al sprite
	spriteKoopa.setTexture(textureKoopa);

}

Sprite koopa::getSprite()
{
	return spriteKoopa;
}

FloatRect koopa::getPosition()
{
	FloatRect posicion = spriteKoopa.getGlobalBounds();
	return posicion;
}

void koopa::setPosition(float x, float y)
{
	spriteKoopa.setPosition(x, y);
}
