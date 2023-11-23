#include "Map.h"

Map::Map() {

    loadTexture(GAME_FOREGROUND_PATH);
    sprite.setTexture(texture);
    size = texture.getSize();

}

void Map::loadTexture(const std::string& filePath) {

    if (!texture.loadFromFile(filePath)) {
        std::cout << "Errore: Impossibile caricare la texture dal file " << filePath << std::endl;
    }
}

void Map::applyScale() {
    float scaleX = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(texture.getSize().x);
    float scaleY = static_cast<float>(WINDOW_HEIGHT) / static_cast<float>(texture.getSize().y);
    sprite.setScale(scaleX, scaleY);
}

void Map::drawSprite(sf::RenderWindow& window) {
    window.draw(sprite);
}



void Map::render(sf::RenderWindow &window) {
    applyScale();
    drawSprite(window);
}