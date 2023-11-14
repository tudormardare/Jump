//
// Created by tudor on 15/06/2023.
//

#define FRAME_DURATION 0.016f

#include <valarray>
#include <iostream>
#include "GamingState.h"

GamingState &GamingState::GetInstance(sf::RenderWindow &window) {
    static GamingState instance(window);
    return instance;
}

void GamingState::handleEvents(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        window.close();
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) {
            player.setTexture(textureManager.getTexture("Player", "Idle", 0));
        }
    }
}

void GamingState::render(sf::RenderWindow &window) {
    player.draw(window);
}

GameState *GamingState::changeState(sf::RenderWindow &window) {

    return nullptr;
}

std::string GamingState::getBackgroundPath() const {
    return GAME_BACKGROUND_PATH;
}

void GamingState::initState() {
    setTextureForPlayer();
}


void GamingState::handlePlayerMovements(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isKeyPressedW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);

    handlePlayerHorizontalMovement(isKeyPressedA, isKeyPressedD, deltaTime);

    if (isKeyPressedW && !player.isJumping()) {
        player.jump(player.getVelocity().x);
    }

    // Applica la gravità al giocatore
    PhysicsSystem::applyGravity(player, deltaTime);

    // Aggiorna la posizione del giocatore
    player.update(deltaTime);

    handleCollisions();

}

void GamingState::handlePlayerAnimations(float deltaTime, const std::string &animationType, int frameCount) {
    float animationLength = 0.f;

    if (animationType == "Idle") {
        animationLength = 0.5f;
    } else if (animationType == "Running") {
        animationLength = 0.9f;
    }

    float frameDuration = animationLength / (float) frameCount;

    // Aggiornamento dell'animazione
    animationTimer += deltaTime;

    if (animationTimer >= frameDuration) {
        animationTimer -= frameDuration; // Più preciso che azzerarlo
        currentFrame = (currentFrame + 1) % frameCount;
        player.setTexture(textureManager.getTexture("Player", animationType, currentFrame));
    }
}


void GamingState::update(sf::RenderWindow &window, float deltaTime) {
    handlePlayerMovements(deltaTime);
    handleAnimations(deltaTime);
}


void GamingState::handlePlayerHorizontalMovement(bool isKeyPressedA, bool isKeyPressedD, float deltaTime) {
    int movementDirection = (isKeyPressedA ? -1 : 0) + (isKeyPressedD ? 1 : 0);

    if (movementDirection != 0) {
        if (player.getInverse() != (movementDirection < 0)) {
            player.inverse();
        }
        adjustAccelerationForDirectionChange((float) movementDirection * PLAYER_ACCELERATION_RATE, deltaTime);
    } else {
        deceleratePlayer(deltaTime);
    }

    sf::Vector2f currentVelocity = player.getVelocity();
    currentVelocity.x += player.getAcceleration().x * deltaTime;
    clampPlayerVelocity(currentVelocity);
    player.setVelocity(currentVelocity);
}



// TODO: Rivedere questa funzione

void GamingState::adjustAccelerationForDirectionChange(float accelerationRate, float deltaTime) {
    float direction = (accelerationRate > 0) ? 1.0f : -1.0f;
    if (direction * player.getVelocity().x < 0) { // Cambio di direzione
        deceleratePlayer(deltaTime); // Prima decelera
        if (player.getVelocity().x == 0) {
            player.setAccelerationX(accelerationRate); // Poi inizia ad accelerare nella nuova direzione
        }
    } else {
        player.setAccelerationX(accelerationRate); // Accelerazione normale
    }
}


bool GamingState::deceleratePlayer(float deltaTime) {
    const float Threshold = 0.1f; // Velocità sotto la quale il giocatore si ferma
    float deceleration = (player.getVelocity().x > 0) ? -PLAYER_DECELERATION_RATE : PLAYER_DECELERATION_RATE;
    player.setAccelerationX(deceleration);

    // Se la velocità è minore di un certo valore, il giocatore si ferma
    if (std::abs(player.getVelocity().x) < Threshold) {
        player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
        player.setAccelerationX(0.f);
        return true; // Il giocatore si è fermato
    }
    return false; // Il giocatore è ancora in movimento
}


void GamingState::clampPlayerVelocity(sf::Vector2f &velocity) {
    velocity.x = std::clamp(velocity.x, -PLAYER_MAX_SPEED, PLAYER_MAX_SPEED);
}

void GamingState::handleCollisions() {
    if (player.getPosition().y > 500) {
        player.setPosition(player.getPosition().x, 500);
        player.setVerticalVelocity(0.0f);
    }
}

void GamingState::handleAnimations(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isKeyPressedW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);


    if (isKeyPressedW) {
        handlePlayerAnimations(deltaTime, "Jumping", PLAYER_JUMPING_TEXTURES);
    } else if (isKeyPressedA || isKeyPressedD) {
        handlePlayerAnimations(deltaTime, "Running", PLAYER_RUNNING_TEXTURES);
    } else {
        handlePlayerAnimations(deltaTime, "Idle", PLAYER_IDLE_TEXTURES);
    }
}

void GamingState::setTextureForPlayer() {

    std::map<std::string, std::pair<std::string, int>> playerAnimations = {
            {"Running", {PLAYER_RUNNING_PATH, PLAYER_RUNNING_TEXTURES}},
            {"Jumping", {PLAYER_JUMPING_PATH, PLAYER_JUMPING_TEXTURES}},
            {"Idle",    {PLAYER_IDLE_PATH,    PLAYER_IDLE_TEXTURES}},
            {"Falling", {PLAYER_FALLING_PATH, PLAYER_FALLING_TEXTURES}}
    };
    textureManager.loadEntityTextures("Player", playerAnimations);
    player.setTexture(textureManager.getTexture("Player", "Idle", 0));
    player.setPosition(sf::Vector2f(100, 100));
}



