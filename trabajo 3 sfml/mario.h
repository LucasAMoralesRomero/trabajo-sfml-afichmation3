#pragma once
#pragma once
#include "SFML\Graphics.hpp"
#include "Afichmation.h"
#include <iostream>

using namespace sf;

class mario {

public: 
	mario();
	void update();//para updatear a mario
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
};