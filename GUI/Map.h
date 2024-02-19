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
#include <fstream>
#include "../Utilities/json.hpp"
#include "../Utilities/constants.h"




class Map{

private:

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2u size;
    std::vector<bool> bitMask;

    std::vector<sf::FloatRect> mapHitboxes;
public:
    std::vector<sf::FloatRect> getMapHitboxes() const;


public:

    Map();


    void loadTexture(const std::string& filePath);

    void loadHitboxesFromFile();

    void applyScale();

    void drawSprite(sf::RenderWindow& window);

    void initBitMask();

    std::vector<bool> getBitMask();


    sf::Vector2u getSize() const;

    void render(sf::RenderWindow& window);

};




#endif //JUMP_MAP_H
