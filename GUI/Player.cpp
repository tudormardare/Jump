#include <iostream>
#include "Player.h"

// Constructor
Player::Player() {
    initSprite();
}

// Private functions

void Player::initSprite() {
    standardTexture.loadFromFile(PLAYER_TEXTURE);
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
void Player::update(float deltaTime) {
    // Implement the update logic here
    velocity.x += acceleration.x * deltaTime;
    velocity.y += acceleration.y * deltaTime;

    // Aggiorna la posizione basandoti sulla velocità
    move(velocity.x * deltaTime, velocity.y * deltaTime);
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


bool Player::isJumping() const {
    return jumping;
}

void Player::setJumping(bool jumping) {
    Player::jumping = jumping;
}

void Player::jump(float initialVelocity) {
    if (!jumping) { // Controlla se il giocatore non sta già saltando
        velocity.y = -initialVelocity; // Velocità negativa per muoversi verso l'alto
        jumping = true;
    }
}


