#include "Map.h"

Map::Map() {

    loadTexture(GAME_FOREGROUND_PATH);
    sprite.setTexture(texture);
    size = texture.getSize();
    createPlatformBounds();

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

void Map::createPlatformBounds() {
    sf::Image image = texture.copyToImage();

    for (unsigned int y = 0; y < size.y; ++y) {
        for (unsigned int x = 0; x < size.x; ++x) {
            sf::Color pixelColor = image.getPixel(x, y);

            if (pixelColor == PLATFORM_COLOR) {
                // Trova la larghezza e l'altezza effettive della piattaforma
                unsigned int width = 1;
                unsigned int height = 1;

                // Espandi la larghezza
                while (x + width < size.x && texture.copyToImage().getPixel(x + width, y) == PLATFORM_COLOR)
                    width++;

                // Espandi l'altezza
                while (y + height < size.y && texture.copyToImage().getPixel(x, y + height) == PLATFORM_COLOR)
                    height++;

                // Crea una bounding box basata sulle dimensioni trovate
                platformBounds.emplace_back(x * 32.f, y * 32.f, width * 32.f, height * 32.f);

                // Salta i pixel già inclusi nella bounding box
                x += width - 1;
            }
        }
    }
}


void Map::render(sf::RenderWindow &window) {
    applyScale();
    drawSprite(window);
}