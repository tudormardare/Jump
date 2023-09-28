#include <iostream>
#include "Player.h"

// Constructor
Player::Player() {
    initTexture();
    initSprite();
}

// Private functions
void Player::initTexture() {
    std::string beginningPath(PLAYER_RUNNING_PATH);
    standardTexture.loadFromFile(PLAYER_TEXTURE);
    for(int i = 0; i < PLAYER_RUNNING_TEXTURES; i++) {
        std::string path = beginningPath + std::to_string(i) + PLAYER_RUNNING_PATH_END;
        runningTextures[i] = std::make_unique<sf::Texture>();
        if(!runningTextures[i]->loadFromFile(path)) {
            std::cout << "Error loading texture from file: " << path << std::endl;
        }
    }
}

void Player::initSprite() {
    sprite.setTexture(standardTexture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);

    setVelocity(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, 0));
}

// Movement
void Player::move(float dirX, float dirY) {
    sprite.move(dirX, dirY);
}

// Update & Draw
void Player::update(sf::RenderWindow &window) {
    // Implement the update logic here
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

// Getters & Setters
sf::Vector2f Player::getAcceleration() const {
    return acceleration;
}

void Player::setAccelerationX(float newAccelerationX) {
    acceleration.x = newAccelerationX;
}


void Player::changeRunningTexture(int textureNumber) {
    if(textureNumber >= 0 && textureNumber < PLAYER_RUNNING_TEXTURES) {
        sprite.setTexture(*runningTextures[textureNumber]);
    }
}

sf::Vector2f Player::getOrigin() const {
    return sprite.getOrigin();
}

void Player::setHealth(int newHealth) {
    health = newHealth;
}

int Player::getHealth() const {
    return health;
}

void Player::setDefaultTexture() {
    sprite.setTexture(standardTexture);
}

int Player::getRunningTexturesNumber() {
    return PLAYER_RUNNING_TEXTURES;
}

void Player::inverse() {
    if(sprite.getScale().x > 0) {
        sprite.setScale(-PLAYER_SCALE, PLAYER_SCALE);
        inverseX = true;
    } else {
        sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
        inverseX = false;
    }
}

bool Player::getInverse() const {
    return inverseX;
}
