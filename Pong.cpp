#include <SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include <iostream>

#include "Pong.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "PlayerManager.hpp"


float Pong::DELTA_TIME = 0.f;

Pong::Pong() {
    this->windowHeight = 400;
    this->windowWidth = 800;

    this->screenCenter.x = this->windowWidth / 2;
    this->screenCenter.y = this->windowHeight / 2;

    this->mode = GameMode::None;

    this->window = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), "Pong");
}

Paddle Pong::setPlayerPaddle() {
    Paddle player;

    player.shape.setSize(sf::Vector2f(10.f, 100.f));
    player.shape.setPosition(50, this->screenCenter.y - (player.shape.getSize().y / 2));

    return player;
}

Paddle Pong::setBotPaddle() {
    Paddle bot = setPlayerPaddle();

    bot.shape.setPosition(this->windowWidth - 50 - bot.shape.getSize().x, screenCenter.y - (bot.shape.getSize().y / 2));

    return bot;
}

/// <summary>
/// Sets the game mode for Player Versus Player
/// </summary>
void Pong::setGameModeVersusPlayer() {
    this->mode = GameMode::VersusPlayer;

    playersManager.add(setPlayerPaddle());
    playersManager.add(setPlayerPaddle());
}

/// <summary>
/// Sets the game mode for Player Versus AI(CPU)
/// </summary>
void Pong::setGameModeVersusAi() {
    this->mode = GameMode::VersusAI;

    playersManager.add(setPlayerPaddle());
    playersManager.add(setBotPaddle());
}

/// <summary>
/// Defines the game mode the player will play.
/// </summary>
/// <param name="mode"></param>
void Pong::setGameMode(GameMode mode) {
    switch (mode) {
        case GameMode::VersusPlayer:
            setGameModeVersusPlayer();
            break;
        case GameMode::VersusAI:
            setGameModeVersusAi();
            break;
    }
}


/// <summary>
/// Executes the game. Game loop.
/// </summary>
void Pong::run() {

    if (this->mode == GameMode::None) {
        throw std::exception("[EXCEPTION] Game Mode not set! Please set a game mode.");
    }
    
    Paddle* players = playersManager.getPlayers();

    sf::Clock clock;
    sf::Text dt;
    sf::Text fps;
    sf::Font Arial;

    if (!Arial.loadFromFile("./assets/fonts/arial.ttf"))
    {
        throw std::exception("[EXCEPTION] Could not load Arial font!");
    }

    dt.setPosition(10.f, 15.f);
    dt.setCharacterSize(12);
    dt.setFont(Arial);
    dt.setFillColor(sf::Color::White);
    dt.setString("hello world");
  
    fps.setPosition(10.f, 30.f);
    fps.setCharacterSize(12);
    fps.setFont(Arial);
    fps.setFillColor(sf::Color::White);

    this->ball.shape.setPosition(screenCenter.x, screenCenter.y);

    bool debugMode = false;

    while (this->window->isOpen()){
        sf::Event event;
        Pong::DELTA_TIME = clock.restart().asSeconds();

        dt.setString("Delta: " + std::to_string(Pong::DELTA_TIME));
        fps.setString("Fps: " + std::to_string((int)(1 / Pong::DELTA_TIME)));

        // Event handles
        while (this->window->pollEvent(event)) {

            switch (event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            default:
                // handle
                break;
            }
        }

        
        //Player 0 Inputs
        if ((players[0].shape.getPosition().y + players[0].shape.getSize().y > this->windowHeight) ) {
            players[0].shape.setPosition(players[0].shape.getPosition().x, players[0].shape.getPosition().y - (players[0].shape.getPosition().y + players[0].shape.getSize().y - this->windowHeight));
        }
        else if ((players[0].shape.getPosition().y <= 0.f)) {
            players[0].shape.setPosition(players[0].shape.getPosition().x, 0.1f);
        }
        else {
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                players[0].move(Direction::Up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                players[0].move(Direction::Down);
            }
        }

        //Player 1 Inputs
        if ((players[1].shape.getPosition().y + players[1].shape.getSize().y > this->windowHeight)) {
            players[1].shape.setPosition(players[1].shape.getPosition().x, players[1].shape.getPosition().y - (players[1].shape.getPosition().y + players[1].shape.getSize().y - this->windowHeight));
        }
        else if ((players[1].shape.getPosition().y <= 0.f)) {
            players[1].shape.setPosition(players[1].shape.getPosition().x, 0.1f);
        }
        else {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                players[1].move(Direction::Up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                players[1].move(Direction::Down);
            }
        }
       
        // Collisions detections
        ball.collides(players[0].shape);
        ball.collides(players[1].shape);

        ball.move();      
                
        if (ball.shape.getPosition().y <= 0 || ball.shape.getPosition().y + ball.shape.getSize().y >= this->windowHeight){
            ball.flipYAxis();
        }
        else if (ball.shape.getPosition().x > players[1].shape.getPosition().x + players[1].shape.getSize().x) {
            // score player 1
            ball.reset(1);
            this->ball.shape.setPosition(screenCenter.x, screenCenter.y);
        }
        else if (ball.shape.getPosition().x < players[0].shape.getPosition().x - players[0].shape.getSize().x){
            // score player 2
            ball.reset(0);
            this->ball.shape.setPosition(screenCenter.x, screenCenter.y);
        }

        
        this->window->clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            debugMode = !debugMode;
        }
        

        if (debugMode) {
            this->window->draw(dt);
            this->window->draw(fps);
        }

        this->window->draw(ball.shape);

        for (int i = 0; i < playersManager.getSize(); i++) {
            this->window->draw(players[i].shape);
        }
    
        this->window->display();

    }
}