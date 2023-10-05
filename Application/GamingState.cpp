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
    if(event.type == sf::Event::KeyReleased) {
        if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) {
            player.setDefaultTexture();
        }
    }
}

void GamingState::update(sf::RenderWindow &window, float deltaTime) {


      // Aumentato per una decelerazione più rapida
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    if (isKeyPressedA && !isKeyPressedD) {
        if(!player.getInverse()){
            player.inverse();
        }
        runningAnimation(deltaTime);
        player.setAccelerationX(-PLAYER_ACCELERATION_RATE);
    } else if (isKeyPressedD && !isKeyPressedA) {
        if(player.getInverse()){
            player.inverse();
        }
        runningAnimation(deltaTime);
        player.setAccelerationX(PLAYER_ACCELERATION_RATE);
    } else {
        player.setAccelerationX(0.f);
        player.setDefaultTexture();

        // Decelerazione più rapida
        if (player.getVelocity().x > 0) {
            player.setVelocity(sf::Vector2f(player.getVelocity().x - PLAYER_DECELERATION_RATE * deltaTime, player.getVelocity().y));
            if (player.getVelocity().x < 0) player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
        } else if (player.getVelocity().x < 0) {
            player.setVelocity(sf::Vector2f(player.getVelocity().x + PLAYER_DECELERATION_RATE * deltaTime, player.getVelocity().y));
            if (player.getVelocity().x > 0) player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
        }
    }

    sf::Vector2f currentVelocity = player.getVelocity();
    currentVelocity.x += player.getAcceleration().x * deltaTime;
    if (currentVelocity.x > PLAYER_MAX_SPEED) currentVelocity.x = PLAYER_MAX_SPEED;
    if (currentVelocity.x < -PLAYER_MAX_SPEED) currentVelocity.x = -PLAYER_MAX_SPEED;

    player.setVelocity(currentVelocity);
    player.move(currentVelocity.x * deltaTime, 0.f);
}





void GamingState::render(sf::RenderWindow &window) {
    gameMap.render(window);
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

void GamingState::runningAnimation(float deltaTime) {
    animationTimer += deltaTime;
    if (animationTimer >= FRAME_DURATION) {
        animationTimer = 0.f;
        currentFrame = (currentFrame + 1) % RUNNING_FRAMES;
        player.changeRunningTexture(currentFrame);
    }
}

void GamingState::stopAnimation() {
    player.setDefaultTexture();
}



