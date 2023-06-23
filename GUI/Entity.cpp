//
// Created by Denis Jaupi on 22/06/23.
//
#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}



//Functions
void Entity::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
}

sf::Vector2f Entity::getPosition() const
{
    return position;
}





void Entity::update()
{

}

void Entity::render(sf::RenderTarget &target)
{
    sprite.setPosition(position);
    target.draw(sprite);
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

