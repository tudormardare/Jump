//
// Created by tudor on 22/06/2023.
//

#ifndef JUMP_COLLISIONMANAGER_H
#define JUMP_COLLISIONMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <valarray>
#include "../GUI/Entity.h"


class CollisionManager {
public:

    static bool checkCollision(const sf::FloatRect &rect1, const sf::FloatRect &rect2) {
        return rect1.intersects(rect2);
    }
    static Entity* handleEnemyCollisionsEntity (Entity &player, std::vector<Entity*> &enemies) {
        for (auto &enemy: enemies) {
            if (checkCollision(player.getGlobalBounds(), enemy->getGlobalBounds())) {
                    // Il giocatore ha collisionato con un nemico!
                    return enemy;
                // Il giocatore ha collisionato con un nemico
            }
        }
        return nullptr;
    }

    static bool checkCircleCollision(const Entity& sprite1, const Entity& sprite2) {
        sf::Vector2f pos1 = sprite1.getPosition();
        sf::Vector2f pos2 = sprite2.getPosition();

        float radius1 = std::max(sprite1.getGlobalBounds().width , sprite1.getGlobalBounds().height) / 3.0f;
        float radius2 = std::max(sprite2.getGlobalBounds().width , sprite2.getGlobalBounds().height) / 3.0f;

        float distance = std::sqrt(std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2));
        return distance < (radius1 + radius2);
    }

    static Entity* handleCircleEnemy(Entity &player, std::vector<Entity*> &enemies) {
        for (auto &enemy : enemies) {
            if (checkCircleCollision(player, *enemy)) {
                return enemy;
            }
        }
        return nullptr;
    }


    static void handlePlatformCollisions(sf::Sprite &player, std::vector<sf::Sprite> &platforms) {
        for (auto &platform: platforms) {
            if (checkCollision(player.getGlobalBounds(), platform.getGlobalBounds())) {
                // Il giocatore ha collisionato con una piattaforma!
                // Aggiungi qui la logica desiderata, ad esempio permettere al giocatore di saltare
            }
        }
    }

    static void handlePowerUpCollisions(sf::Sprite &player, std::vector<sf::Sprite> &powerUps) {
        for (auto &powerUp: powerUps) {
            if (checkCollision(player.getGlobalBounds(), powerUp.getGlobalBounds())) {
                // Il giocatore ha collisionato con un powerUp!
                // Aggiungi qui la logica desiderata, ad esempio permettere al giocatore di saltare
            }
        }
    }

    static sf::FloatRect getTransformedBounds(const sf::Sprite& sprite, const sf::IntRect& localBounds) {
        // Calcola la trasformazione globale dello sprite
        sf::Transform transform = sprite.getTransform();

        // Trasforma i punti del rettangolo locale in coordinate globali
        sf::Vector2f topLeft = transform.transformPoint(static_cast<float>(localBounds.left), static_cast<float>(localBounds.top));
        sf::Vector2f bottomRight = transform.transformPoint(static_cast<float>(localBounds.left + localBounds.width), static_cast<float>(localBounds.top + localBounds.height));

        return sf::FloatRect(topLeft.x, topLeft.y, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
    }


    static bool checkMapCollision(const sf::Sprite& entity, const std::vector<bool>& mapBitMask, const sf::Vector2u& mapSize) {
        sf::FloatRect bounds = entity.getGlobalBounds();

        for (int x = std::max(0, static_cast<int>(bounds.left)); x < std::min(static_cast<int>(mapSize.x), static_cast<int>(bounds.left + bounds.width)); x++) {
            for (int y = std::max(0, static_cast<int>(bounds.top)); y < std::min(static_cast<int>(mapSize.y), static_cast<int>(bounds.top + bounds.height)); y++) {
                if (mapBitMask[x + y * mapSize.x]) {
                    return true; // Collisione con la mappa
                }
            }
        }
        return false;
    }



};


#endif //JUMP_COLLISIONMANAGER_H
