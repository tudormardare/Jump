//
// Created by Denis Jaupi on 26/06/23.
//

#ifndef JUMP_GHOST_H
#define JUMP_GHOST_H

#include "Entity.h"
#include <cstdlib>
#include <cmath>


class Ghost : public Entity {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

    sf::Vector2f* playerPosition;
    float movementSpeed;
    bool isAlive;

    //Private functions
    void initTexture();
    void initSprite();
    float getSpeed() const;


    void spawnRandomly();


public:

    Ghost(sf::Vector2f playerPosition);
    virtual ~Ghost();


    /*Function updatePosition:
     * - Player direction
     * - Update Ghost position according to his direction and velocity
     */


    void update(sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;


};


#endif //JUMP_GHOST_H
