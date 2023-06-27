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
    if (event.type == sf::Event::Closed) {
        window.close();
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (auto &button: buttons) {
                if (button->isClicked(window)) {
                    button->update(window);
                    changeStateToNext = true; // Imposta il flag per il cambio di stato
                    break; // Esci dal ciclo dopo il primo bottone cliccato
                }
            }
        }
    }
}

void PlayingState::update() {
    for (auto &button: buttons) {
        button->update(window);
    }
}

void PlayingState::render(sf::RenderWindow &window) {
    for (auto &button: buttons) {
        button->draw(window);
    }
}

GameState *PlayingState::changeState() {
    if (changeStateToNext) {
        changeStateToNext = false;
        if (buttons[0]->isClicked(window)) {
            return &PauseState::GetInstance(window);
        } else if (buttons[1]->isClicked(window)) {
            return &MenuState::GetInstance(window);
        } else if (buttons[3]->isClicked(window)) {
            window.close();
        }
    }
    return nullptr;
}

std::string PlayingState::getBackgroundPath() const {
    return backgroundPath;
}

void PlayingState::initButtons() {
    if (!buttonTexture.loadFromFile(PLAYING_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della backgroundTexture del pulsante." << std::endl;
    }
    sf::Vector2f size(PLAYING_BUTTON_WIDTH, PLAYING_BUTTON_HEIGHT);
    float totalHeight =
            (PLAYING_BUTTON_NUMBER * PLAYING_BUTTON_HEIGHT) + (PLAYING_BUTTON_DISTANCE * (PLAYING_BUTTON_NUMBER - 1));
    sf::Vector2f startingPosition((WINDOW_WIDTH) / (float) 2, (WINDOW_HEIGHT - totalHeight) / (float) 2);

    float i = 0;
    //Inizializzazione dei bottoni
    for (auto &button: buttons) {
        button = std::make_unique<MenuButton>(size, startingPosition + sf::Vector2f(0, PLAYING_BUTTON_HEIGHT +
                                                                                       PLAYING_BUTTON_DISTANCE * i),
                                              buttonTexture);
        i++;
    }
}
