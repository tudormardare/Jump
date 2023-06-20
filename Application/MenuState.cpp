//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Graphics.hpp"
#include "MenuState.h"

MenuState &MenuState::GetInstance(sf::RenderWindow &window){
    static MenuState instance(window);
    return instance;
}

void MenuState::handleEvents(sf::RenderWindow &window){

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void MenuState::update() {
    for (int i = 0; i < 3; ++i)
    {
        buttons[i]->update(window);
    }
}

void MenuState::render(sf::RenderWindow &window) {
    window.clear();

    for (auto & button : buttons)
    {
        button->draw(window);
    }

    window.display();
}

GameState* MenuState::changeState() {
    if (buttons[0]->isClicked(window)){
        return &PauseState::GetInstance(window);
        std::cout << "Passo a Pausa" << std::endl;
    }
    return nullptr;
}




