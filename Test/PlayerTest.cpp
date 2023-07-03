//
// Created by Denis Jaupi on 22/06/23.
//

#include "gtest/gtest.h"
#include "../GUI/Player.h"
#include "SFML/Graphics.hpp"

TEST(Player, move){
    Player p;
    p.setPosition(sf::Vector2f(5,5));
    p.move(10, 5);
    EXPECT_EQ(p.getPosition().x, 45);
}