#pragma once
#include <vector>

// #include "PlayerManager.hpp"
#include "GameWindow.hpp"
//#include "Ball.hpp"

enum class GameMode { None, VersusPlayer, VersusAI };

class Pong {
public:
	
	Pong();

	/// <summary>
	/// Game loop
	/// </summary>
	void run();

	void setGameMode(GameMode mode);

private:
	GameWindow *window = nullptr;
	GameMode gameMode;
	//PlayerManager playersManager;
	//Ball ball;

	//Paddle setPlayerPaddle();
	//Paddle setBotPaddle();


	void setScreenCenter(int width, int height);
	//void setGameModeVersusPlayer();
	//void setGameModeVersusAi();
	void update();
	void render(std::vector<sf::RectangleShape* > gameObjects);

};