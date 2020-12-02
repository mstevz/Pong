#include "Score.hpp"


Score::Score() {
	this->scoreValue = 0;
}

void Score::setTextGui(sf::Text textGui){
	this->text = textGui;
}

sf::Text & Score::getScoreGui() {
	return text;
}
void Score::add(int value){
	this->scoreValue += value;
	this->text.setString(std::to_string(this->scoreValue));
}

unsigned int Score::getScore(){
	return this->scoreValue;
}
