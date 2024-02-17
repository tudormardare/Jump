//
// Created by Denis Jaupi on 10/02/24.
//


#include "Heart.h"

void Heart::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
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
    name = "Heart";
    sprite.setScale(1, 1);
    setVelocity(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, 0));

}
