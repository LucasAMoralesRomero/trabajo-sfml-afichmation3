#include "mario.h"
#include <stdlib.h>
//395 es el floor
mario::mario()
{
	//sprite y textura de mario
	textureMario = new Texture;
	//inicializamosd a mario
	textureMario->loadFromFile("recursos/imagenes/spritesheet.png");
	spriteMario = new Afichmation(*textureMario, true, 104, 125);

	//añadimos las animaciones que se van a usar
	spriteMario->Add("idle", {0,1,2,1,0}, 8, true);
	spriteMario->Add("run", { 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7 }, 8, true);
	spriteMario->Add("jump", { 12, 13, 14, 13, 12 }, 8, false);
	//reproduzco la animacion idle
	spriteMario->Play("idle");
	//seteo la escala del sprite con setScale
	spriteMario->setScale(Vector2f(0.5f, 0.5f));
	//ubicamos al personaje en piso 0 en el medio
	spriteMario->move(330.0f,1.0f);

}

void mario::update()//updateamos a mario
{
	spriteMario->Update();
}

Afichmation mario::getMario()
{
	return *spriteMario;
}

void mario::runLeft() {
	velocidadActual = velocidadActual + aceleracion;//aceleramos el movimiento
	if (velocidadActual > velocidadMaxima)//si la aceleracion es mayor a la maxima, la seteamos nuevamnete
	{
		velocidadActual = velocidadMaxima;
	}
	spriteMario->Play("run");
	spriteMario->FlipX(false);
	spriteMario->setPosition(spriteMario->getPosition().x - velocidadActual, spriteMario->getPosition().y);
	//para definir los floors funcion que manda a consola la posicion de mario
	cout << "movimiento a izquierda";
	cout << "mario x ";
	cout << spriteMario->getPosition().x;
	cout << "mario y ";
	cout << spriteMario->getPosition().y << endl;
}

void mario::runRight() {
	velocidadActual = velocidadActual + aceleracion;
	if (velocidadActual > velocidadMaxima)//si la aceleracion es mayor a la maxima, la seteamos nuevamnete
	{
		velocidadActual = velocidadMaxima;
	}
	spriteMario->Play("run");
	spriteMario->FlipX(true);
	spriteMario->setPosition(spriteMario->getPosition().x + velocidadActual, spriteMario->getPosition().y);
	//para definir los floors funcion que manda a consola la posicion de mario
	cout << "movimiento a derecha";
	cout << "mario x ";
	cout << spriteMario->getPosition().x;
	cout << "mario y ";
	cout << spriteMario->getPosition().y << endl;
}

void mario::jump(int numeroPiso) {
	/*se define la implemetacion del salto pero permanecera comentada
	mientras este en desarrollo el array de pisos*/
	
	cout << "Jump" << endl;

	/*
	if (spriteMario->getPosition().y == floor) // salto de mario
	{
		if (en_piso)
		{
			spriteMario->Play("jump");
			spriteMario->setPosition(spriteMario->getPosition().x, spriteMario->getPosition().y - 80);
			jumpVelocity += gravity;
			jumpVelocity = -10.f; // reiniciar la velocidad de salto
			en_piso = false;//desactivamos bandera del piso
			activar_idle = false;//desactivamos bandera de idle
		}
	}
	*/
}

//variables de test para desarrollo de juego

void mario::testUp() {
	spriteMario->setPosition(spriteMario->getPosition().x, spriteMario->getPosition().y - 1);
	cout << "movimiento arriba";
	cout << "mario x ";
	cout << spriteMario->getPosition().x;
	cout << "mario y ";
	cout << spriteMario->getPosition().y << endl;
}

void mario::testDown() {
	spriteMario->setPosition(spriteMario->getPosition().x, spriteMario->getPosition().y + 1);
	cout << "movimiento abajo";
	cout << "mario x ";
	cout << spriteMario->getPosition().x;
	cout << "mario y ";
	cout << spriteMario->getPosition().y << endl;
}