//
// Created by Denis Jaupi on 10/02/24.
//


#include "Heart.h"

void Heart::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture);
    setCollisionRect();
}

void Heart::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Heart::update(float deltaTime) {
    move(velocity.x * deltaTime, velocity.y * deltaTime);
}

void Heart::move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}

Heart::Heart() : collected(false) {
    sprite.setScale(HEART_SCALE, HEART_SCALE);
    setVelocity(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, 0));

}
