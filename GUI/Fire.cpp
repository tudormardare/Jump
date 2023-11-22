//
// Created by tudor on 15/11/2023.
//

#include "Fire.h"

void Fire::move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}

void Fire::update(float deltaTime) {
    move(velocity.x * deltaTime , velocity.y * deltaTime);
}

void Fire::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Fire::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setOrigin(0,0);
    nonTransparentBounds = setNonTransparentBounds();
}

Fire::Fire() {
    sprite.setScale(FIRE_SCALE, FIRE_SCALE);
    setVelocity(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, 0));
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}
