#include "colas.h"
using namespace std;
struct Nodo {
	koopa koopaTroopa;
	Nodo* siguienteNodo;
};

colas::colas(int cantidadKoopas)
{
	//iniciamos la cola vacia
	Nodo *primero = NULL;
	Nodo *ultimo = NULL;
	//generamos un array de koopas
	for (int h = 0; h < 4; h++)
	{
		arrayKoopas[h] = new koopa(h);
	}
	for (int i = 0; i < cantidadKoopas; i++)
	{
		InsertarNodo(primero, ultimo, arrayKoopas*[i]);
	}

}

void colas::InsertarNodo(Nodo *& primero, Nodo *& ultimo, koopa koopaTroopa)
{
	Nodo *nuevoKoopa = new Nodo();
	nuevoKoopa->koopaTroopa =  koopaTroopa;
	nuevoKoopa->siguienteNodo = NULL;
	if (primero == NULL)
	{
		primero = nuevoKoopa;
	}
	else
	{
		ultimo->siguienteNodo = nuevoKoopa;
	}
	ultimo = nuevoKoopa;
}

void colas::QuitarNodo(Nodo *& primero, Nodo *& ultimo, koopa koopaTroopa)
{
	koopaObtenido = primero->koopaTroopa;
	Nodo *Aux = primero;
	if (primero == ultimo)
	{
		primero = NULL;
		ultimo = NULL;
	}
	else
	{
		primero = primero->siguienteNodo;
	}
	delete Aux;
}
