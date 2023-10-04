#ifndef JUMP_PLAYER_H
#define JUMP_PLAYER_H

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include <memory>

#define PLAYER_TEXTURE "PNG/Player/Player.png"
#define PLAYER_HEALTH 3
#define PLAYER_VELOCITY 200.f
#define PLAYER_RUNNING_TEXTURES 6
#define PLAYER_JUMPING_TEXTURES 4
#define PLAYER_FALLING_TEXTURES 2
#define PLAYER_IDLE_TEXTURES 2
#define PLAYER_FALLING_PATH "PNG/Player/FallingTextures/adventurer-fall-0"
#define PLAYER_RUNNING_PATH "PNG/Player/RunningTextures/adventurer-run-0"
#define PLAYER_JUMPING_PATH "PNG/Player/JumpingTextures/adventurer-jump-0"
#define PLAYER_IDLE_PATH "PNG/Player/IdleTextures/adventurer-idle-0"
#define PLAYER_SCALE 2.f
#define PLAYER_ACCELERATION_RATE 150.f
#define PLAYER_MAX_SPEED 250.f
#define PLAYER_DECELERATION_RATE 1000.f
#define PLAYER_CHANGE_DIRECTION_SPEED 3.f // The higher the value, the faster the player will change direction
#define PLAYER_JUMP_FORCE -450.f


class Player : public Entity {
private:
    std::unique_ptr<sf::Texture> runningTextures[PLAYER_RUNNING_TEXTURES];
    std::unique_ptr<sf::Texture> jumpingTextures[PLAYER_JUMPING_TEXTURES];
    std::unique_ptr<sf::Texture> idleTextures[PLAYER_IDLE_TEXTURES];
    std::unique_ptr<sf::Texture> fallingTextures[PLAYER_FALLING_TEXTURES];
    sf::Texture standardTexture;
    int health = PLAYER_HEALTH;
    bool inverseX = false;
    bool jumping = false;
public:
    bool isJumping() const;

    void setJumping(bool jumping);

private:


    // Private functions
    void initTexture();
    void initSprite();

    void loadStandardTexture();
    void loadAnimationTextures(const std::string& basePath, int textureCount, std::unique_ptr<sf::Texture> texturesArray[]);

public:
    Player();

    // Movement
    void move(float dirX, float dirY);

    // Update & Draw
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;

    // Getters & Setters
    sf::Vector2f getAcceleration() const;
    void setAccelerationX(float newAccelerationX);
    void changeRunningTexture(int textureNumber);
    void changeJumpingTexture(int textureNumber);
    void changeIdleTexture(int textureNumber);
    void changeFallingTexture(int textureNumber);
    void jump(float initialVelocity);
    sf::Vector2f getOrigin() const;
    void setHealth(int newHealth);
    int getHealth() const;
    void setDefaultTexture();
    void inverse();
    bool getInverse() const;
};

#endif //JUMP_PLAYER_H
