//
// Created by tudor on 27/06/2023.
//
#include "gtest/gtest.h"
#include "../GUI/MenuButton.h"

TEST(BackgroundTest, menuBackground){
#include <SFML/Graphics.hpp>
        sf::RenderWindow window(sf::VideoMode(800, 600), "Finestra con sfondo");

        sf::Texture texture;
        if (!texture.loadFromFile("PNG/Background/background.png")) {
            // gestisci l'errore se non viene caricata
        }

        sf::Sprite sprite;
        sprite.setTexture(texture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            window.draw(sprite);
            window.display();
        }
    EXPECT_EQ(texture.getSize().x, 288);
}