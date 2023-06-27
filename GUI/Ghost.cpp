//
// Created by Denis Jaupi on 26/06/23.
//
#define GHOST_TEXTURE "PNG/Ghost/Ghost.png"

#include "Ghost.h"

Ghost::Ghost(sf::Vector2f playerPosition) {
    movementSpeed = 2.f;

    spawnRandomly();

    initTexture();
    initSprite();

}

Ghost::~Ghost() {

}

void Ghost::update() {

}

void Ghost::render(sf::RenderTarget &target) {
    sprite.setPosition(position);
    target.draw(sprite);
}


//Private functions

void Ghost::spawnRandomly() {
    // Genera una posizione casuale all'esterno dello schermo
    int side = std::rand() % 4; // 0 = top, 1 = right, 2 = bottom, 3 = left
    sf::Vector2u windowSize = sf::Vector2u(800, 600);
    switch (side) {
        case 0: // top
            position = sf::Vector2f(std::rand() % windowSize.x, -50);
            break;
        case 1: // right
            position = sf::Vector2f(windowSize.x + 50, std::rand() % windowSize.y);
            break;
        case 2: // bottom
            position = sf::Vector2f(std::rand() % windowSize.x, windowSize.y + 50);
            break;
        case 3: // left
            position = sf::Vector2f(-50, std::rand() % windowSize.y);
            break;
    }

    sprite.setPosition(position);

}

void Ghost::initTexture() {
    //Load a texture from file
    texture.loadFromFile(GHOST_TEXTURE);
}

void Ghost::initSprite() {
    //Set the texture to the sprite
    sprite.setTexture(texture);

    //Resize the sprite
    sprite.scale(4.0f, 4.0f);
}

void Ghost::setSpeed(float newSpeed) {
    movementSpeed = newSpeed;
}

float Ghost::getSpeed() const {
    return movementSpeed;
}



