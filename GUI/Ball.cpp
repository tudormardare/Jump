//
// Created by tudor on 15/11/2023.
//

#include "Ball.h"

Ball::Ball() {
    pumpkin.setPosition(0, 0);
    fire.setPosition(0, 0);
}

void Ball::update(float deltaTime) {
    pumpkin.update(deltaTime);
    fire.update(deltaTime);
}

void Ball::draw(sf::RenderWindow &window) {
    //Diseganre sempre prima il fuoco e poi la zucca
    fire.draw(window);
    pumpkin.draw(window);
}

void Ball::move(float offsetX, float offsetY) {
    pumpkin.move(offsetX, offsetY);
    fire.move(offsetX, offsetY);
}

void Ball::setVelocity(float newVelocityX, float newVelocityY) {
    pumpkin.setVelocity(newVelocityX, newVelocityY);
    fire.setVelocity(newVelocityX, newVelocityY);
}

void Ball::setFireTexture(const sf::Texture &firetexture) {
    fire.setTexture(firetexture);
}

void Ball::setPumpkinTexture(const sf::Texture &pumpkintexture) {
    pumpkin.setTexture(pumpkintexture);
}

sf::Vector2f Ball::getPosition() const {
    return pumpkin.getPosition();
}

sf::Vector2f Ball::getVelocity() const {
    return pumpkin.getVelocity();
}

void Ball::setAcceleration(sf::Vector2f newAcceleration) {
    pumpkin.setAcceleration(newAcceleration);
    fire.setAcceleration(newAcceleration);
}

void Ball::setPosition(sf::Vector2f newPosition) {
    pumpkin.setPosition(newPosition + sf::Vector2f(OFFSET_FIREBALL_X, OFFSET_FIREBALL_Y));
    fire.setPosition(newPosition);
}

Fire &Ball::getFire() {
    return fire;
}

Pumpkin &Ball::getPumpkin() {
    return pumpkin;
}
