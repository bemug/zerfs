#include "monster.hpp"

Monster::Monster(int x, int y) {
	this->x = x;
	this->y = y;
	sprite = sf::RectangleShape(sf::Vector2f(MONSTER_WIDTH, MONSTER_HEIGHT));
	sprite.setFillColor(sf::Color(255, 0, 0));
}

void Monster::draw(sf::RenderWindow *app) {
	/* We maitain position as floats for precision and map them as int for display */
	sprite.setPosition(x,y);
	app->draw(sprite);
}
