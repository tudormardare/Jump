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
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision2){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture texture;
    texture.loadFromFile("PNG/Player/Player.png");
    s1.setTexture(texture);
    s2.setTexture(texture);
    s1.setPosition(0,0);
    s2.setPosition(0,200);
    EXPECT_FALSE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision3){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(48,112);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision4){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(48+77,112-16);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision5){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(0,399);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision6){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(17,244);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision7){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(48,288);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision8){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(145,160);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision9){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(176,256);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}

TEST(CollisionManager, checkCollision10){
    sf::Sprite s1;
    sf::Sprite s2;
    sf::Texture playerTexture;
    sf::Texture mapTexture;
    playerTexture.loadFromFile("PNG/Player/Player.png");
    mapTexture.loadFromFile("PNG/Map-platforms/Map.png");
    s1.setTexture(playerTexture);
    s2.setTexture(mapTexture);
    s1.setPosition(305,208);
    s2.setPosition(0,0);
    EXPECT_TRUE(CollisionManager::checkCollision(s1.getGlobalBounds(),s2.getGlobalBounds()));
}


