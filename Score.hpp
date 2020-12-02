#pragma once

#include <SFML/Graphics/Text.hpp>

#include "Score.hpp"

class Score {

public:
	Score();
	void setTextGui(const sf::Text textGui);
	sf::Text & getScoreGui();
	void add(int value = 0);
	unsigned int getScore();

private:
	unsigned int scoreValue;
	sf::Text text;

};