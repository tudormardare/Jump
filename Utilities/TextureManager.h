//
// Created by tudor on 04/10/2023.
//

#ifndef JUMP_TEXTUREMANAGER_H
#define JUMP_TEXTUREMANAGER_H


#include <map>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "../GUI/Entity.h"

struct AnimationData {
    std::vector<sf::Texture> frames;
};

struct AnimationInfo {
    AnimationData animationData;
    float minFrameDuration{};
    float maxFrameDuration{};
    int currentFrame = 0;
    float animationTimer = 0.0f;
    bool dynamicFrameCount = false;
};

struct AnimationConfig {
    std::string texturePath;
    int frameCount;
    float minFrameDuration;
    float maxFrameDuration;
    bool isDynamic;
};


class TextureManager {
public:
    TextureManager();

    void loadEntityTextures(const std::string& entityName, const std::map<std::string, AnimationConfig>& animations);
    void loadTexturesFromSpriteSheetWithLineNumber(const std::string& entityName, const std::string& spriteSheetPath, const std::map<std::string, std::pair<int, int>>& animationDetails, int frameWidth, int frameHeight);
    void loadTexturesFromSpriteSheetRegular(const std::string& entityName, const std::string& spriteSheetPath, const std::map<std::string, std::tuple<int, int, int>>& animationDetails, int frameWidth, int frameHeight);
    [[nodiscard]] const sf::Texture& getTexture(const std::string& entity, const std::string& animationType, int frameIndex) const;
    void updateAnimation(const std::string& entityName, const std::string& animationType, float deltaTime, Entity& entity);

private:
    std::map<std::string, std::map<std::string, AnimationInfo>> textures;
};

#endif // TEXTUREMANAGER_H
