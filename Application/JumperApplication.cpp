//
// Created by tudor on 15/06/2023.
//

#include "JumperApplication.h"

JumperApplication::JumperApplication() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jumper", sf::Style::Titlebar);
    currentState = &MenuState::GetInstance(window);
    initWindow();
}

void JumperApplication::run() {

    sf::Clock clock;
    float deltaTime;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        // Gestione degli eventi
        handleEvents();

        // Aggiornamento dello stato corrente
        update(deltaTime);

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
                currentState->handleEvents(window, event);
            }
        } else if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                isButtonPressed = false;
            }
        }

        currentState->handleEvents(window, event);
    }
}

void JumperApplication::update(float deltaTime) {
    currentState->update(window, deltaTime);
}

void JumperApplication::render() {
    window.clear();
    window.draw(backgroundShape);
    currentState->render(window);
    window.display();
}

void JumperApplication::changeState() {
    GameState *nextState = currentState->changeState(window);
    if (nextState != nullptr) {
        currentState = nextState;
        setBackground();
    }
}

void JumperApplication::initWindow() {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int screenWidth = (int) desktopMode.width;
    int screenHeight = (int) desktopMode.height;

    int windowPosX = (screenWidth - WINDOW_WIDTH) / 2;
    int windowPosY = (screenHeight - WINDOW_HEIGHT) / 2;

    window.setPosition(sf::Vector2i(windowPosX, windowPosY));
    setBackground();
}

void JumperApplication::setBackground() {
    backgroundTexture.loadFromFile(currentState->getBackgroundPath());
    backgroundShape.setSize(sf::Vector2f((float) backgroundTexture.getSize().x, (float) backgroundTexture.getSize().y));
    float scaleX = WINDOW_WIDTH / (float) backgroundTexture.getSize().x;
    float scaleY = WINDOW_HEIGHT / (float) backgroundTexture.getSize().y;

    float scale = std::min(scaleX, scaleY);
    backgroundShape.setTexture(&backgroundTexture);
    backgroundShape.setScale(scale, scale);
}

