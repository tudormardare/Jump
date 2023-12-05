//
// Created by tudor on 22/11/2023.
//

#ifndef JUMP_PUMPKIN_H
#define JUMP_PUMPKIN_H


#include "Entity.h"

#define PUMPKIN_TEXTURE_PATH "PNG/Pumpkin/Pumpkin_1_"
#define PUMPKIN_SCALE 1.f
#define PUMPKIN_TEXTURES 1
#define PUMPKIN_MIN_FRAME_DURATION 1.f
#define PUMPKIN_MAX_FRAME_DURATION 1.f


class Pumpkin: public Entity{
private:
    sf::IntRect getCustomCollisionRect() const {
        sf::Image image = sprite.getTexture()->copyToImage();
        int left = image.getSize().x, top = image.getSize().y, right = 0, bottom = 0;

        for (unsigned int x = 0; x < image.getSize().x; ++x) {
            for (unsigned int y = 0; y < image.getSize().y; ++y) {
                if (image.getPixel(x, y).a != 0) { // Pixel non trasparente
                    left = std::min(left, static_cast<int>(x));
                    top = std::min(top, static_cast<int>(y));
                    right = std::max(right, static_cast<int>(x));
                    bottom = std::max(bottom, static_cast<int>(y));
                }
            }
        }

        if (left > right || top > bottom) {
            return sf::IntRect(); // Nessuna area non trasparente trovata.
        }
        return sf::IntRect(left, top, right - left + 1, bottom - top + 1);
    }
public:
    Pumpkin();

    void move(float offsetX, float offsetY) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    void setTexture(const sf::Texture &texture) override;

    sf::FloatRect getGlobalBoundsCustom() const {
        sf::IntRect localBounds = getCustomCollisionRect();
        sf::Transform transform = sprite.getTransform();
        return transform.transformRect(static_cast<sf::FloatRect>(localBounds));
    }
};


#endif //JUMP_PUMPKIN_H
