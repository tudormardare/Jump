#include "Map.h"

Map::Map() {

    loadTexture(GAME_FOREGROUND_PATH);
    sprite.setTexture(texture);
    size = texture.getSize();
    initBitMask();
    loadHitboxesFromFile();

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

void Map::initBitMask() {

    sf::Image image = sprite.getTexture()->copyToImage();
    std::vector mask(image.getSize().x * image.getSize().y, false);

    for (unsigned int x = 0; x < image.getSize().x; x++) {
        for (unsigned int y = 0; y < image.getSize().y; y++) {
            mask[x + y * image.getSize().x] = image.getPixel(x, y).a != 0;
        }
    }
    bitMask = mask;
}

std::vector<bool> Map::getBitMask() {
    std::ofstream file("filename.txt");
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file " << "filename.txt" << std::endl;
        return std::vector<bool>();
    }

    unsigned int width = size.x; // Assumiamo che size sia un sf::Vector2u con le dimensioni della mappa
    unsigned int height = size.y;

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            file << (bitMask[x + y * width] ? "1" : "0");
        }
        file << '\n'; // Vai a capo alla fine di ogni riga
    }

    file.close(); // Chiudi il file dopo aver finito

    return bitMask;
}

sf::Vector2u Map::getSize() const {
    return size;
}

void Map::loadHitboxesFromFile() {
    std::ifstream file("hitbox/MapHitboxes.json");
    nlohmann::json hitboxData;
    file >> hitboxData;
    float scaleX = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(texture.getSize().x);
    float scaleY = static_cast<float>(WINDOW_HEIGHT) / static_cast<float>(texture.getSize().y);

    for (const auto& hitbox : hitboxData["hitboxes"]) {
        float x = (float) hitbox["x"]  * scaleX;
        float y = (float) hitbox["y"] * scaleY;
        float width =  (float)hitbox["width"] * scaleX;
        float height = (float) hitbox["height"] * scaleY;
        mapHitboxes.push_back(sf::FloatRect(x, y, width, height));
    }
}

std::vector<sf::FloatRect> Map::getMapHitboxes() const {
    return mapHitboxes;
}
