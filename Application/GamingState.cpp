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
    if(event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
    }
}

void GamingState::update(sf::RenderWindow &window, float deltaTime) {

    player.setVelocity(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.setVelocity( 0.f, -1.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.setVelocity( 0.f, 1.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.setVelocity( -1.f, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.setVelocity( 1.f, 0.f);
    }

    float length = std::sqrt(player.getVelocity().x * player.getVelocity().x + player.getVelocity().y * player.getVelocity().y);
    if (length != 0.f) {
        player.setVelocity(player.getVelocity()/length);
    }
    player.setVelocity(player.getVelocity() * player.getSpeed());
    player.move(player.getVelocity().x, player.getVelocity().y);

    if (player.getPosition().x + player.getOrigin().x > (float) window.getSize().x ||
        player.getPosition().x - player.getOrigin().x < 0) {
        player.setVelocity(-player.getVelocity().x, player.getVelocity().y);
    }

    if (player.getPosition().y + player.getOrigin().y > (float) window.getSize().y ||
        player.getPosition().y - player.getOrigin().y < 0) {
        player.setVelocity(player.getVelocity().x, -player.getVelocity().y);
    }


    // Cambia la texture ogni frameDuration millisecondi
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(player.getInverse()){
            player.inverse();
        }
        runningAnimation(deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(!player.getInverse()){
            player.inverse();
        }
        runningAnimation(deltaTime);
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

void GamingState::runningAnimation(float deltaTime) {

    animationTimer += deltaTime;
    if (animationTimer >= FRAME_DURATION) {
        animationTimer = 0.f;
        currentFrame = (currentFrame + 1) % RUNNING_FRAMES;
        switch (currentFrame) {
            case 0:
                player.changeRunningTexture(0);
                currentFrame++;
                break;
            case 1:
                player.changeRunningTexture(1);
                currentFrame++;
                break;
            case 2:
                player.changeRunningTexture(2);
                currentFrame++;
                break;
            case 3:
                player.changeRunningTexture(3);
                currentFrame++;
                break;
            case 4:
                player.changeRunningTexture(4);
                currentFrame++;
                break;
            case 5:
                player.changeRunningTexture(5);
                currentFrame = 0;
                break;
            default:
                currentFrame = 0;
                break;
        }
    }

}

void GamingState::stopAnimation() {
    player.setDefaultTexture();
}



