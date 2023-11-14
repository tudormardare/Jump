#ifndef JUMP_PLAYER_H
#define JUMP_PLAYER_H

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include <memory>

#define PLAYER_TEXTURE "PNG/Player/Player.png"
#define PLAYER_HEALTH 3
#define PLAYER_RUNNING_TEXTURES 6
#define PLAYER_JUMPING_TEXTURES 4
#define PLAYER_FALLING_TEXTURES 2
#define PLAYER_IDLE_TEXTURES 2
#define PLAYER_FALLING_PATH "PNG/Player/FallingTextures/adventurer-fall-0"
#define PLAYER_RUNNING_PATH "PNG/Player/RunningTextures/adventurer-run-0"
#define PLAYER_JUMPING_PATH "PNG/Player/JumpingTextures/adventurer-jump-0"
#define PLAYER_IDLE_PATH "PNG/Player/IdleTextures/adventurer-idle-0"
#define PLAYER_SCALE 2.f
#define PLAYER_ACCELERATION_RATE 200.f
#define PLAYER_MAX_SPEED 250.f
#define PLAYER_DECELERATION_RATE 1000.f

class Player : public Entity {
private:

    int health = PLAYER_HEALTH;
    bool inverseX = false;
    bool jumping = false;

    void initSprite();

public:
    Player();

    bool isJumping() const;

    void move(float dirX, float dirY) override;

    void update(float deltaTime) override;

    void draw(sf::RenderWindow &window) override;

    void setAccelerationX(float newAccelerationX);

    void jump(float initialVelocity);

    sf::Vector2f getOrigin() const;

    void setHealth(int newHealth);

    int getHealth() const;

    void setTexture(const sf::Texture &texture) override;

    void inverse();

    bool getInverse() const;

    sf::Sprite getSprite() const;
};

#endif //JUMP_PLAYER_H
