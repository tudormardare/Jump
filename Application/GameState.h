//
// Created by tudor on 15/06/2023.
//
/*
 * Classe che rappresenta i vari stati del gioco, ovvero
 * in gioco, non in gioco ecc
 */

#ifndef JUMPER_MENUSTATE_H
#define JUMPER_MENUSTATE_H


#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameState {
public:
    virtual void handleEvents(sf::RenderWindow& window,const sf::Event& event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual GameState* changeState() = 0;
    virtual ~GameState() = default;
};


#endif //JUMPER_MENUSTATE_H
