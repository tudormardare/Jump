//
// Created by tudor on 20/06/2023.
//
#include "MenuButton.h"

MenuButton::MenuButton(sf::Vector2f size, sf::Vector2f position, const sf::Texture &texture) {
    buttonTexture = std::make_shared<sf::Texture>(texture);
    buttonTexture->setSmooth(true);

    button.setPosition(position);
    button.setTexture(*buttonTexture, true);

    float scaleX = size.x / button.getGlobalBounds().width;
    float scaleY = size.y / button.getGlobalBounds().height;

    float scale = std::min(scaleX, scaleY);
    button.setScale(scale, scale);
    button.setOrigin((float)button.getTextureRect().width / 2, (float)button.getTextureRect().height / 2);
    button.setPosition(position);
}

void MenuButton::setTexture(const sf::Texture &texture) {
    *buttonTexture = texture;
    buttonTexture->setSmooth(true);
    button.setTexture(*buttonTexture, true);
}

bool MenuButton::isClicked(sf::RenderWindow &window) {
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    if (button.getGlobalBounds().contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return true;
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
    // Aggiornamenti, se necessario
}

void MenuButton::setPosition(sf::Vector2f position) {
    button.setPosition(position);
}

sf::FloatRect MenuButton::getGlobalBounds() {
    return button.getGlobalBounds();
}
