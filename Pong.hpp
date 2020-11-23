#pragma once
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

#include "PlayerManager.hpp"
#include "Ball.hpp"



enum class GameMode { None, VersusPlayer, VersusAI };

class Pong {
public: 
	sf::RenderWindow* window = nullptr;
	static float DELTA_TIME;

	Pong();

	/// <summary>
	/// Game loop
	/// </summary>
	void run();

	void setGameMode(GameMode mode);

private:
	int windowHeight;
	int windowWidth;
	sf::Vector2f screenCenter;
	GameMode mode;
	PlayerManager playersManager;
	Ball ball;


	Paddle players[2];

	Paddle setPlayerPaddle();
	Paddle setBotPaddle();

	void setGameModeVersusPlayer();
	void setGameModeVersusAi();
	void update();
	void render(std::vector<sf::RectangleShape * > gameObjects);
	
};