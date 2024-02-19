//
// Created by Denis Jaupi on 23/11/23.
//
#include <SFML/Graphics.hpp>
#include "gtest/gtest.h"
#include "../GUI/Map.h"

class MapTest : public ::testing::Test {
protected:
    Map* map;

    void SetUp() override {
        map = new Map();
    }

    void TearDown() override {
        delete map;
    }
};

TEST(Map, getBitMask){
Map map;
map.initBitMask();
std::vector<bool> bitmask = map.getBitMask();

EXPECT_EQ(bitmask.size(), 358400);
}

TEST_F(MapTest, TestApplyScale) {
    // Testa l'applicazione della scala
    map->applyScale();
    sf::Vector2f scale = map->sprite.getScale();
    ASSERT_EQ(scale.x, WINDOW_WIDTH / static_cast<float>(map->getSize().x));
    ASSERT_EQ(scale.y, WINDOW_HEIGHT / static_cast<float>(map->getSize().y));
}

TEST_F(MapTest, TestInitBitMask) {
    // Testa l'inizializzazione della bitmask
    map->initBitMask();
    std::vector<bool> bitMask = map->getBitMask();
    ASSERT_FALSE(bitMask.empty());
}

TEST_F(MapTest, TestLoadHitboxesFromFile) {
    // Testa il caricamento delle hitbox da un file
    ASSERT_NO_THROW(map->loadHitboxesFromFile());
}
