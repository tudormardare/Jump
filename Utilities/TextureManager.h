//
// Created by tudor on 04/10/2023.
//

#ifndef JUMP_TEXTUREMANAGER_H
#define JUMP_TEXTUREMANAGER_H


#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

class TextureManager {
public:
    TextureManager();

    // Carica tutte le texture necessarie per un'entità
    void loadEntityTextures(const std::string& entityName, const std::map<std::string, std::pair<std::string, int>>& animations);

    // Ottieni una texture specifica
     [[nodiscard]] const sf::Texture& getTexture(const std::string& entity, const std::string& type, int index) const;

private:
    // Mappa nidificata per contenere le texture
    std::map<std::string, std::map<std::string, std::vector<sf::Texture>>> textures;
};

#endif //JUMP_TEXTUREMANAGER_H
