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

    float movementSpeed;

    //Private functions
    void initTexture();
    void initSprite();

public:
    Player();
    virtual ~Player();

    //Functions
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
