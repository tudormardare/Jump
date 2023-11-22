//
// Created by tudor on 15/11/2023.
//

#ifndef JUMP_FIRE_H
#define JUMP_FIRE_H

#define FIRE_TEXTURE_PATH "PNG/Fire/1_"
#define FIRE_SCALE 2.f
#define FIRE_TEXTURES 60
#define FIRE_MIN_FRAME_DURATION 1.f
#define FIRE_MAX_FRAME_DURATION 1.f
#define FIRE_RECTANGLE_WIDTH 16
#define FIRE_RECTANGLE_HEIGHT 16
#define FIRE_DEFAULT_SPEED 20.f

#include "Entity.h"

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
