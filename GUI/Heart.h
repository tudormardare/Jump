//
// Created by Denis Jaupi on 10/02/24.
//

#ifndef JUMP_HEART_H
#define JUMP_HEART_H


#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "../Utilities/constants.h"


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
