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

koopa colas::QuitarNodo()
{
	if (primero == nullptr) {
		// Manejo del caso cuando la cola está vacía
		// Por ejemplo, podrías lanzar una excepción o devolver un valor predeterminado.
		// Aquí se devuelve un koopa por defecto
		return koopa();
	}

	Nodo *Aux = primero;
	koopaObtenido = primero->koopaTroopa;

	if (primero == ultimo)
	{
		primero = nullptr;
		ultimo = nullptr;
	}
	else
	{
		primero = primero->siguienteNodo;
	}

	delete Aux;
	return koopaObtenido;
}