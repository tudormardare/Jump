//
// Created by tudor on 22/06/2023.
//

#ifndef JUMP_COLLISIONMANAGER_H
#define JUMP_COLLISIONMANAGER_H

#include <SFML/Graphics.hpp>


class CollisionManager {
public:

    static bool checkCollision(const sf::FloatRect &rect1, const sf::FloatRect &rect2) {
        return rect1.intersects(rect2);
    }

    static void handleEnemyCollisions(sf::Sprite &player, std::vector<sf::Sprite> &enemies) {
        for (auto &enemy: enemies) {
            if (checkCollision(player.getGlobalBounds(), enemy.getGlobalBounds())) {
                //Devo ritornare chi viene colpito se si tratta di un fantasma
                //La palla invece è indistruttibile quindi, il personaggio perde lo scudo o la vita
            }
        }
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
};


#endif //JUMP_COLLISIONMANAGER_H
