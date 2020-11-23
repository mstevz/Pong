#pragma once

#include "Paddle.hpp"

class PlayerManager {
public:

	PlayerManager();
	
	bool add(Paddle player);

	Paddle* getPlayers();
	int getSize();
private:
	Paddle players[2];
	int count; 
	const int MAX_PLAYERS = 2;
	
	
};