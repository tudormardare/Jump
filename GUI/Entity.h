//
// Created by Denis Jaupi on 22/06/23.
//

#ifndef JUMP_ENTITY_H
#define JUMP_ENTITY_H

#include "SFML/Graphics.hpp"


class Entity {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;


public:
    Entity();

    virtual ~Entity();


    //Functions
    virtual void setPosition(sf::Vector2f newPosition);

    virtual sf::Vector2f getPosition() const;

    virtual void update();

    virtual void render(sf::RenderTarget &target);

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

protected:

    sf::Sprite sprite;
    sf::Vector2f velocity;
    sf::Texture texture;

};
*/

#endif //JUMP_ENTITY_H
