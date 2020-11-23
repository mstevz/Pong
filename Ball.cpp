#include "Ball.hpp";
#include "Pong.hpp";


#include <stdlib.h> 
#include<time.h> 
#include <iostream>

#include <SFML/Graphics.hpp>

Ball::Ball() {

	std::srand(time(0));

	this->speed = 100.f;
	this->movement = sf::Vector2f(rand() % 2 + 1, rand() % 2 + 1);
	this->shape.setSize(sf::Vector2f(10.f, 10.f));
	this->shape.setPosition(0.f, 0.f);

}

Ball::Ball(float speed) {
	this->speed = speed;
}

void Ball::reset(bool direction) {
	this->movement = sf::Vector2f((direction) ? 1.f : -1.f, rand() % 2 + 1);
}

void Ball::flipYAxis() {
	this->movement.y *= -1.f;
}

void Ball::move() {
	//std::cout << this->movement.x << " ; " << this->movement.y << std::endl;

	this->shape.move(this->movement.x * speed * Pong::DELTA_TIME, this->movement.y * speed * Pong::DELTA_TIME);
}

void Ball::collides(sf::RectangleShape shape) {
	
	if (this->shape.getGlobalBounds().intersects(shape.getGlobalBounds())) {
		this->movement.x *= -1.f;
	}
}