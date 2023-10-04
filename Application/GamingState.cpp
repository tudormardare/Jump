//
// Created by tudor on 15/06/2023.
//

#define FRAME_DURATION 0.15f

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
            player.setDefaultTexture();
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
    player.setPosition(sf::Vector2f(100, 100));
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

void GamingState::handlePlayerAnimations(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isKeyPressedW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);

    if (isKeyPressedW) {
        jumpingAnimation(deltaTime);
    } else if (isKeyPressedA || isKeyPressedD) {
        runningAnimation(deltaTime);
    } else {
        idleAnimation(deltaTime);
    }
}

void GamingState::update(sf::RenderWindow &window, float deltaTime) {
    handlePlayerMovements(deltaTime);
    handlePlayerAnimations(deltaTime);
    // ... Altri aggiornamenti specifici dello stato
}


void GamingState::runningAnimation(float deltaTime) {
    animationTimer += deltaTime;
    if (animationTimer >= FRAME_DURATION) {
        animationTimer = 0.f;
        currentFrame = (currentFrame + 1) % PLAYER_RUNNING_TEXTURES;
        player.changeRunningTexture(currentFrame);
    }
}

void GamingState::jumpingAnimation(float deltaTime) {
    animationTimer += deltaTime;
    if (animationTimer >= FRAME_DURATION) {
        animationTimer = 0.f;
        currentFrame = (currentFrame + 1) % PLAYER_JUMPING_TEXTURES;
        player.changeJumpingTexture(currentFrame);
    }
}

void GamingState::idleAnimation(float deltaTime) {
    animationTimer += deltaTime;
    if (animationTimer >= FRAME_DURATION) {
        animationTimer = 0.f;
        currentFrame = (currentFrame + 1) % PLAYER_IDLE_TEXTURES;
        player.changeIdleTexture(currentFrame);
    }
}

void GamingState::fallingAnimation(float deltaTime) {
    animationTimer += deltaTime;
    if (animationTimer >= FRAME_DURATION) {
        animationTimer = 0.f;
        currentFrame = (currentFrame + 1) % PLAYER_FALLING_TEXTURES;
        player.changeFallingTexture(currentFrame);
    }
}

void GamingState::handlePlayerHorizontalMovement(bool isKeyPressedA, bool isKeyPressedD, float deltaTime) {
    if (isKeyPressedA && !isKeyPressedD) {
        if (!player.getInverse()) {
            player.inverse();
        }
        adjustAccelerationForDirectionChange(PLAYER_ACCELERATION_RATE, PLAYER_CHANGE_DIRECTION_SPEED, deltaTime, true);
    } else if (isKeyPressedD && !isKeyPressedA) {
        if (player.getInverse()) {
            player.inverse();
        }
        adjustAccelerationForDirectionChange(-PLAYER_ACCELERATION_RATE, PLAYER_CHANGE_DIRECTION_SPEED, deltaTime,
                                             false);
    } else {
        deceleratePlayer(deltaTime);
    }

    sf::Vector2f currentVelocity = player.getVelocity();
    currentVelocity.x += player.getAcceleration().x * deltaTime;
    clampPlayerVelocity(currentVelocity);

    player.setVelocity(currentVelocity);
    player.move(currentVelocity.x * deltaTime, currentVelocity.y * deltaTime);
}

void
GamingState::adjustAccelerationForDirectionChange(float accelerationRate, float changeDirectionSpeed, float deltaTime,
                                                  bool isMovingLeft) {
    if ((isMovingLeft && player.getVelocity().x > 0) || (!isMovingLeft && player.getVelocity().x < 0)) {
        player.setAccelerationX(-changeDirectionSpeed * accelerationRate);
    } else {
        player.setAccelerationX(accelerationRate);
    }
}

void GamingState::deceleratePlayer(float deltaTime) {
    player.setAccelerationX(0.f);
    if (player.getVelocity().x > 0) {
        player.setVelocity(
                sf::Vector2f(player.getVelocity().x - PLAYER_DECELERATION_RATE * deltaTime, player.getVelocity().y));
        if (player.getVelocity().x < 0) player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
    } else if (player.getVelocity().x < 0) {
        player.setVelocity(
                sf::Vector2f(player.getVelocity().x + PLAYER_DECELERATION_RATE * deltaTime, player.getVelocity().y));
        if (player.getVelocity().x > 0) player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
    }
}

void GamingState::clampPlayerVelocity(sf::Vector2f &velocity) {
    if (velocity.x > PLAYER_MAX_SPEED) velocity.x = PLAYER_MAX_SPEED;
    if (velocity.x < -PLAYER_MAX_SPEED) velocity.x = -PLAYER_MAX_SPEED;
}

void GamingState::handleCollisions() {
    if (player.getPosition().y > 500) {
        player.setPosition(player.getPosition().x, 500);
        player.setVerticalVelocity(0.0f);
    }
}



