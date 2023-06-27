//
// Created by tudor on 20/06/2023.
//

#include <iostream>
#include "MenuButton.h"

MenuButton::MenuButton(sf::Vector2f size, sf::Vector2f position, sf::Texture &texture) {
    texture.setSmooth(true);
    button.setPosition(position);
    button.setTexture(texture, true);

    float scaleX = size.x / button.getGlobalBounds().width;
    float scaleY = size.y /button.getGlobalBounds().height;

    float scale = std::min(scaleX, scaleY);
    button.setScale(scale, scale);
    button.setOrigin((float)button.getTextureRect().width / 2, (float)button.getTextureRect().height / 2 );
    button.setPosition(position);

}

bool MenuButton::isClicked(sf::RenderWindow &window) {
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    if (button.getGlobalBounds().contains(mousePosition))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return true;
        }
    }
    return false;
}

void MenuButton::draw(sf::RenderWindow &window) {
    window.draw(button);
}

bool MenuButton::isMouseOver(sf::Vector2<int> mousePosition) {
    return false;
}

void MenuButton::update(sf::RenderWindow &window) {

}

void MenuButton::setPosition(sf::Vector2f position) {
    button.setPosition(position);
}

sf::FloatRect MenuButton::getGlobalBounds() {
    return button.getGlobalBounds();
}
