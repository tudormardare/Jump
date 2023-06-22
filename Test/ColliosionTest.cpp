//
// Created by tudor on 22/06/2023.
//
#include <SFML/Graphics.hpp>
#include "gtest/gtest.h"
#include "../Controllers/CollisionManager.h"

TEST(CollisionManager, checkCollision){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture texture;
    texture.loadFromFile("PNG/Player/Player.png");
    s1.setTexture(texture);
    s2.setTexture(texture);
    s1.setPosition(0,0);
    s2.setPosition(0,10);
    EXPECT_EQ(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()), true);
};

TEST(CollisionManager, checkCollision2){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture texture;
    texture.loadFromFile("PNG/Player/Player.png");
    s1.setTexture(texture);
    s2.setTexture(texture);
    s1.setPosition(0,0);
    s2.setPosition(0,200);
    EXPECT_EQ(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()), false);
}