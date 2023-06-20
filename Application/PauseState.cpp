//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include "PauseState.h"

PauseState &PauseState::GetInstance(sf::RenderWindow &window){
    static PauseState pauseState(window);
    return pauseState;
}

void PauseState::handleEvents(sf::RenderWindow &window){

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void PauseState::update() {

}

void PauseState::render(sf::RenderWindow &window) {
    window.clear();

    for (int i = 0; i < 3; ++i)
    {
        buttons[i]->draw(window);
    }

    window.display();
}

GameState* PauseState::changeState() {
    if (buttons[0]->isClicked(window)){
        return &MenuState::GetInstance(window);
        std::cout << "Passo a Menu" << std::endl;
    }
    return nullptr;
}

