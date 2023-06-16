//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_PAUSEMENU_H
#define JUMPER_PAUSEMENU_H


#include "GameState.h"
#include "MenuState.h"

class PauseState: public GameState{
public:
    static PauseState*  GetInstance();
    virtual void handleRequest();
};


#endif //JUMPER_PAUSEMENU_H
