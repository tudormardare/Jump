//
// Created by tudor on 04/10/2023.
//

#include <iostream>
#include "TextureManager.h"

TextureManager::TextureManager() {
    // Qui puoi eventualmente pre-caricare alcune texture se necessario
}

void TextureManager::loadEntityTextures(const std::string& entityName, const std::map<std::string, std::pair<std::string, int>>& animations) {
    for (const auto& [animationName, animationData] : animations) {
        const auto& [path, count] = animationData;
        for (int i = 0; i < count; i++) {
            sf::Texture texture;
            std::string fullPath = path + std::to_string(i) + ".png";
            if (!texture.loadFromFile(fullPath)) {
                std::cerr << "Error loading texture from file: " << fullPath << std::endl;
            } else {
                textures[entityName][animationName].push_back(texture);
            }
        }
    }
}

const sf::Texture& TextureManager::getTexture(const std::string& entity, const std::string& type, int index) const {
    return textures.at(entity).at(type).at(index);
}