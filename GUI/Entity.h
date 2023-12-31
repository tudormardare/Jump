//
// Created by Denis Jaupi on 22/06/23.
//

#ifndef JUMP_ENTITY_H
#define JUMP_ENTITY_H

#include "SFML/Graphics.hpp"


class Entity {
private:
    sf::IntRect hitbox;

protected:
    sf::Sprite sprite;
    sf::Texture currentTexture;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f maxSpeed;

    void setCollisionRect() ;


public:
    //Functions
    virtual void setTexture(const sf::Texture &texture) = 0;

    sf::Vector2f getCenter() const;

    sf::Vector2f getScale() const;

     void setAcceleration(sf::Vector2f newAcceleration);

     void setPosition(sf::Vector2f newPosition);

    void setPosition(float x, float y);

    void setVelocity(sf::Vector2f newVelocity);

    virtual sf::Vector2f getPosition() const;

    virtual sf::Vector2f getVelocity() const;

    virtual void update(float deltaTime) = 0;

    virtual void draw(sf::RenderWindow &window) = 0;

    virtual void move(float offsetX, float offsetY) = 0;

    virtual void setVelocity(float newVelocityX, float newVelocityY);

    float getVerticalVelocity() const;

    void setVerticalVelocity(float d);

    sf::Rect<float> getGlobalBounds() const;

    sf::Rect<float> getLocalBounds() const;

    sf::Vector2f getMaxSpeed() const;

    sf::Vector2f getAcceleration() const;

    sf::Sprite getSprite() const;

    sf::FloatRect getHitbox() const;
};

#endif //JUMP_ENTITY_H
