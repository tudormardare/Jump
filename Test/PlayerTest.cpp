//
// Created by Denis Jaupi on 22/06/23.
//

#include "lib/googletest/include/gtest/gtest.h"
#include "../GUI/Player.h"
#include "SFML/Graphics.hpp"

TEST(Player, move){
    Player p;
    p.setPosition(sf::Vector2f(0,0));
    p.move(5, 5);
    EXPECT_EQ(p.getPosition().x, 5);
}