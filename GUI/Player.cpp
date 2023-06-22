//
// Created by Denis Jaupi on 22/06/23.
//
#define PLAYER_TEXTURE "PNG/MenuButton/Button.png"

#include "Player.h"

Player::Player() {
    texture.loadFromFile(PLAYER_TEXTURE);
}

void Player::draw(sf::RenderWindow &window) {
    Entity::draw(window);
}

void Player::update(float deltaTime) {

}

void Player::move(const float offsetX, const float offsetY) {

    sprite.setPosition(sprite.getPosition().x + offsetX, sprite.getPosition().y + offsetY);

}
