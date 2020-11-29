#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Paddle.hpp"

class NpcPaddle : public Paddle {
public:

	NpcPaddle(const sf::Vector2f * ball);

	void update();
private:
	const sf::Vector2f * ball;

};