//
// Created by tudor on 20/06/2023.
//

#include "MenuButton.h"

MenuButton::MenuButton(sf::Vector2f size, sf::Vector2f position, sf::Texture &texture) {
    button.setTexture(texture);
    button.setPosition(position);
    button.setScale(size.x / button.getLocalBounds().width, size.y / button.getLocalBounds().height);

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
