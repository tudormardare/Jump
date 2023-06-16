//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include "SettingsState.h"

SettingsState *SettingsState::GetInstance() {
    static SettingsState settingsState;
    return &settingsState;
}

void SettingsState::handleRequest() {
    std::cout<<"Settings \n";
}