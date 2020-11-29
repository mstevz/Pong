#include "PlayerPaddle.hpp"

void PlayerPaddle::update() {
    if ((getPosition().y + getSize().y > GameWindow::GET_HEIGHT())) {
        setPosition(getPosition().x, getPosition().y - (getPosition().y + getSize().y - GameWindow::GET_HEIGHT()));
    }
    else if ((getPosition().y <= 0.f)) {
        setPosition(getPosition().x, 0.1f);
    }
    else {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            move(Direction::Up);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            move(Direction::Down);
        }
    }
}