#pragma once

#include <SFML/Graphics.hpp>

enum class Direction { Up, Down };

class Paddle : public sf::RectangleShape {
public:
	Paddle();
	void move(Direction direction);
protected:
	float speed;
};
