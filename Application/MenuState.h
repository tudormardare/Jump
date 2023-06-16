//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_MAINMENU_H
#define JUMPER_MAINMENU_H


#include "GameState.h"
#include "PauseState.h"
#include "PlayingState.h"

class MenuState: public GameState{
public:
    static MenuState* GetInstance();
    virtual void handleRequest();
};


#endif //JUMPER_MAINMENU_H
