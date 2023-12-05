//
// Created by tudor on 22/06/2023.
//

#ifndef JUMP_COLLISIONMANAGER_H
#define JUMP_COLLISIONMANAGER_H

#include <SFML/Graphics.hpp>
#include "../GUI/Player.h"
#include "CameraManager.h"

class CollisionManager {
private:
    static CameraManager cameraManager;

public:

    static bool checkCollision(const sf::FloatRect &rect1, const sf::FloatRect &rect2);
    static void handleWindowBoundsCollisions(sf::Sprite &player, const sf::RenderTarget* target);
    static void handleEnemyCollisions(sf::Sprite &player, std::vector<sf::Sprite> &enemies);
    static void handlePlatformCollisions(sf::Sprite &player, const std::vector<sf::FloatRect>& platformBounds);
    static void handlePowerUpCollisions(sf::Sprite &player, std::vector<sf::Sprite> &powerUps);

};


#endif //JUMP_COLLISIONMANAGER_H
