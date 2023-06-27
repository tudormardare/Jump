//
// Created by tudor on 15/06/2023.
//
/*
 * Classe che si occupa di gestire l'applicazione in se per se,
 * compres di menù e gioco
 */

#ifndef JUMPER_JUMPERAPPLICATION_H
#define JUMPER_JUMPERAPPLICATION_H

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 675

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

    GameState *currentState;
    sf::RenderWindow window;
    sf::RectangleShape backgroundShape;
    sf::Texture backgroundTexture;

    void handleEvents();

    void update();

    void render();

    void changeState();

    void initWindow();


};


#endif //JUMPER_JUMPERAPPLICATION_H
