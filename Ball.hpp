#pragma once

#include <SFML/Graphics.hpp>;

class Ball : public sf::RectangleShape {
public:

	Ball();
	Ball(float speed);

	void reset(bool direction);
	void update();
	void collides(sf::RectangleShape shape);
	void flipYAxis();
protected:
	sf::Vector2f defaultPosition;
private:
	sf::Vector2f movement;
	float speed;

};