//
// Created by tudor on 15/06/2023.
//

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Graphics.hpp"
#include "MenuState.h"
#include "GamingState.h"

MenuState &MenuState::GetInstance(sf::RenderWindow &window) {
    static MenuState instance(window);
    return instance;
}

void MenuState::handleEvents(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (auto &button : buttons) {
                if (button->isClicked(window)) {
                    button->update(window);
                    changeStateToNext = true; // Imposta il flag per il cambio di stato
                    break; // Esci dal ciclo dopo il primo bottone cliccato
                }
            }
        }
    }
}

void MenuState::update(sf::RenderWindow &window, float deltaTime) {
    for (auto &button : buttons) {
        button->update(window);
    }
}

void MenuState::render(sf::RenderWindow &window) {
    for (auto &button : buttons) {
        button->draw(window);
    }
    gameTimer.displayBestTime(window);
}

GameState *MenuState::changeState(sf::RenderWindow &window) {
    if (changeStateToNext) {
        changeStateToNext = false;
        if (buttons[0]->isClicked(window)) {
            return &SettingsState::GetInstance(window);
        } else if (buttons[1]->isClicked(window)) {
            return &GamingState::GetInstance(window);
        } else if (buttons[2]->isClicked(window)) {
            window.close();
        }
    }
    return nullptr;
}

void MenuState::initState() {
    // Texture per i pulsanti
    sf::Texture settingsButtonTexture, playButtonTexture, exitButtonTexture;

    if (!settingsButtonTexture.loadFromFile(MENU_SETTINGS_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della texture del pulsante SETTINGS." << std::endl;
    }
    if (!playButtonTexture.loadFromFile(MENU_PLAY_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della texture del pulsante PLAY." << std::endl;
    }
    if (!exitButtonTexture.loadFromFile(MENU_EXIT_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della texture del pulsante EXIT." << std::endl;
    }

    sf::Vector2f size(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
    float totalHeight = (MENU_BUTTONS_NUMBER * MENU_BUTTON_HEIGHT) + (MENU_BUTTON_DISTANCE * (MENU_BUTTONS_NUMBER - 1));
    sf::Vector2f startingPosition((WINDOW_WIDTH) / (float) 2, (WINDOW_HEIGHT - totalHeight) / (float) 2);

    // Inizializzazione dei bottoni con texture diverse
    buttons[0] = std::make_unique<MenuButton>(size, startingPosition, settingsButtonTexture);
    buttons[1] = std::make_unique<MenuButton>(size, startingPosition + sf::Vector2f(0, MENU_BUTTON_HEIGHT + MENU_BUTTON_DISTANCE), playButtonTexture);
    buttons[2] = std::make_unique<MenuButton>(size, startingPosition + sf::Vector2f(0, 2 * (MENU_BUTTON_HEIGHT + MENU_BUTTON_DISTANCE)), exitButtonTexture);
}

std::string MenuState::getBackgroundPath() const {
    return backgroundPath;
}

MenuState::MenuState(sf::RenderWindow &window) {
    initState();
}




