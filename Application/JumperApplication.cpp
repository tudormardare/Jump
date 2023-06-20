//
// Created by tudor on 15/06/2023.
//

#include <thread>
#include "JumperApplication.h"
#include "SettingsState.h"


JumperApplication::JumperApplication() {
    window.create(sf::VideoMode(800, 600), "Jumper");
    currentState = &MenuState::GetInstance(window);
}

void JumperApplication::run(){
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}

void JumperApplication::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    if(event.type == sf::Event::MouseButtonPressed) {
        currentState->handleEvents(window);
        GameState *nextState = currentState->changeState();
        if (nextState != nullptr) {
            currentState = nextState;
        }
    }
}

void JumperApplication::update() {
    currentState->update();
}

void JumperApplication::render() {
    window.clear();
    currentState->render(window);
    window.display();
}

