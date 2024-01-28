#include "colas.h"

colas::colas() : primero(nullptr), ultimo(nullptr)
{
	//iniciamos la cola vacía, ya que las variables miembro primero y ultimo están en la clase colas
}

void colas::InsertarNodo(koopa koopaTroopa)
{
	Nodo *nuevoKoopa = new Nodo();
	nuevoKoopa->koopaTroopa = koopaTroopa;
	nuevoKoopa->siguienteNodo = nullptr;

	if (primero == nullptr)
	{
		primero = nuevoKoopa;
	}
	else
	{
		ultimo->siguienteNodo = nuevoKoopa;
	}

	ultimo = nuevoKoopa;
}

void colas::QuitarNodo()
{
	koopaObtenido = primero->koopaTroopa;
	Nodo *Aux = primero;
	if (primero == ultimo)
	{
		primero = nullptr;
		ultimo = nullptr;
	}
	else
	{
		primero = primero->siguienteNodo;
	}
	koopaObtenido.runRight();
	if(koopaObtenido.getPosition)
	InsertarNodo(koopaObtenido);
	delete Aux;
}