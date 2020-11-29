#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

class GameWindow : protected sf::RenderWindow {
public:
	
	GameWindow();
	GameWindow(int width, int height);

	static unsigned int GET_WIDTH();
	static unsigned int GET_HEIGHT();

	static float GET_DELTA_TIME();

	sf::Vector2f getScreenCenter();

	int getFramesPerSecond();
	
	void setToDraw(sf::Drawable* drawable, std::function<void()> onUpdate = nullptr);
	void render();
	sf::Vector2u getWindowSize(); // exposing parent method

protected:
	std::vector<sf::Drawable*> drawables;
	static unsigned int WIDTH;
	static unsigned int HEIGHT;
	
	void setScreenCenter(int width, int height);
	void setFramesPerSecond();
	void setDeltaTime(sf::Clock* clock);
	void handleWindowEvents();


private:
	int framesPerSecond;
	static float DELTA_TIME;
	
	sf::Vector2f screenCenter;
	sf::Event event;
	std::vector<std::function<void()>> onUpdateCallbacks;
	
	void initializeVariables(unsigned int windowWidth = 800, unsigned int windowHeight = 480);
	void drawObjects(std::vector<sf::Drawable*> components);


};