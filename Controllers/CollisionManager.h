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
    enum class CollisionDirection {
        None,
        Top,
        Bottom,
        Left,
        Right
    };

    struct CollisionResult {
        bool hasCollision;
        CollisionDirection direction;
    };

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


    CollisionResult checkMapCollision(Entity& entity, const std::vector<sf::FloatRect>& mapHitboxes) {
        sf::FloatRect entityBounds = entity.getHitbox();
        sf::Vector2f entityCenter = entity.getCenter(); // Dovrai implementare questo metodo nella classe Entity.

        CollisionResult result{false, CollisionDirection::None};

        for (const auto& hitbox : mapHitboxes) {
            if (entityBounds.intersects(hitbox)) {
                // Collisione rilevata, ora determiniamo la direzione
                result.hasCollision = true;

                // Calcola il punto centrale della hitbox della mappa
                sf::Vector2f hitboxCenter(hitbox.left + hitbox.width / 2.0f, hitbox.top + hitbox.height / 2.0f);

                // Distanze tra i centri
                float deltaX = entityCenter.x - hitboxCenter.x;
                float deltaY = entityCenter.y - hitboxCenter.y;

                // Assumiamo che il player non possa passare attraverso le piattaforme, quindi verifichiamo solo da sopra o da sotto
                // Verifica quale lato ha una maggiore sovrapposizione
                if (std::abs(deltaX) > std::abs(deltaY)) {
                    if (deltaX > 0) {
                        result.direction = CollisionDirection::Right;
                    } else {
                        result.direction = CollisionDirection::Left;
                    }
                } else {
                    if (deltaY > 0) {
                        result.direction = CollisionDirection::Bottom;
                    } else {
                        result.direction = CollisionDirection::Top;
                    }
                }

                // Una volta rilevata la collisione, puoi uscire dal ciclo se non hai bisogno di ulteriori informazioni
                break;
            }
        }
        return result;
    }



};


#endif //JUMP_COLLISIONMANAGER_H
