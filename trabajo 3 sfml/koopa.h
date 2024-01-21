#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

class koopa
{
public:
	koopa();//el color sera generado al azar
	Sprite getSprite();
	FloatRect getPosition();
	void setPosition(float x, float y);
private:
	Texture* textureKoopa;
	Sprite* spriteKoopa;
	int num;//aqui generamos el random del shell
};