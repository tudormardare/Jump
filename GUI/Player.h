#ifndef JUMP_PLAYER_H
#define JUMP_PLAYER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Entity.h"
#include <memory>
#include "../Utilities/constants.h"

class Player : public Entity {
private:

    int hp;
    int hpMax = PLAYER_HEALTH;

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

    void setAccelerationY(float newAccelerationY);

    void jump(float initialVelocity);

    sf::Vector2f getOrigin() const;

    void setHealth(int newHealth);

    void resetHealth() {
        hp = hpMax;  // Supponendo che maxHealth sia un attributo che rappresenta il massimo delle vite
    }


    int getHealth() const;

    void takeDamage();

    void gainHealth();

    void setTexture(const sf::Texture &texture) override;

    void inverse();

    bool getInverse() const;

    void renderHealth(sf::RenderWindow &window);

    void setJumping(bool newJumping);

};

#endif //JUMP_PLAYER_H
