//
// Created by Denis Jaupi on 22/06/23.
//

#include <iostream>
#include "Player.h"



Player::Player() {
    initTexture();
    initSprite();
}

//Private functions
void Player::initTexture() {
    std::string beginningPath(PLAYER_RUNNING_PATH);
    //Load a currentTexture from file
    standardTexture.loadFromFile(PLAYER_TEXTURE);
    for(int i = 0; i < PLAYER_RUNNING_TEXTURES; i++){
        std::string path = beginningPath + std::to_string(i) + PLAYER_RUNNING_PATH_END;
        runningTextures[i] = std::make_unique<sf::Texture>();
        if(!runningTextures[i]->loadFromFile(path)){
            std::cout << "Error loading texture from file: " << path << std::endl;
        }
    }
    currentTexture = standardTexture;
}

void Player::initSprite() {
    //Set the currentTexture to the sprite
    sprite.setTexture(currentTexture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
    //Resize the sprite
    setVelocity(sf::Vector2f (PLAYER_VELOCITY, PLAYER_VELOCITY));
    setSpeed(PLAYER_SPEED);
}


float Player::getSpeed() const {
    return speed;
}


void Player::setHealth(int newHealth) {
    health = newHealth;
}

int Player::getHealth() const {
    return health;
}

void Player::move(float dirX, float dirY) {
    sprite.move(speed * dirX, speed * dirY);
}

void Player::update(sf::RenderWindow &window) {
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

int Player::getRunningTexturesNumber() {
    return PLAYER_RUNNING_TEXTURES;
}

sf::Vector2f Player::getOrigin() const {
    return sprite.getOrigin();
}

void Player::changeRunningTexture(int textureNumber) {
    currentTexture = *runningTextures[textureNumber];
}

void Player::setDefaultTexture() {
    currentTexture = standardTexture;
}

void Player::inverse() {
    if(sprite.getScale().x > 0){
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






/*
Player::Player() {
    currentTexture.loadFromFile(PLAYER_TEXTURE);
}

void Player::draw(sf::RenderWindow &window) {
    Entity::draw(window);
}

void Player::update(float deltaTime) {

}

void Player::move(const float offsetX, const float offsetY) {
    sprite.setPosition(sprite.getPosition().x + offsetX, sprite.getPosition().y + offsetY);
}
*/