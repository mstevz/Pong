#include "Paddle.hpp"
#include "GameWindow.hpp"

Paddle::Paddle() : sf::RectangleShape(sf::Vector2f(10.f, 100.f)) {
	this->speed = 200.f;
}

void Paddle::move(Direction direction) {
	if (direction == Direction::Up) {
		sf::RectangleShape::move(0.f, -speed * GameWindow::GET_DELTA_TIME()); // * Pong::DELTA_TIME
	}
	else {
		sf::RectangleShape::move(0.f, speed * GameWindow::GET_DELTA_TIME());
	}
}