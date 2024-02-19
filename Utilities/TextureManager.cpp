//
// Created by tudor on 04/10/2023.
//
#include "TextureManager.h"


TextureManager::TextureManager() = default;

void TextureManager::loadEntityTextures(const std::string& entityName, const std::map<std::string, AnimationConfig>& animations, int entityNum) {
    for (const auto& [animationType, config] : animations) {
        AnimationData data;
        for (int i = 0; i < config.frameCount; ++i) {
            sf::Texture texture;
            std::string fullPath = config.texturePath + std::to_string(i) + ".png";
            if (!texture.loadFromFile(fullPath)) {
                std::cerr << "Error loading texture from file: " << fullPath << std::endl;
                continue;
            }
            data.frames.push_back(std::move(texture));
        }

        AnimationInfo info;
        info.animationData = std::move(data);
        info.minFrameDuration = config.minFrameDuration;
        info.maxFrameDuration = config.maxFrameDuration;
        info.dynamicFrameCount = config.isDynamic;
        // currentFrame e animationTimer sono già inizializzati a

        if(entityNum > 1){
            for (int i = 0; i < entityNum; i++) {
                textures[entityName + std::to_string(i + 1)][animationType] = info;
            }
        }else{
            textures[entityName][animationType] = std::move(info);
        }
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

const sf::Texture &
TextureManager::getTexture(const std::string& entity, const std::string& animationType, int frameIndex) {
    resetAnimation(entity, animationType);
    return textures.at(entity).at(animationType).animationData.frames.at(frameIndex);
}

void TextureManager::updateAnimation(const std::string &entityName, const std::string &animationType, float deltaTime, Entity *entity) {
    AnimationInfo& animInfo = textures[entityName][animationType];
    animInfo.animationTimer += deltaTime;
    auto frameCount = (float) animInfo.animationData.frames.size();
    float frameDuration = animInfo.minFrameDuration /  frameCount;
    float entitySpeed = entity->getVelocity().x;

    // Calcola la durata del frame in base alla velocità
    if(animInfo.dynamicFrameCount) {
        if( entitySpeed < 0) {
            entitySpeed = -entitySpeed;
        }
        frameDuration = (animInfo.minFrameDuration - ( entitySpeed / entity->getMaxSpeed().x) * (animInfo.minFrameDuration - animInfo.maxFrameDuration)) /frameCount;
        if(frameDuration < animInfo.maxFrameDuration / (float) frameCount) {
            frameDuration = animInfo.maxFrameDuration / (float) frameCount ;
        }
    }

    if (animInfo.animationTimer >= frameDuration) {
        animInfo.animationTimer -= frameDuration;
        int newFrame = (animInfo.currentFrame + 1) % static_cast<int>(frameCount);

        // Imposta la texture solo se il frame è cambiato
        if (newFrame != animInfo.currentFrame) {
            animInfo.currentFrame = newFrame;
            entity->setTexture(animInfo.animationData.frames[animInfo.currentFrame]);
        }

        //Vecchia implementazione
        //animInfo.currentFrame = ++animInfo.currentFrame % (int) frameCount;
        //entity.setTexture(animInfo.animationData.frames[animInfo.currentFrame]);
    }
}


void TextureManager::setSpecificFrame(const std::string &entityName, const std::string &animationType, int frameIndex, Entity &entity) {
    AnimationInfo& animInfo = textures[entityName][animationType];
    animInfo.currentFrame = frameIndex;
    entity.setTexture(animInfo.animationData.frames[animInfo.currentFrame]);
}

int TextureManager::getCurrentIndex(const std::string &entityName, const std::string &animationType) {
    return textures.at(entityName).at(animationType).currentFrame;
}

void TextureManager::resetAnimation(const std::string &entityName, const std::string &animationType) {
        // Verifica se l'entità esiste nella mappa
        auto entityIt = textures.find(entityName);
        if (entityIt != textures.end()) {
            // Itera su tutte le animazioni dell'entità
            auto& animations = entityIt->second;
            for (auto& animationPair : animations) {
                // Resetta l'animazione se currentFrame è diverso da
                AnimationInfo& animationInfo = animationPair.second;
                if (animationInfo.currentFrame != 0) {
                    animationInfo.currentFrame = 0;
                    animationInfo.animationTimer = 0.0f;
                }
            }
        }
    }

void TextureManager::loadTexturesFromSpriteSheetWithLineNumber(const std::string &entityName,
                                                               const std::string &spriteSheetPath,
                                                               const std::map<std::string, AnimationConfig> &animations,
                                                               int frameWidth, int frameHeight, int entityNum,
                                                               int rows) {

    sf::Texture spriteSheet;
    if (!spriteSheet.loadFromFile(spriteSheetPath)) {
        std::cerr << "Error loading sprite sheet from file: " << spriteSheetPath << std::endl;
        return;
    }

    for (const auto& [animationName, details] : animations) {
        const auto frameCount = details.frameCount;
        AnimationData newAnimationData;

        for (int i = 0; i < frameCount; i++) {
            sf::IntRect frameRect(i * frameWidth, rows * frameHeight, frameWidth, frameHeight);
            sf::Texture texture;
            texture.loadFromImage(spriteSheet.copyToImage(), frameRect);
            newAnimationData.frames.push_back(std::move(texture));
        }

        AnimationInfo info;
        info.animationData = std::move(newAnimationData);
        info.minFrameDuration = details.minFrameDuration;
        info.maxFrameDuration = details.maxFrameDuration;
        info.dynamicFrameCount = details.isDynamic;

        if(entityNum > 1){
            for (int i = 0; i < entityNum; i++) {
                textures[entityName + std::to_string(i + 1)][animationName] = info;
            }
        }else{
            textures[entityName][animationName] = std::move(info);
        }
    }

}



