//
// Created by tudor on 15/06/2023.
//

#include <thread>
#include "JumperApplication.h"
#include "SettingsState.h"


JumperApplication::JumperApplication() {
    window.create(sf::VideoMode(1080, 720), "Jumper");
    currentState = &MenuState::GetInstance(window);
}

void JumperApplication::run() {

    while (window.isOpen()) {

        // Gestione degli eventi
        handleEvents();

        // Aggiornamento dello stato corrente
        update();

        // Cambio di stato se necessario
        changeState();

        // Disegno dello stato corrente
        render();
    }
}


void JumperApplication::handleEvents() {

    bool isButtonPressed = false; // Nuova variabile per gestire il clic del pulsante

    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left && !isButtonPressed) {
                isButtonPressed = true;
                currentState->handleEvents(window, event); // Gestisci l'evento solo una volta
            }
        } else if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                isButtonPressed = false;
            }
        }
    }
}

void JumperApplication::update() {
    currentState->update();
}

void JumperApplication::render() {
    currentState->render(window);
}

void JumperApplication::changeState() {
    GameState *nextState = currentState->changeState();
    if (nextState != nullptr) {
        currentState = nextState;
    }
}

