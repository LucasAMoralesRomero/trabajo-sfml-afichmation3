#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

class koopa
{
public:
	koopa(int color);//le pasamos un numero del 1 al 4 para seleccionar el color
	Sprite getSprite();
	FloatRect getPosition();
	void setPosition(float x, float y);
private:
	Texture textureKoopa;
	Sprite spriteKoopa;
};