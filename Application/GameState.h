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

class GameState {
public:
    virtual void handleRequest() = 0;
};


#endif //JUMPER_MENUSTATE_H
