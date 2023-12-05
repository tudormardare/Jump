//
// Created by tudor on 22/11/2023.
//

#ifndef JUMP_PUMPKIN_H
#define JUMP_PUMPKIN_H


#include "Entity.h"

#define PUMPKIN_TEXTURE_PATH "PNG/Pumpkin/Pumpkin_1_"
#define PUMPKIN_SCALE 1.f
#define PUMPKIN_TEXTURES 1
#define PUMPKIN_MIN_FRAME_DURATION 1.f
#define PUMPKIN_MAX_FRAME_DURATION 1.f


class Pumpkin: public Entity{
public:
    Pumpkin();

    void move(float offsetX, float offsetY) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    void setTexture(const sf::Texture &texture) override;
};


#endif //JUMP_PUMPKIN_H
