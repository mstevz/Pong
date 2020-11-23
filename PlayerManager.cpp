#include "PlayerManager.hpp"



PlayerManager::PlayerManager() {
	this->count = 0;
}

bool PlayerManager::add(Paddle player) {
	bool result = false;

	if (this->count < this->MAX_PLAYERS) {
		this->players[count] = player;
		this->count++;
		result = true;
	}
	
	return result;
}

Paddle* PlayerManager::getPlayers() {
	return players;
}

int PlayerManager::getSize() {
	return count;
}