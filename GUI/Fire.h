//
// Created by tudor on 15/11/2023.
//
#ifndef JUMP_FIRE_H
#define JUMP_FIRE_H

#include "Entity.h"
#include "../Utilities/constants.h"

class Fire: public Entity{
public:

    Fire();

    void move(float offsetX, float offsetY) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    void setTexture(const sf::Texture &texture) override;
private:

};


#endif //JUMP_FIRE_H
