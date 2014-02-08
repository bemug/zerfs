#include "hero.hpp"
#include "ball.hpp"

#include <cmath>
#include <iostream>

using namespace std;


Hero::Hero(int x, int y) {
	setX(x);
	setY(y);
	aimX=x;
	aimY=y;
	moving = false;
	sprite = sf::RectangleShape(sf::Vector2f(HERO_WIDTH, HERO_HEIGHT));
	sprite.setFillColor(sf::Color(100, 255, 100));
	ball = new Ball(0,0);
}

float Hero::getX() {
	return x;
}

float Hero::getY() {
	return y;
}

void Hero::setX(float x) {
	this->x = x;
}

void Hero::setY(float y) {
	this->y = y;
}

void Hero::setAimX(int x) {
	aimX = x;
}

void Hero::setAimY(int y) {
	aimY = y;
}

bool Hero::isMoving() {
	return moving;
}

void Hero::prepareMove() {
	/* Check differences between the aim and the current position */
	int diffX = std::abs(x-aimX);
	int diffY = std::abs(y-aimY);
	/* Find the highest, wich speed will be maxed */
	if (diffX > diffY) {
		stepX = 1 * SPEED; //Max speed
		stepY = (float) diffY/diffX * SPEED; //Ratio speed, to catch the point at the same time
	}
	else { //Symetric
		stepX = (float) diffX/diffY * SPEED;
		stepY = 1 * SPEED;
	}
	moving = true;
}

void Hero::trySendBall(int x, int y, Hero **heroes) {
	cout << x << " " << y << endl;
	/* Check if someone is over there */
	for(int i=0; i<NB_PLAYERS; i++) {
		if (i != 0) //This is not me
		{
			/* Collision testing */
			if (heroes[i]->getX() < x
				&& heroes[i]->getX() + HERO_WIDTH > x
				&& heroes[i]->getY() < y
				&& heroes[i]->getY() + HERO_HEIGHT > y) {

				cout << "Collision!" << endl;
			}
				
		}
	}
}

void Hero::move() {

	/* Only perform a move if we're not at the aim point */
	/* This is calculated below */
	if (moving) {
		bool stillMovingX = true;
		bool stillMovingY = true;

		/* Go right if the aim is on the right */
		if (x < aimX) {
			/* We should not step over the aim */
			if (x+stepX > aimX)
				x = aimX; 
			else
				x+=stepX;
		}
		/* Go left */
		else if (x > aimX) {
			if (x-stepX < aimX)
				x = aimX;
			else
				x-=stepX;
		}
		/* We're already at the aim point */
		else {
			stillMovingX = false; // We're not moving in X anymore
		}

		/* Symetric */
		if (y < aimY) {
			if (y+stepY > aimY)
				y = aimY;
			else
				y+=stepY;
		}
		else if (y > aimY) {
			if (y-stepY < aimY)
				y = aimY;
			else
				y-=stepY;
		}
		else {
			stillMovingY = false;
		}

		/* Check if must continue to move or not */
		moving = stillMovingX || stillMovingY;
	}
}

void Hero::draw(sf::RenderWindow *app) {
	/* We maitain position as floats for precision and map them as int for display */
	sprite.setPosition(x,y);
	app->draw(sprite);
}
