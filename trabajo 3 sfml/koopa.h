#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

class koopa
{
public:
	koopa();//el color sera generado al azar
	Sprite getSprite();
	Vector2f getPosition();
	void setPosition(float x, float y);
	void runLeft();
	void runRight();
private:
	Texture* textureKoopa;
	Sprite* spriteKoopa;
	int num;//aqui generamos el random del shell
	float aceleracion = 0.1f;
	float velocidadMaxima = 6.0f;
	float velocidadActual = 0.0f;
};