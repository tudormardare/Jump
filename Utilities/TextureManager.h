//
// Created by tudor on 04/10/2023.
//

#ifndef JUMP_TEXTUREMANAGER_H
#define JUMP_TEXTUREMANAGER_H


#include <map>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

struct AnimationData {
    std::vector<sf::Texture> frames;
};

struct AnimationInfo {
    AnimationData animationData;
    float minFrameDuration{};
    float maxFrameDuration{};
};

class TextureManager {
public:
    TextureManager();

    void loadEntityTextures(const std::string& entityName, const std::map<std::string, std::pair<std::string, int>>& animations);
    void setAnimationDurations(const std::string& entityName, const std::string& animationType, float minDuration, float maxDuration);
    [[nodiscard]] const sf::Texture& getTexture(const std::string& entity, const std::string& animationType, int frameIndex) const;
    [[nodiscard]] std::pair<float, float> getAnimationDurations(const std::string& entity, const std::string& animationType) const;

private:
    std::map<std::string, std::map<std::string, AnimationInfo>> textures;
};

#endif // TEXTUREMANAGER_H
