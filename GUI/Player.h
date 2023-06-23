//
// Created by Denis Jaupi on 22/06/23.
//

#ifndef JUMP_PLAYER_H
#define JUMP_PLAYER_H


#include "Entity.h"

class Player : public Entity
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;

    float movementSpeed;
    int health;

    //Private functions
    void initTexture();
    void initSprite();

    void setSpeed(float newSpeed);
    float getSpeed() const;

    void setHealth(int newHealth);
    int getHealth() const;

public:
    Player();
    virtual ~Player();


    void setPosition(sf::Vector2f newPosition) override;
    sf::Vector2f getPosition() const override;


    void move(const float dirX, const float dirY);

    void update() override;
    void render(sf::RenderTarget& target) override;

};



/*
class Player : public Entity
{

public:
        Player();

        void draw(sf::RenderWindow& window) override;
        void update(float deltaTime) override;
        void move(float offsetX, float offsetY);



};
*/

#endif //JUMP_PLAYER_H
