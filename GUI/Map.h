//
// Created by Denis Jaupi on 26/09/23.
//

#ifndef JUMP_MAP_H
#define JUMP_MAP_H


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "../Controllers/CollisionManager.h"
#include <iostream>
#include <queue>
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 675
#define GAME_FOREGROUND_PATH "PNG/Map-platforms/Map.png"



class Map{

private:

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2u size;
    std::vector<sf::FloatRect> platformBounds;


public:

    Map();


    void loadTexture(const std::string& filePath);

    void applyScale();

    void drawSprite(sf::RenderWindow& window);



    void render(sf::RenderWindow& window);

};




#endif //JUMP_MAP_H
