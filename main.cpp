#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

#include "Pong.hpp"


void PongRun() {
    Pong game;

    game.setGameMode(GameMode::VersusAI);

    try {
        game.run();
    }
    catch (std::exception e) {
        std::cout << e.what();
    }
}

void Test() {
    sf::Text dt;
    sf::Text fps;
    sf::Font Arial;

    sf::RenderWindow window(sf::VideoMode(800, 480), "Pong");

    if (!Arial.loadFromFile("./assets/fonts/calibri.ttf"))
    {
        throw std::exception("[EXCEPTION] Could not load Arial font!");
    }

    dt.setPosition(10.f, 5.f);
    dt.setCharacterSize(12);
    dt.setFont(Arial);
    dt.setFillColor(sf::Color::White);
    dt.setString("Hello World!");
    sf::Event ev;

    while (window.isOpen()) {
        while (window.pollEvent(ev)) {
            switch (ev.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        window.draw(dt);
        window.display();
    }
}

int main(){   
  
    //Test();

    PongRun();
   
   
    

    return 0;
}