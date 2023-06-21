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

void MenuState::handleEvents(sf::RenderWindow& window,const sf::Event& event){
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


void MenuState::update() {
    for (auto & button : buttons){
        button->update(window);
    }
}

void MenuState::render(sf::RenderWindow &window) {
    window.clear();
    for (auto & button : buttons){
        button->draw(window);
    }

    window.display();
}

GameState* MenuState::changeState() {
    if(changeStateToNext) {
        changeStateToNext = false;
        if (buttons[0]->isClicked(window)) {
            return &PauseState::GetInstance(window);
        }
        else if(buttons[1]->isClicked(window)){
            return &PlayingState::GetInstance(window);
        }
        else if(buttons[2]->isClicked(window)){
            window.close();
        }
    }
    return nullptr;
}

void MenuState::initButtons() {
    if (!buttonTexture.loadFromFile(MENU_BUTTONS_PATH)){
        std::cout << "Errore durante il caricamento della texture del pulsante." << std::endl;
    }
    sf::Vector2f size(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    sf::Vector2f startingPosition(WINDOW_WIDTH -/ (float) 2, (WINDOW_HEIGHT/(float) 2));


    //Inizializzazione dei bottoni
    for(int i = 0; i < MENU_BUTTONS_NUMBER; i++){
        buttons[i] = std::make_unique<MenuButton>(size, startingPosition + sf::Vector2f(0, i * MENU_BUTTON_DISTANCE), buttonTexture);
    }
}




