//
// Created by tudor on 15/06/2023.
//

#include <thread>
#include "JumperApplication.h"
#include "SettingsState.h"


JumperApplication::JumperApplication() {
    gameState = nullptr;
}

void JumperApplication::run(){
    int i = 0;
    while (i < 3) {
        gameState = PauseState::GetInstance();
        gameState->handleRequest();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        gameState = MenuState::GetInstance();
        gameState->handleRequest();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        gameState = PlayingState::GetInstance();
        gameState->handleRequest();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        gameState = SettingsState::GetInstance();
        gameState->handleRequest();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i++;
    }

}
