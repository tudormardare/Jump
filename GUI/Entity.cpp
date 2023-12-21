//
// Created by Denis Jaupi on 22/06/23.
//
#include <iostream>
#include "Entity.h"

//Functions
void Entity::setPosition(sf::Vector2f newPosition) {
    sprite.setPosition(newPosition);
}

sf::Vector2f Entity::getPosition() const {
    return sprite.getPosition();
}

void Entity::setVelocity(sf::Vector2f newVelocity) {
    this->velocity = newVelocity;
}


sf::Vector2f Entity::getVelocity() const {
    return velocity;
}

void Entity::setVelocity(float newVelocityX, float newVelocityY) {
    this->velocity.x = newVelocityX;
    this->velocity.y = newVelocityY;
}

void Entity::setAcceleration(sf::Vector2f newAcceleration) {
    this->acceleration = newAcceleration;
}


void Entity::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

float Entity::getVerticalVelocity() const {
    return velocity.y;
}

void Entity::setVerticalVelocity(float velocityY) {
    velocity.y = velocityY;
}

sf::Vector2f Entity::getAcceleration() const {
    return acceleration;
}

sf::Vector2f Entity::getMaxSpeed() const {
    return maxSpeed;
}

sf::Rect<float> Entity::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

sf::Rect<float> Entity::getLocalBounds() const {
    return sprite.getLocalBounds();
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}

sf::Vector2f Entity::getScale() const {
    return sprite.getScale();
}

sf::Vector2f Entity::getCenter() const {
    const sf::FloatRect bounds = getHitbox(); // Assicurati che questo metodo restituisca i GlobalBounds dell'entità
    return sf::Vector2f(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
}
sf::FloatRect Entity::getHitbox() const{
        sf::FloatRect globalBounds = sprite.getTransform().transformRect(static_cast<sf::FloatRect>(hitbox));
        return globalBounds;
}

void Entity::setCollisionRect()  {
    sf::Image image = sprite.getTexture()->copyToImage();
    int left = image.getSize().x, top = image.getSize().y, right = 0, bottom = 0;

    for (unsigned int x = 0; x < image.getSize().x; ++x) {
        for (unsigned int y = 0; y < image.getSize().y; ++y) {
            if (image.getPixel(x, y).a != 0) { // Pixel non trasparente
                left = std::min(left, static_cast<int>(x));
                top = std::min(top, static_cast<int>(y));
                right = std::max(right, static_cast<int>(x));
                bottom = std::max(bottom, static_cast<int>(y));
            }
        }
    }

    if (left > right || top > bottom) {
        std::cout << "ERRORE: " << sprite.getTexture()->copyToImage().getSize().x << " " << sprite.getTexture()->copyToImage().getSize().y << std::endl;
    }
   hitbox = sf::IntRect(left, top, right - left + 1, bottom - top + 1);
}













/*
void Entity::setPosition(const sf::Vector2f &position) {
    sprite.setPosition(position);
}

void Entity::setVelocity(const sf::Vector2f &velocity) {
    this->velocity = velocity;
}

void Entity::update(const float deltaTime) {
    //TODO
}

void Entity::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect Entity::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

Entity::Entity() {

}

sf::Vector2f Entity::getPosition() {
    return sprite.getPosition();
}
*/

