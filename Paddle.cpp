#include "Paddle.hpp"
#include "Pong.hpp"

Paddle::Paddle() {
	this->shape = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
	this->shape.setFillColor(sf::Color::White);
	this->speed = 100.f;
}

sf::Vector2f Paddle::getPosition() {
	return this->shape.getPosition();
}

void Paddle::move(Direction direction) {
	
	if (direction == Direction::Up) {
		this->shape.move(0.f, -speed * Pong::DELTA_TIME);
	}
	else {
		this->shape.move(0.f, speed * Pong::DELTA_TIME);
	}
	
}