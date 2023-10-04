//
// Created by Denis Jaupi on 22/06/23.
//

#ifndef JUMP_ENTITY_H
#define JUMP_ENTITY_H

#include "SFML/Graphics.hpp"


class Entity {

protected:
    sf::Sprite sprite;
    sf::Texture currentTexture;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;


public:
    //Functions
    virtual void setTexture(sf::Texture& texture);
    virtual void setAcceleration(sf::Vector2f newAcceleration);
    virtual void setPosition(sf::Vector2f newPosition);
    virtual void setVelocity(sf::Vector2f newVelocity);
    virtual sf::Vector2f getPosition() const;
    virtual sf::Vector2f getVelocity() const;
    virtual void update(sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void setVelocity(float newVelocityX, float newVelocityY);
};
/*
class Entity {

public:

    Entity();
    virtual ~Entity() = default;

    void setPosition(const sf::Vector2f &position);
    void setVelocity(const sf::Vector2f& velocity);
    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition();

    sf::FloatRect getGlobalBounds();
    banananaisdjisj

protected:

    sf::Sprite sprite;
    sf::Vector2f velocity;
    sf::Texture currentTexture;

};
*/

#endif //JUMP_ENTITY_H
