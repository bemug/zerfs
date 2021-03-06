#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "hero.hpp"
#include "ball.hpp"
#include "monster.hpp"

using namespace std;


int main(int argc, char* argv[]) {

	/* Display the app version provided by cmake */
	cout << "Version " << VERSION_MAJOR << "." << VERSION_MINOR << endl;

	/* Initializing the game */
	Hero *heroes[NB_PLAYERS];
	heroes[0] = new Hero(100,100);
	heroes[1] = new Hero(200,200);
	Ball *ball = new Ball(300,300);
	heroes[0]->setBall(ball);
	Monster *monster = new Monster(250,250);

	sf::RenderWindow app(sf::VideoMode(800, 600), "Zerfs");
	app.setFramerateLimit(60);

	while (app.isOpen()) {

		/* Process events */
		sf::Event event;
		while (app.pollEvent(event)) {
			switch (event.type) {
				/* Window close */
				case sf::Event::Closed:
					app.close();
					break;
					/* Keyboard input */
				case sf::Event::KeyPressed:
					cout << "Key pressed" << endl;
					break;
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Right) {
						cout << "Right click!" << endl;
						heroes[0]->setAimX(event.mouseButton.x - HERO_WIDTH/2);
						heroes[0]->setAimY(event.mouseButton.y - HERO_HEIGHT/2);
						heroes[0]->prepareMove();
					}
					if (event.mouseButton.button == sf::Mouse::Left) {
						cout << "Left click!" << endl;
						heroes[0]->trySendBall(event.mouseButton.x, event.mouseButton.y, heroes);
					}
					break;
				default:
					break;	
			}		
		}

		/* Compute */
		heroes[0]->move();
		heroes[1]->move();


		/* Render */
		app.clear();
		heroes[0]->draw(&app);
		heroes[1]->draw(&app);
		monster->draw(&app);
		app.display();
	}
}		
