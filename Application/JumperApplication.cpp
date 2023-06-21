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

void JumperApplication::run() {
    bool isButtonPressed = false; // Nuova variabile per gestire il clic del pulsante

    while (window.isOpen()) {

        // Gestione degli eventi
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

        // Aggiornamento dello stato corrente
        currentState->update();

        // Cambio di stato se necessario
        GameState *nextState = currentState->changeState();
        if (nextState != nullptr) {
            currentState = nextState;
        }

        // Disegno dello stato corrente
        currentState->render(window);
    }
}


void JumperApplication::handleEvents() {
    sf::Event event{};
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
    }
    /*if(event.type == sf::Event::MouseButtonPressed) {
        currentState->handleEvents(window);
        GameState *nextState = currentState->changeState();
        if (nextState != nullptr) {
            currentState = nextState;
        }
    }*/
}

void JumperApplication::update() {
    currentState->update();
}

void JumperApplication::render() {
    window.clear();
    currentState->render(window);
    window.display();
}

