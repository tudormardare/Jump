//
// Created by Denis Jaupi on 22/06/23.
//
#include "Entity.h"

//Functions
void Entity::setPosition(sf::Vector2f newPosition)
{
    sprite.setPosition(newPosition);
}

sf::Vector2f Entity::getPosition() const{
    return sprite.getPosition();
}

void Entity::setVelocity(sf::Vector2f newVelocity) {
    this->velocity = newVelocity;
}

void Entity::setSpeed(float newSpeed) {
    this->speed = newSpeed;
}

sf::Vector2f Entity::getVelocity() const {
    return velocity;
}

void Entity::setVelocity(float newVelocityX, float newVelocityY) {
    this->velocity.x = newVelocityX;
    this->velocity.y = newVelocityY;
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

