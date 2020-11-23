#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

GameObject::GameObject(sf::RenderWindow * gameWindow) {
	this->gameWindow = gameWindow;
}

void GameObject::Render() {
	this->gameWindow->draw(this->shape);
}