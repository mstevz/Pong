#include <SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include <iostream>

#include "Font.hpp";
#include "Pong.hpp"
#include "Ball.hpp"
#include "PlayerPaddle.hpp";
#include "NpcPaddle.hpp"

Pong::Pong() {
   
    this->window = new GameWindow(800, 400);
    this->gameMode = GameMode::None;

    
}

void Pong::setGameMode(GameMode mode) {
    this->gameMode = mode;
}

/// <summary>
/// Executes the game. Game loop.
/// </summary>
void Pong::run() {

    if (this->gameMode == GameMode::None) {
        throw std::exception("[EXCEPTION] Game Mode not set! Please set a game mode.");
    }

    GameWindow* windowPtr; 
    sf::Text fps;
    Ball ball;
    PlayerPaddle pl;
    NpcPaddle npc(&ball.getPosition());

    windowPtr = window; // Exposing window property to lambda

    sf::Font arial = Font::GET("./assets/fonts/arial.ttf");

    fps.setFont(arial);
    fps.setPosition(10.f, 30.f);
    fps.setCharacterSize(12);
    fps.setFillColor(sf::Color::White);
    
    pl.setPosition(20.f, 100.f);
    npc.setPosition((float)(window->GET_WIDTH() - 20), 100.f);
       
    // draw fps Gui Text & sets update for function for each frame
    this->window->setToDraw(&fps, [&fps, &windowPtr](){
        fps.setString("Fps: " + std::to_string(windowPtr->getFramesPerSecond()));
    }); 

    // Draw ball & Settings
    this->window->setToDraw(&ball, [&ball, &pl, &npc]() { 

        if (ball.getPosition().x >= GameWindow::GET_WIDTH()) {
            // set player score
            ball.reset(1);
        }
        else if (ball.getPosition().x <= 0) {
            // set npc score
            ball.reset(0);
        }

        ball.collides(pl);
        ball.collides(npc);
        ball.update(); 

    }); 
    
    
    this->window->setToDraw(&pl,   [&pl]()   { pl.update();  }); // Draw Player Paddle
    this->window->setToDraw(&npc,  [&npc]()  { npc.update(); }); // Draw Npc Paddle

    /* #####################
     * STARTS GAME LOOP HERE 
     * ##################### */

    this->window->render();  // render draws 


    
}