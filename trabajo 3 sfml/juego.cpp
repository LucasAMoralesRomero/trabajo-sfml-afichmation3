#include "juego.h"
#include "mario.h"
#include "koopa.h"
#include "colas.h"
#include "audioEngine.h"
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
	//sprite y textura de la puerta
	door = new Texture;
	spriteDoor = new Sprite;
	//cargamos la textura de la puerta y la asignamos al sprite
	door->loadFromFile("recursos/imagenes/puerta.png");
	spriteDoor->setTexture(*door);
	// Obtener el tamaño del sprite
	sf::Vector2u spriteSize = door->getSize();
	// Establecer el origen en el centro del sprite
	spriteDoor->setOrigin(spriteSize.x / 2.0f, spriteSize.y / 2.0f);
	//ubicamos la puerta
	spriteDoor->setPosition(320, 38.5);
	//ajustamos al tamaño de ventana y escalamos el fondo
	spriteBackground->setScale((float)(ventana1->getSize().x) / background->getSize().x, (float)(ventana1->getSize().y) / background->getSize().y);

	//iniciamos los enemigos del piso 1
	colas piso1Cola1;
	koopa1 = new koopa;
	koopa2 = new koopa;
	koopa3 = new koopa;
	koopa4 = new koopa;
	//seteamos los koopa en el piso 1
	koopa4->setPosition(600, stages[1]);
	koopa3->setPosition(570, stages[1]);
	koopa2->setPosition(540, stages[1]);
	koopa1->setPosition(510, stages[1]);
	//agregamos los enemigos a la cola 1
	piso1Cola1.InsertarNodo(*koopa1);
	piso1Cola1.InsertarNodo(*koopa2);
	piso1Cola1.InsertarNodo(*koopa3);
	piso1Cola1.InsertarNodo(*koopa4);
	//probamos a sacar un nodo
	piso1Cola1.QuitarNodo();
	koopa1->runRight();

	//iniciamos a mario
	Mario = new mario;
	
	//inicializamos el reloj

	reloj1 = new Clock;
	tiempo1 = new Time;
	tiempoInicio = reloj1->getElapsedTime().asSeconds() + TIEMPO_JUEGO;
	gameOver = false;

	//generamos el audioEngine
	audio = new audioEngine();

	hurryUp = false;//asignamos la bandera de hurry up en false, recien inicio el juego

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
			procesarMusica();
			procesarGravedad();
		}
		else if (gameOver) {
			dibujarGameOver();
			procesarEventos();
			//reproducimos el sonido de ganar
			//primero detenemos la musica ambiente
			audio->stopBackgroundSound();
			//ahora reproducimos el sonido de perder
			audio->playMusicdGameOver();
			procesarGravedad();
			sleep(seconds(2.0));//esperamos 2 segundos mientras se reproduce el sonido
			exit(0);
		}
		else if (win)
		{
			dibujarWin();
			procesarEventos();
			//reproducimos el sonido de ganar
			//primero detenemos la musica ambiente
			audio->stopBackgroundSound();
			//ahora reproducimos el sonido de ganar
			audio->playMusicWin();

			procesarGravedad();
			Mario->update();
			
			sleep(seconds(3.0));//esperamos 3 segundos mienras se reproduce el sonido
			exit(1);
		}
	}
}

void juego::procesarGravedad() {//aca procesamos la gravedad para mario
	// No es necesario cambiar la posición en el eje X para la gravedad
	jumpVelocity += 0.5f; // Ajuste de gravedad

	// Asegurarse de que el personaje no se hunda en el suelo
	if (Mario->getPosition().y > floor) {
		Mario->setPosition(Mario->getPosition().x, (float)floor);
		enPiso = true;
		activar_idle = true;
	}
}

void juego::procesarColisiones() {
	/*procesar colision con la puerta
	 Obtén el rectángulo delimitador global de Mario*/
	sf::FloatRect boundsMario = Mario->getMario().getGlobalBounds();

	// Procesar colisión con la puerta
	if (spriteDoor->getGlobalBounds().intersects(boundsMario)) {
		// Hacer algo cuando hay colisión
		win = true;
		std::cout << "Colisión con la puerta\n";
	}
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
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Left))//movemos a la izquierda con Mario->runLeft()
			{
				Mario->setIdle(false);
				Mario->runLeft();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))//movemos a la derecha con Mario->runRight()
			{
				Mario->setIdle(false);
				Mario->runRight();
			}
			//codigo de prueba para determinar el piso de la actividad  posiciona e imprime en consola posicion
			else if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				
				if (floor == stages[0]) 
				{
					Mario->jump(stages[1]);
					floor = stages[1];
				}
				else if (floor == stages[1])
				{
					Mario->jump(stages[2]);
					floor = stages[2];
				}
				else if (floor == stages[2])
				{
					Mario->jump(stages[3]);
					floor = stages[3];
				}
				else if (floor == stages[3])
				{
					Mario->jump(stages[4]);
					floor = stages[4];
				}
				else if (floor == stages[4])
				{
					Mario->jump(stages[5]);
					floor = stages[5];
				}
				else if (floor == stages[5])
				{
					Mario->jump(stages[6]);
					floor = stages[6];
				}

			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				//Mario->testDown();
			}
		default:
			if (Mario->getStatus() == true)
			{
				Mario->stayIdle();
			}
			break;
		}
	}


}

void juego::dibujar() {
	ventana1->clear();
	ventana1->draw(*spriteBackground);
	ventana1->draw(*spriteDoor);
	ventana1->draw(Mario->getMario());
	ventana1->draw(koopa1->getSprite());
	ventana1->draw(koopa2->getSprite());
	ventana1->draw(koopa3->getSprite());
	ventana1->draw(koopa4->getSprite());
	ventana1->draw(*stringTimerText);
	ventana1->display();
}

void juego::dibujarWin()
{
	ventana1->clear();
	ventana1->draw(*spriteBackground);
	ventana1->draw(*spriteDoor);
	ventana1->draw(Mario->getMario());
	ventana1->draw(*stringTimerText);
	ventana1->draw(*stringGameWinText);
	ventana1->display();
}

void juego::dibujarGameOver()
{
	ventana1->clear();
	ventana1->draw(*spriteBackground);
	ventana1->draw(*spriteDoor);
	ventana1->draw(Mario->getMario());
	ventana1->draw(*stringTimerText);
	ventana1->draw(*stringGameOverText);
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

void juego::procesarMusica()
{
	if (!audio->backgroundSoundStatus() && !hurryUp)
	{
		audio->playBackgroundSound();
	}
	else if (!audio->backgroundSoundStatus() && hurryUp)
	{
		audio->playBackgroundSoundFaster();
	}
}
