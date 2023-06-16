//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include "PlayingState.h"

PlayingState *PlayingState::GetInstance() {
    static PlayingState playingState;
    return &playingState;
}


void PlayingState::handleRequest() {
    std::cout<<"Playing\n";
}

