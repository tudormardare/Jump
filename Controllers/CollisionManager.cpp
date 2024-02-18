/*
//
// Created by tudor on 22/06/2023.
//


#include "CollisionManager.h"
#include "CameraManager.h"

bool CollisionManager::checkCollision(const sf::FloatRect &rect1, const sf::FloatRect &rect2) {
    return rect1.intersects(rect2);
}

void CollisionManager::handleWindowBoundsCollisions(sf::Sprite &player, const sf::RenderTarget* target) {

        //Left
        if(player.getGlobalBounds().left <= 0.f)
            player.setPosition(0.f, player.getGlobalBounds().top);
        //Right
        else if(player.getGlobalBounds().left + player.getGlobalBounds().width >= target->getSize().x)
            player.setPosition(target->getSize().x - player.getGlobalBounds().width, player.getGlobalBounds().top);
        //Top
        if(player.getGlobalBounds().top <= 0.f)
            player.setPosition(player.getGlobalBounds().left, 0.f);
        //Bottom
        else if(player.getGlobalBounds().top + player.getGlobalBounds().height >= target->getSize().y)
            player.setPosition(player.getGlobalBounds().left, target->getSize().y - player.getGlobalBounds().height);
}




void CollisionManager::handleEnemyCollisions(sf::Sprite &player, std::vector<sf::Sprite> &enemies, CameraManager& cameraManager) {

    for (auto &enemy : enemies) {

        if (checkCollision(player.getGlobalBounds(), enemy.getGlobalBounds())) {
            // Implementa la logica di gestione delle collisioni con i nemici
            cameraManager.ShakeCamera(0.5f);
        }
    }
}

void CollisionManager::handlePlatformCollisions(sf::Sprite &player, const std::vector<sf::FloatRect>& platformBounds) {
    sf::FloatRect playerBounds = player.getGlobalBounds();

    for (const auto &platform : platformBounds) {
        if (playerBounds.intersects(platform)) {
            // Imposta la posizione del giocatore in modo che sia sopra la piattaforma
            // Mantieni la stessa coordinata y ma fai in modo che il giocatore sia sopra la piattaforma
            player.setPosition(sf::Vector2f(player.getPosition().x, platform.top - playerBounds.height));
        }
    }
}



void CollisionManager::handlePowerUpCollisions(sf::Sprite &player, std::vector<sf::Sprite> &powerUps) {
    for (auto &powerUp : powerUps) {
        if (checkCollision(player.getGlobalBounds(), powerUp.getGlobalBounds())) {
            // Implementa la logica di gestione delle collisioni con i power-up
        }
    }
}
*/
