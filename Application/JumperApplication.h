//
// Created by tudor on 15/06/2023.
//
/*
 * Classe che si occupa di gestire l'applicazione in se per se,
 * compres di menù e gioco
 */

#ifndef JUMPER_JUMPERAPPLICATION_H
#define JUMPER_JUMPERAPPLICATION_H

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "PlayingState.h"
#include "GameState.h"
#include "PauseState.h"
#include "MenuState.h"

class JumperApplication {

public:
    JumperApplication();
    void run();

private:

    GameState* currentState;
    sf::RenderWindow window;
    void handleEvents();
    void update();
    void render();
    void changeState();


};


#endif //JUMPER_JUMPERAPPLICATION_H
