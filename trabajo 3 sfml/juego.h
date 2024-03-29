#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "mario.h"
#include "audioEngine.h"
#include "Afichmation.h"
#include "colas.h"

using namespace sf;
using namespace std;

class juego {

public:
	juego(int ancho, int alto, string titulo);
	void gameLoop();
	void dibujar();
	void dibujarWin();
	void dibujarGameOver();
	void procesarEventos();
	void procesarColisiones();
	void procesarTiempo();
	void checkWin();
	void procesarMusica();//procesamos musica de ambiente
	void procesarGravedad();

private:

	//variables de ventana
	RenderWindow * ventana1;
	int fps;
	Texture * background;
	Sprite * spriteBackground;
	Texture *door;
	Sprite *spriteDoor;

	//variables de mario
	Event * evento1;
	mario *  Mario;
	bool enPiso = true;
	float jumpVelocity = -10.f;
	bool activar_idle = true;
	float aceleracion = 0.1f;
	float velocidadMaxima = 6.0f;
	float velocidadActual = 0.0f;

	//variable de juego (mundo)

	//variable de enemigos
	//colas de piso 1
	colas piso1Cola1;
	//banderas para cola en piso1
	bool piso1Pop = false;//bandera para sacar 1 koopa
	bool piso1Desaparecio = false;//bandera para indicar que el koopa desaprecio del escenario
	//koopa en piso 1
	koopa* koopa1;
	koopa* koopa2;
	koopa* koopa3;
	koopa* koopa4;
	//koopa que vamos a manpular moviendololo por el escenario
	koopa* koopaEnPiso1;

/*
INFORMACION DE PISOS:
piso 0 y =395.5
piso 1 y =335.5
piso 2 y =276.5
piso 3 y =216.5
piso 4 y =157.5
piso 5 y =96.5
piso 6 y =38.5

*/
	float stages[7]{ 395.5,335.5,276.5,216.5,157.5,96.5,38.5};//almacenamos los pisos
	const float gravity = 0.5f;
	float floor = stages[0];
	audioEngine * audio;//desde esta variable accedemos a los sonidos



	bool win = false;

	//variables de juego(clock)
	Clock * reloj1;
	Time * tiempo1;
	float tiempoInicio;
	float tiempoFin;
	int TIEMPO_JUEGO;//en segundos
	bool gameOver;//bandera de fin de juego (fin de tiempo)
	bool hurryUp;//bool para reproducir el sonido mas rapido

	//variable de HUD

	Font  * font;
	String stringTimer;
	Text * stringTimerText;
	String stringGameOver;
	Text * stringGameOverText;
	Text * stringGameWinText;
};