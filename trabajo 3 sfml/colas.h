#pragma once
#include "SFML/Graphics.hpp"
#include "koopa.h"
#include <iostream>

using namespace sf;

class colas
{
public:
	colas(int cantidadKoopas);//le paso cuanto koopas quiero en la cola
	void InsertarNodo(Nodo *&primero, Nodo *&ultimo, koopa koopaTroopa);
	void QuitarNodo(Nodo *&primero, Nodo *&ultimo, koopa koopaTroopa);

private:
	struct Nodo;
	koopa koopaTroopa;
	Nodo *siguienteNodo;
	koopa koopaObtenido;//aca guardamos el koopa que sale de la lista
	koopa * arrayKoopas[4];
};