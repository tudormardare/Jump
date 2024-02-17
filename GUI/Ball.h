//
// Created by tudor on 15/11/2023.
//

#ifndef JUMP_BALL_H
#define JUMP_BALL_H

#include "Pumpkin.h"
#include "Fire.h"
#include "../Utilities/constants.h"

class Ball{

private:
    Pumpkin pumpkin;
    Fire fire;
public:

    Ball();
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    void move(float offsetX, float offsetY);
    void setVelocity(float newVelocityX, float newVelocityY);
    void setFireTexture( const sf::Texture &firetexture);
    void setPumpkinTexture( const sf::Texture &pumpkintexture);
    void setPosition(sf::Vector2f newPosition);
    Fire& getFire() ;
    Pumpkin& getPumpkin() ;
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;
    void setAcceleration(sf::Vector2f newAcceleration);
    void setVerticalVelocity(float d);
    float getVerticalVelocity() const;
    sf::Rect<float> getGlobalBounds() const;
    sf::Rect<float> getLocalBounds() const;
    sf::Vector2f getCenter() const;
    sf::Vector2f getScale() const;
    void setCollisionRect();
};


#endif //JUMP_BALL_H
