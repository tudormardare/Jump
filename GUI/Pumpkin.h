//
// Created by tudor on 22/11/2023.
//

#ifndef JUMP_PUMPKIN_H
#define JUMP_PUMPKIN_H


#include "Entity.h"
#include "../Utilities/constants.h"

class Pumpkin: public Entity{
public:
    Pumpkin();

    void move(float offsetX, float offsetY) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    void setTexture(const sf::Texture &texture) override;

    bool isHit() const {
        return hit;
    }

    void setHit(bool value) {
        hit = value;
    }

private:
    bool hit;
};


#endif //JUMP_PUMPKIN_H
