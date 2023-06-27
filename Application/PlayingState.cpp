//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include "PlayingState.h"


PlayingState &PlayingState::GetInstance(sf::RenderWindow &window) {
    static PlayingState instance(window);
    return instance;
}

void PlayingState::handleEvents(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::Closed){
        window.close();
    }
    else if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
            for (auto & button : buttons){
                if (button->isClicked(window)){
                    button->update(window);
                    changeStateToNext = true; // Imposta il flag per il cambio di stato
                    break; // Esci dal ciclo dopo il primo bottone cliccato
                }
            }
        }
    }
}

void PlayingState::update() {
    for (auto & button : buttons){
        button->update(window);
    }
}

void PlayingState::render(sf::RenderWindow &window) {
    for (auto & button : buttons){
        button->draw(window);
    }
}

GameState *PlayingState::changeState() {
    if(changeStateToNext) {
        changeStateToNext = false;
        if (buttons[0]->isClicked(window)) {
            return &PauseState::GetInstance(window);
        }
        else if(buttons[1]->isClicked(window)){
            return &MenuState::GetInstance(window);
        }
        else if(buttons[3]->isClicked(window)){
            window.close();
        }
    }
    return nullptr;
}

std::string PlayingState::getBackgroundPath() const {
    return backgroundPath;
}
