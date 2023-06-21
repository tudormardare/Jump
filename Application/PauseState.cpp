//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include "PauseState.h"

PauseState &PauseState::GetInstance(sf::RenderWindow &window){
    static PauseState pauseState(window);
    return pauseState;
}

void PauseState::handleEvents(sf::RenderWindow &window, const sf::Event& event){
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

void PauseState::update() {

}

void PauseState::render(sf::RenderWindow &window) {
    window.clear();
    for (auto & button : buttons){
        button->draw(window);
    }

    window.display();
}

GameState* PauseState::changeState() {
    if(changeStateToNext) {
        if (buttons[0]->isClicked(window)) {
            std::cout << "Passo a Menu" << std::endl;
            changeStateToNext = false;
            return &MenuState::GetInstance(window);
        }
    }
    return nullptr;
}


