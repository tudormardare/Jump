//
// Created by tudor on 04/10/2023.
//

#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager() = default;

void TextureManager::loadEntityTextures(const std::string& entityName, const std::map<std::string, std::pair<std::string, int>>& animations) {
    for (const auto& [animationName, animationData] : animations) {
        const auto& [path, count] = animationData;
        AnimationData newAnimationData;

        for (int i = 0; i < count; i++) {
            sf::Texture texture;
            std::string fullPath = path + std::to_string(i) + ".png";
            if (!texture.loadFromFile(fullPath)) {
                std::cerr << "Error loading texture from file: " << fullPath << std::endl;
            } else {
                newAnimationData.frames.push_back(std::move(texture));
            }
        }

        textures[entityName][animationName].animationData = std::move(newAnimationData);
    }
}

void TextureManager::loadTexturesFromSpriteSheetWithLineNumber(const std::string& entityName, const std::string& spriteSheetPath, const std::map<std::string, std::pair<int, int>>& animationDetails, int frameWidth, int frameHeight) {
    sf::Texture spriteSheet;
    if (!spriteSheet.loadFromFile(spriteSheetPath)) {
        std::cerr << "Error loading sprite sheet from file: " << spriteSheetPath << std::endl;
        return;
    }

    for (const auto& [animationName, details] : animationDetails) {
        const auto [frameCount, row] = details;
        AnimationData newAnimationData;

        for (int i = 0; i < frameCount; i++) {
            sf::IntRect frameRect(i * frameWidth, row * frameHeight, frameWidth, frameHeight);
            sf::Texture texture;
            texture.loadFromImage(spriteSheet.copyToImage(), frameRect);
            newAnimationData.frames.push_back(std::move(texture));
        }

        AnimationInfo animInfo;
        animInfo.animationData = std::move(newAnimationData);

        textures[entityName][animationName] = std::move(animInfo);
    }
}
void TextureManager::loadTexturesFromSpriteSheetRegular(const std::string& entityName, const std::string& spriteSheetPath, const std::map<std::string, std::tuple<int, int, int>>& animationDetails, int frameWidth, int frameHeight) {
    sf::Texture spriteSheet;
    if (!spriteSheet.loadFromFile(spriteSheetPath)) {
        std::cerr << "Error loading sprite sheet from file: " << spriteSheetPath << std::endl;
        return;
    }

    for (const auto& [animationName, details] : animationDetails) {
        const auto [startRow, frameCount, framesPerRow] = details;
        AnimationData newAnimationData;

        for (int i = 0; i < frameCount; i++) {
            int x = (i % framesPerRow) * frameWidth;
            int y = (startRow + i / framesPerRow) * frameHeight;
            sf::IntRect frameRect(x, y, frameWidth, frameHeight);
            sf::Texture texture;
            texture.loadFromImage(spriteSheet.copyToImage(), frameRect);
            newAnimationData.frames.push_back(std::move(texture));
        }

        AnimationInfo animInfo;
        animInfo.animationData = std::move(newAnimationData);

        textures[entityName][animationName] = std::move(animInfo);
    }
}




void TextureManager::setAnimationDurations(const std::string& entityName, const std::string& animationType, float minDuration, float maxDuration) {
    textures[entityName][animationType].minFrameDuration = minDuration;
    textures[entityName][animationType].maxFrameDuration = maxDuration;
}

const sf::Texture& TextureManager::getTexture(const std::string& entity, const std::string& animationType, int frameIndex) const {
    return textures.at(entity).at(animationType).animationData.frames.at(frameIndex);
}

std::pair<float, float> TextureManager::getAnimationDurations(const std::string& entity, const std::string& animationType) const {
    const auto& animationInfo = textures.at(entity).at(animationType);
    return {animationInfo.minFrameDuration, animationInfo.maxFrameDuration};
}
