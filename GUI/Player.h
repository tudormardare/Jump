//
// Created by Denis Jaupi on 22/06/23.
//

#ifndef JUMP_PLAYER_H
#define JUMP_PLAYER_H


#include "Entity.h"

class Player : public Entity {

public:
        Player();

        void draw(sf::RenderWindow& window) override;
        void update(float deltaTime) override;
        void move(float offsetX, float offsetY);



};


#endif //JUMP_PLAYER_H
