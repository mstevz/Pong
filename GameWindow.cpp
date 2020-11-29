#include "GameWindow.hpp"

unsigned int GameWindow::WIDTH = 0;
unsigned int GameWindow::HEIGHT = 0;

float GameWindow::DELTA_TIME = 0.f;

GameWindow::GameWindow() { 
	initializeVariables();
}

GameWindow::GameWindow(int width, int height) : sf::RenderWindow(sf::VideoMode(width, height), "Pong") {
	initializeVariables((unsigned int)width, (unsigned int)height);
}
unsigned int GameWindow::GET_WIDTH() {
	return GameWindow::WIDTH;
}

unsigned int GameWindow::GET_HEIGHT() {
	return GameWindow::HEIGHT;
}

float GameWindow::GET_DELTA_TIME() {
	return GameWindow::DELTA_TIME;
}

void GameWindow::initializeVariables(unsigned int windowWidth, unsigned int windowHeight) {
	this->framesPerSecond = 0;
	this->DELTA_TIME = 0.f;
	
	GameWindow::WIDTH = windowWidth;
	GameWindow::HEIGHT = windowHeight;

	this->setScreenCenter(GameWindow::WIDTH, GameWindow::HEIGHT);
}

void GameWindow::setScreenCenter(int width, int height) {
	this->screenCenter.x = width / 2;
	this->screenCenter.y = height / 2;
}

void GameWindow::setToDraw(sf::Drawable* drawable, std::function<void()> onUpdate) {
	this->drawables.push_back(drawable);
	
	if (onUpdate != nullptr) {
		this->onUpdateCallbacks.push_back(onUpdate);
	}
}

void GameWindow::setDeltaTime(sf::Clock* clock) {
	this->DELTA_TIME = clock->restart().asSeconds();
}

void GameWindow::setFramesPerSecond() {
	this->framesPerSecond = (int)(1.f / DELTA_TIME);
}

int GameWindow::getFramesPerSecond() {
	return framesPerSecond;
}

sf::Vector2u GameWindow::getWindowSize() {
	return this->getSize();
}


sf::Vector2f GameWindow::getScreenCenter() {
	return this->screenCenter;
}

void GameWindow::handleWindowEvents() {
	while (this->pollEvent(this->event)) {
		switch (this->event.type) {
			case sf::Event::Closed:
				this->close();
				break;
			default:
				// unhandled
				break;
		}
	}
}

void GameWindow::drawObjects(std::vector<sf::Drawable*> components) {
	for (auto graphic : components) {
		this->draw(*graphic);
	}
}

void GameWindow::render() {

	sf::Clock clock;

	while (this->isOpen()) {
		
		this->handleWindowEvents();

		this->setDeltaTime(&clock);
		this->setFramesPerSecond();

		this->clear();
		this->drawObjects(this->drawables);

		// Calls the onUpdate function each drawable set has defined.
		for (auto updateDrawables : onUpdateCallbacks) {
			updateDrawables();
		}
		
		this->display();
	}	
}