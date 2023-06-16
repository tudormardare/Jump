//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_GAME_H
#define JUMPER_GAME_H

#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"

class PlayingState:public GameState {
public:
    static PlayingState* GetInstance();
    virtual void handleRequest();
};


#endif //JUMPER_GAME_H
