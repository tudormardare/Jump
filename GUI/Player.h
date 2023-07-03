//
// Created by Denis Jaupi on 22/06/23.
//

#ifndef JUMP_PLAYER_H
#define JUMP_PLAYER_H

#define PLAYER_TEXTURE "PNG/Player/Player.png"
#define PLAYER_SPEED 0.5f
#define PLAYER_HEALTH 3
#define PLAYER_VELOCITY 1.5f
#define PLAYER_RUNNING_TEXTURES 6
#define PLAYER_RUNNING_PATH "PNG/Player/RunningTextures/adventurer-run-0"
#define PLAYER_RUNNING_PATH_END ".png"
#define PLAYER_SCALE 2.f

#include "SFML/Graphics.hpp"

#include "Entity.h"

class Player : public Entity {

private:
    std::unique_ptr<sf::Texture> runningTextures[PLAYER_RUNNING_TEXTURES];
    sf::Texture standardTexture;
    sf::Vector2f position;
    int health = PLAYER_HEALTH;
    bool inverseX = false;

    //Private functions
    void initTexture();

    void initSprite();



public:
    Player();

    void move(float dirX, float dirY);

    void update(sf::RenderWindow &window)  override;

    void draw(sf::RenderWindow &window) override;

    float getSpeed() const;

    void changeRunningTexture(int textureNumber);

    sf::Vector2f getOrigin() const;

    void setHealth(int newHealth);

    int getHealth() const;

    void setDefaultTexture();

    static int getRunningTexturesNumber() ;

    void inverse();

    bool getInverse() const;
};




/*
class Player : public Entity
{

public:
        Player();

        void draw(sf::RenderWindow& window) override;
        void update(float deltaTime) override;
        void move(float offsetX, float offsetY);



};
*/

#endif //JUMP_PLAYER_H
