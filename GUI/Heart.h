//
// Created by Denis Jaupi on 10/02/24.
//

#ifndef JUMP_HEART_H
#define JUMP_HEART_H


#include <SFML/Graphics.hpp>
#include "Entity.h"

#define HEART_SPAWN_INTERVAL 5.f
#define HEART_FALL_SPEED 100.f
#define HEART_SCALE 1.f
#define HEART_TEXTURES 4
#define HEART_MIN_FRAME_DURATION 0.5f
#define HEART_MAX_FRAME_DURATION 0.5f
#define HEART_TEXTURE_PATH "PNG/Heart/Heart_1_"


class Heart : public Entity {
private:
    bool visible;
public:
    Heart();

    void move(float offsetX, float offsetY) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    void setTexture(const sf::Texture &texture) override;

    bool isVisible() const {
        return visible;
    }

    void setVisible(bool value) {
        visible = value;
    }

    bool isCollected() const {
        return collected;
    }

    void setCollected(bool value) {
        collected = value;
    }


private:
    bool collected;
};


#endif //JUMP_HEART_H
