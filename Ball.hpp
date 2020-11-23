#pragma once

#include <SFML/Graphics.hpp>;


class Ball {
public:

	Ball();
	Ball(float speed);

	void reset(bool direction);
	void move();
	void collides(sf::RectangleShape shape);
	void flipYAxis();
	sf::RectangleShape shape;
private:
	
	sf::Vector2f movement;
	float speed;

};