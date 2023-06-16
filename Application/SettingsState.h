//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_SETTINGSMENU_H
#define JUMPER_SETTINGSMENU_H


#include "GameState.h"

class SettingsState:public GameState{
public:
    static SettingsState* GetInstance();
    virtual void handleRequest();
};


#endif //JUMPER_SETTINGSMENU_H
