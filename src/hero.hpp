#ifndef __HERO__
#define __HERO__

#include <SFML/Graphics.hpp>
#define HERO_WIDTH 30
#define HERO_HEIGHT 30
#define SPEED 10
#define NB_PLAYERS 2

class Ball;

class Hero {
	private:
		float x;
		float y;
		int aimX;
		int aimY;
		float stepX;
		float stepY;
		bool moving;
		sf::RectangleShape sprite;
		Ball *ball;

	public:
		Hero(int, int);

		float getX();
		float getY();
		void setX(float);
		void setY(float);
		void setAimX(int);
		void setAimY(int);
		bool isMoving();
		void setBall(Ball*);

		void prepareMove();
		bool hasBall();
		void trySendBall(int, int, Hero**);
		void move();
		void draw(sf::RenderWindow*);
};

#endif
