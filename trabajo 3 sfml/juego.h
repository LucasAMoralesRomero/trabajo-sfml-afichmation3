#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "mario.h"
#include "audioEngine.h"
#include "Afichmation.h"

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
	void procesarMusica();//procesamos musica de ambiente

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

	
	//array con pisos
	//int piso[7]{ 395,552,278,215,156,98,37 };
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