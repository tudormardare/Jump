//
// Created by Denis Jaupi on 22/06/23.
//
#define PLAYER_TEXTURE "PNG/Player/Player.png"

#include "Player.h"


Player::Player()
{
    movementSpeed = 4.f;

    initTexture();
    initSprite();

}

Player::~Player()
{

}


void Player::initTexture()
{
    //Load a texture from file
    texture.loadFromFile(PLAYER_TEXTURE);

}

void Player::initSprite()
{
    //Set the texture to the sprite
    sprite.setTexture(texture);

    //Resize the sprite
    sprite.scale(4.0f, 4.0f);

}

void Player::move(const float dirX, const float dirY)
{
    sprite.move(movementSpeed*dirX, movementSpeed*dirY);
}

//Function
void Player::update()
{

}

void Player::render(sf::RenderTarget &target)
{
    target.draw(sprite);
}



/*
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
*/