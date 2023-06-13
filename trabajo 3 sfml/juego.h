#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "mario.h"

using namespace sf;
using namespace std;

class juego {

public:
	juego(int ancho, int alto, string titulo);
	void gameLoop();
	void dibujar();
	void procesarEventos();
	void procesarColisiones();
	void procesarTiempo();
	void checkWin();
private:

	//variables de ventana
	RenderWindow * ventana1;
	int fps;
	Texture * background;
	Sprite * spriteBackground;

	//variables de mario
	Event * evento1;
	mario *  Mario;
	bool enPiso = true;

	//variable de juego (mundo)

	int piso[7]{380, 370, 360, 350, 340, 330, 320}; //array con pisos

	bool win = false;

	//variables de juego(clock)
	Clock * reloj1;
	Time * tiempo1;
	float tiempoInicio;
	float tiempoFin;
	int TIEMPO_JUEGO;//en segundos
	bool gameOver;//bandera de fin de juego (fin de tiempo)

	//variable de HUD

	Font  * font;
	String stringTimer;
	Text * stringTimerText;
	String stringGameOver;
	Text * stringGameOverText;
	Text * stringGameWinText;
};