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
#include <thread>
#include "GamingState.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "SettingsState.h"
#include "GameState.h"
#include "PauseState.h"
#include "MenuState.h"
#include "../Utilities/constants.h"

class JumperApplication {

public:
    JumperApplication();
    void run();

private:

    GameState* currentState;
    sf::RenderWindow window;
    sf::RectangleShape backgroundShape;
    sf::Texture backgroundTexture;

    void handleEvents();
    void update(float deltaTime);
    void render();
    void changeState();
    void initWindow();
    void setBackground();


};


#endif //JUMPER_JUMPERAPPLICATION_H
