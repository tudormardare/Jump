//
// Created by tudor on 20/06/2023.
//

#ifndef JUMP_MENUBUTTON_H
#define JUMP_MENUBUTTON_H


#include <SFML/Graphics.hpp>

class MenuButton {
public:
    MenuButton(sf::Vector2f size, sf::Vector2f position, const sf::Texture &texture);

    bool isClicked(sf::RenderWindow &window);
    void setTexture(const sf::Texture &texture);
    void draw(sf::RenderWindow &window);
    bool isMouseOver(sf::Vector2<int> mousePosition);
    void update(sf::RenderWindow &window);
    void setPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds();

private:
    sf::Sprite button;
    std::shared_ptr<sf::Texture> buttonTexture;
};



#endif //JUMP_MENUBUTTON_H
