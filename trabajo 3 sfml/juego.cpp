#include "juego.h"
#include <stdlib.h>

juego::juego(int ancho, int alto, std::string titulo)
{
	fps = 60; //fps a los que corre el juego
	TIEMPO_JUEGO = 30;//timer de nivel
	ventana1 = new RenderWindow(VideoMode(ancho, alto), titulo);

	ventana1->setFramerateLimit(fps);

	//sprites y textura de fondo
	background = new Texture;
	spriteBackground = new Sprite;
	//cargamos el fondo en la textura y la asignamos al sprite
	background->loadFromFile("/recursos/imagenes/fondo_plataformas.png");
	spriteBackground->setTexture(*background);
	//ajustamos al tamaño de ventana y escalamos el fondo
	spriteBackground->setScale((float)(ventana1->getSize().x) / background->getSize().x, (float)(ventana1->getSize().y) / background->getSize().y);

	//inicializamos el reloj

	reloj1 = new Clock;
	tiempo1 = new Time;
	tiempoInicio = reloj1->getElapsedTime().asSeconds() + TIEMPO_JUEGO;
	gameOver = false;


	//ajustes de HUD

	font = new Font;
	font->loadFromFile("assets/fuentes/fontnes.otf");
	stringTimerText = new Text();
	

}

void juego::gameLoop() {
	while (ventana1->isOpen()) {

	}
}