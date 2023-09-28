#ifndef JUMP_PLAYER_H
#define JUMP_PLAYER_H

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include <memory>

#define PLAYER_TEXTURE "PNG/Player/Player.png"
#define PLAYER_HEALTH 3
#define PLAYER_VELOCITY 200.f
#define PLAYER_RUNNING_TEXTURES 6
#define PLAYER_RUNNING_PATH "PNG/Player/RunningTextures/adventurer-run-0"
#define PLAYER_RUNNING_PATH_END ".png"
#define PLAYER_SCALE 2.f
#define PLAYER_ACCELERATION_RATE 200.f
#define PLAYER_MAX_SPEED 250.f
#define PLAYER_DECELERATION_RATE 1000.f


class Player : public Entity {
private:
    std::unique_ptr<sf::Texture> runningTextures[PLAYER_RUNNING_TEXTURES];
    sf::Texture standardTexture;
    int health = PLAYER_HEALTH;
    bool inverseX = false;

    // Private functions
    void initTexture();
    void initSprite();

public:
    Player();

    // Movement
    void move(float dirX, float dirY);

    // Update & Draw
    void update(sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;

    // Getters & Setters
    sf::Vector2f getAcceleration() const;
    void setAccelerationX(float newAccelerationX);
    void changeRunningTexture(int textureNumber);
    sf::Vector2f getOrigin() const;
    void setHealth(int newHealth);
    int getHealth() const;
    void setDefaultTexture();
    static int getRunningTexturesNumber();
    void inverse();
    bool getInverse() const;
};

#endif //JUMP_PLAYER_H
