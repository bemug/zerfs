#ifndef __MONSTER__ 
#define __MONSTER__

#include <SFML/Graphics.hpp>

#define MONSTER_WIDTH 100
#define MONSTER_HEIGHT 100

class Hero;

class Monster {
	private:
		int x;
		int y;
		sf::RectangleShape sprite;
		Hero *target;	

	public:
		Monster(int, int);
		void move();
		void draw(sf::RenderWindow*);
};

#endif
