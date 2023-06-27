//
// Created by tudor on 15/06/2023.
//

#include <thread>
#include "JumperApplication.h"
#include "SettingsState.h"

JumperApplication::JumperApplication() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jumper");
    currentState = &MenuState::GetInstance(window);
    initWindow();
}

void JumperApplication::run() {

    while (window.isOpen()) {

        //inizializzazione finestra

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
    window.clear();
    window.draw(backgroundShape);
    currentState->render(window);
    window.display();
}

void JumperApplication::changeState() {
    GameState *nextState = currentState->changeState();
    if (nextState != nullptr) {
        currentState = nextState;
    }
}

void JumperApplication::initWindow() {
    if(!backgroundTexture.loadFromFile(currentState->getBackgroundPath())){
        std::cout<<"errore";
    }

    backgroundShape.setSize(sf::Vector2f(backgroundTexture.getSize().x, backgroundTexture.getSize().y));
    float scaleX = WINDOW_WIDTH / (float) backgroundTexture.getSize().x;
    float scaleY = WINDOW_HEIGHT / (float) backgroundTexture.getSize().y;

    float scale = std::min(scaleX, scaleY);

    backgroundShape.setTexture(&backgroundTexture);
    backgroundShape.setScale(scale, scale);
}

