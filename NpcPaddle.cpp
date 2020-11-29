#include "NpcPaddle.hpp"

NpcPaddle::NpcPaddle(const sf::Vector2f * ball) {
	this->ball = ball;
}

void NpcPaddle::update() {

	if (ball->y < this->getPosition().y) {
		move(Direction::Up);
	}
	else {
		move(Direction::Down);
	}

}