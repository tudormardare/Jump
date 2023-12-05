//
// Created by Denis Jaupi on 23/11/23.
//
#include <SFML/Graphics.hpp>
#include "gtest/gtest.h"
#include "../GUI/Map.h"

TEST(Map, getBitMask){
Map map;
map.initBitMask();
std::vector<bool> bitmask = map.getBitMask();

EXPECT_EQ(bitmask.size(), 358400);
}