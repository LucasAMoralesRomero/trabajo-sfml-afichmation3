#include "juego.h"
#include "mario.h"
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
	background->loadFromFile("recursos/imagenes/fondo_plataformas.png");
	spriteBackground->setTexture(*background);
	//ajustamos al tamaño de ventana y escalamos el fondo
	spriteBackground->setScale((float)(ventana1->getSize().x) / background->getSize().x, (float)(ventana1->getSize().y) / background->getSize().y);

	//iniciamos a mario
	Mario = new mario;
	
	//inicializamos el reloj

	reloj1 = new Clock;
	tiempo1 = new Time;
	tiempoInicio = reloj1->getElapsedTime().asSeconds() + TIEMPO_JUEGO;
	gameOver = false;


	//ajustes de HUD

	font = new Font;
	font->loadFromFile("recursos/fuentes/fontnes.otf");
	stringTimerText = new Text();
	stringTimerText->setFont(*font);
	stringTimerText->setFillColor(sf::Color::White);
	stringTimerText->setPosition(400, 1);

	stringGameOverText = new Text();
	stringGameOverText->setFont(*font);
	stringGameOverText->setString("Time's up, GAME OVER!");
	stringGameOverText->setFillColor(sf::Color::Red);
	stringGameOverText->setPosition((float)(ventana1->getSize().x / 3), (float)(ventana1->getSize().y / 2));

	stringGameWinText = new Text();
	stringGameWinText->setFont(*font);
	stringGameWinText->setString("Ganaste!");
	stringGameWinText->setFillColor(sf::Color::Green);
	stringGameWinText->setPosition((float)(ventana1->getSize().x / 3), (float)(ventana1->getSize().y / 2));

	evento1 = new Event;
	gameLoop();
}

void juego::gameLoop() {
	while (ventana1->isOpen()) {
		*tiempo1 = reloj1->getElapsedTime();
		//explicacion del if si tiempo1 es mayor que 1/fps y no es gameover y no es condicion de ganar haz esto
		if (tiempo1->asSeconds() > 1 / fps && !gameOver && !win) {
			procesarColisiones();
			procesarEventos();
			Mario->update();
			dibujar();
			procesarTiempo();
			checkWin();
		}
		if (gameOver) {
			ventana1->clear();
			ventana1->draw(Mario->getMario());
		}
	}
}

void juego::procesarColisiones() {

}

void juego::procesarEventos() {
	while (ventana1->pollEvent(*evento1))
	{
		switch (evento1->type)
		{
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		default:
			break;
		}
	}
}

void juego::dibujar() {
	ventana1->clear();
	ventana1->draw(*spriteBackground);
	ventana1->draw(Mario->getMario());
	ventana1->draw(*stringTimerText);
	ventana1->display();
}

void juego::procesarTiempo() {
	tiempoFin = reloj1->getElapsedTime().asSeconds();
	int seconds = ((int)(tiempoInicio - tiempoFin));
	stringTimerText->setString("Tiempo: " + (std::to_string(seconds)));
	if (seconds == -1 || seconds < -2)//se busca ver que el tiempo no sea cero para disparar el gameover
	{
		gameOver = true;
	}
}

void juego::checkWin() {

}