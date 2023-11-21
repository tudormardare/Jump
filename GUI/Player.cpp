#include <iostream>
#include "Player.h"

Player::Player() {
    initSprite();
}

void Player::initSprite() {
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
    maxSpeed = sf::Vector2f(PLAYER_MAX_SPEED, PLAYER_MAX_SPEED);
    setVelocity(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, PLAYER_ACCELERATION_RATE));
}

void Player::move(float dirX, float dirY) {
    sprite.move(dirX, dirY);
}

void Player::update(float deltaTime) {
    move(velocity.x * deltaTime , velocity.y * deltaTime);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Player::setAccelerationX(float newAccelerationX) {
    acceleration.x = newAccelerationX;
}
void Player::setAccelerationY(float newAccelerationY) {
    acceleration.y = newAccelerationY;
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


void Player::inverse() {
    if (sprite.getScale().x > 0) {
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

void Player::jump(float initialVelocity) {
    if (!jumping) { // Controlla se il giocatore non sta già saltando
        velocity.y = -initialVelocity; // Velocità negativa per muoversi verso l'alto
        jumping = true;
    }
}

void Player::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

sf::Sprite Player::getSprite() const {
    return sprite;
}


