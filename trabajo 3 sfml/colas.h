#pragma once
#include "SFML/Graphics.hpp"
#include "koopa.h"
#include <iostream>

using namespace sf;

class colas {
public:
	colas();
	void InsertarNodo(koopa koopaTroopa);
	void QuitarNodo();
	
private:
	class Nodo {
	public:
		koopa koopaTroopa;
		Nodo* siguienteNodo;

		// Constructor con valor predeterminado para koopaTroopa
		Nodo(koopa koopa = koopa()) : koopaTroopa(koopa), siguienteNodo(nullptr) {}
	};

	Nodo* primero;
	Nodo* ultimo;
	koopa koopaObtenido;
};
