#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

#include "Pong.hpp"

int main(){   
    Pong game;

    game.setGameMode(GameMode::VersusAI);

    try {
        game.run();
    }
    catch (std::exception e) {
        std::cout << e.what();
    }

    return 0;
}



