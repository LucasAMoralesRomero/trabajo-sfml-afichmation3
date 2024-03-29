#pragma once
#include "SFML\Graphics.hpp"
#include "Afichmation.h"
#include <iostream>

using namespace sf;

class mario {

public: 
	mario();
	void update();//para updatear a mario
	//para mover a mario
	void runLeft();//correr a la izquierda
	void runRight();//correr a la derecha
	void jump(float floor);//saltar a proximo piso le pasamos el numero de piso
	void stayIdle();//dejamos a mario en idle
	void setPosition(float x, float y);//seteamos a mario
	Vector2f getPosition();//obtenemos la posicion de mario
	bool getStatus();//devuelve si esta o no idle
	void setIdle(bool status);//seteamos idle

	//variables de desarrollo (test)
	void testUp();
	void testDown();

	Afichmation getMario(); //para obtener sprite de mario

private:
	//variables de mario
	Event * evento1;
	Texture * textureMario;
	Afichmation * spriteMario;
	float jumpVelocity = -10.f;
	bool en_piso = true;
	bool activar_idle = true;
	float aceleracion = 0.1f;
	float velocidadMaxima = 6.0f;
	float velocidadActual = 0.0f;
	int floor;//definimos el piso de mario
	const float gravity = 0.5f;
};