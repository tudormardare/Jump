//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include "MenuState.h"

MenuState *MenuState::GetInstance() {
    static MenuState menuState;
    return &menuState;
}

void MenuState::handleRequest() {
    std::cout<<"Menu \n";
}


