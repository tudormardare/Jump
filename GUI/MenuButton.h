//
// Created by tudor on 20/06/2023.
//

#ifndef JUMP_MENUBUTTON_H
#define JUMP_MENUBUTTON_H


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class MenuButton {
private:
    sf::Sprite button;

public:
    MenuButton(sf::Vector2f size, sf::Vector2f position, sf::Texture &texture);

    bool isClicked(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    bool isMouseOver(sf::Vector2<int> mousePosition);

    void update(sf::RenderWindow &window);

    void setPosition(sf::Vector2f position);

    sf::FloatRect getGlobalBounds();
};


#endif //JUMP_MENUBUTTON_H
