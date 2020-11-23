#pragma once

#include <SFML/Graphics.hpp>

enum class Direction { Up, Down };

class Paddle {
public:
	sf::RectangleShape shape;

	Paddle();
	sf::Vector2f getPosition();
	void move(Direction direction);
protected:
	float speed;
};