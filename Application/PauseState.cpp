//
// Created by tudor on 15/06/2023.
//
#include "PauseState.h"

PauseState &PauseState::GetInstance(sf::RenderWindow &window) {
    static PauseState pauseState(window);
    return pauseState;
}

void PauseState::handleEvents(sf::RenderWindow &window, const sf::Event &event) {
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

void PauseState::update(sf::RenderWindow &window, float deltaTime) {

}

void PauseState::render(sf::RenderWindow &window) {
    for (auto &button: buttons) {
        button->draw(window);
    }
}

GameState *PauseState::changeState(sf::RenderWindow &window) {
    if (changeStateToNext) {
        if (buttons[0]->isClicked(window)) {
            changeStateToNext = false;
            return &SettingsState::GetInstance(window);
        } else if (buttons[1]->isClicked(window)) {
            window.close();
        }
    }
    return nullptr;
}

std::string PauseState::getBackgroundPath() const {
    return backgroundPath;
}

void PauseState::initState() {
    if (!buttonTexture.loadFromFile(PAUSE_BUTTONS_PATH)) {
        std::cout << "Errore durante il caricamento della backgroundTexture del pulsante." << std::endl;
    }
    sf::Vector2f size(PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT);
    float totalHeight =
            (PAUSE_BUTTONS_NUMBER * PAUSE_BUTTON_HEIGHT) + (PAUSE_BUTTON_DISTANCE * (PAUSE_BUTTONS_NUMBER - 1));
    sf::Vector2f startingPosition((WINDOW_WIDTH) / (float) 2, (WINDOW_HEIGHT - totalHeight) / (float) 2);

    float i = 0;
    //Inizializzazione dei bottoni
    for (auto &button: buttons) {
        button = std::make_unique<MenuButton>(size, startingPosition +
                                                    sf::Vector2f(0, PAUSE_BUTTON_HEIGHT + PAUSE_BUTTON_DISTANCE * i),
                                              buttonTexture);
        i++;
    }

}


