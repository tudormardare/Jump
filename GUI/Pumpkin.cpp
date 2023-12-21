//
// Created by tudor on 22/11/2023.
//

#include <iostream>
#include "Pumpkin.h"

void Pumpkin::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture);
    setCollisionRect();
}

void Pumpkin::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Pumpkin::update(float deltaTime) {
    move(velocity.x * deltaTime , velocity.y * deltaTime);
}

void Pumpkin::move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}

Pumpkin::Pumpkin() {
    sprite.setScale(PUMPKIN_SCALE, PUMPKIN_SCALE);
    setVelocity(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, 0));
}
