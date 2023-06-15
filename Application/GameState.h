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

struct GameState {
    virtual GameState* handleEvent(const sf::Event&) = 0;
    virtual void update(sf::Time) = 0;
    virtual void render() = 0;
    virtual ~GameState() = default;
};


#endif //JUMPER_MENUSTATE_H
