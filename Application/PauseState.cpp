//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include "PauseState.h"

PauseState *PauseState::GetInstance() {
    static PauseState pauseState;
    return &pauseState;
}

void PauseState::handleRequest() {
    std::cout<<"Pause \n";
}


