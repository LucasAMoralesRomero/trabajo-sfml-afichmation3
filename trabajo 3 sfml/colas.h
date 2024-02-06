#pragma once
#include "SFML/Graphics.hpp"
#include "koopa.h"
#include <iostream>

using namespace sf;

class colas {
public:
	colas();
	void InsertarNodo(koopa koopaTroopa);
	koopa QuitarNodo();//devolvemos un koopa para manipularlo en la clase juego
	
private:
	
	class Nodo {
	public:
		koopa koopaTroopa;
		Nodo* siguienteNodo;

		// Constructor con valor predeterminado para koopaTroopa
		Nodo(koopa koopa = koopa()) : koopaTroopa(koopa), siguienteNodo(nullptr) {}
	};
    friend class juego;//permite que juego acceda a las variables privadas de la clase
	Nodo* primero;
	Nodo* ultimo;
	koopa koopaObtenido;
};
