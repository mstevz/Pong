#include <SFML/Graphics.hpp>

#include "Ball.hpp";
#include "GameWindow.hpp";

Ball::Ball() {

	std::srand(time(0));

	// Defines default position to GameWindow screen center
	this->defaultPosition = sf::Vector2f(GameWindow::GET_WIDTH() / 2.f, GameWindow::GET_HEIGHT() / 2.f); 
	
	this->speed = 100.f;
	this->setSize(sf::Vector2f(10.f, 10.f));

	reset(rand());
}

Ball::Ball(float speed) {
	this->speed = speed;
}

void Ball::reset(bool direction) {
	this->movement = sf::Vector2f((direction) ? 1.f : -1.f, rand() % 2 + 1);
	this->setPosition(defaultPosition.x, defaultPosition.y);
}

void Ball::flipYAxis() {
	this->movement.y *= -1.f;
}

void Ball::update() {

	// Constraint ball position to GameWindow Screen
	if (this->getPosition().y <= 0) {
		this->setPosition(getPosition().x, 0.f);
		flipYAxis();
	}
	else if (getPosition().y >= GameWindow::GET_HEIGHT()) {
		this->setPosition(getPosition().x, GameWindow::GET_HEIGHT() - 1.f);
		flipYAxis();
	}
	// ---------------------------------------------

	sf::RectangleShape::move(this->movement.x * speed * GameWindow::GET_DELTA_TIME(), this->movement.y * speed * GameWindow::GET_DELTA_TIME());
}

void Ball::collides(sf::RectangleShape shape) {
	
	if (this->getGlobalBounds().intersects(shape.getGlobalBounds())) {
		this->movement.x *= -1.f;
	}
}