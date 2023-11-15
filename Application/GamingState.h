//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_SETTINGSMENU_H
#define JUMPER_SETTINGSMENU_H


#include <SFML/Graphics/Texture.hpp>
#include "GameState.h"
#include "../Controllers/CollisionManager.h"
#include "../GUI/Player.h"
#include "../Utilities/PhysicsSystem.h"
#include "../Utilities/TextureManager.h"
#include "../GUI/Fire.h"

#define GAME_BACKGROUND_PATH "PNG/Background/background.png"

class GamingState : public GameState {


public:
    static GamingState &GetInstance(sf::RenderWindow &window);

    void handleEvents(sf::RenderWindow &window, const sf::Event &event) override;

    void update(sf::RenderWindow &window, float deltaTime) override;

    void render(sf::RenderWindow &window) override;

    GameState *changeState(sf::RenderWindow &window) override;

    GamingState(const GamingState &) = delete;

    void operator=(GamingState const &) = delete;

    std::string getBackgroundPath() const override;

private:
    explicit GamingState(sf::RenderWindow &window) {
        initState();
    };

    // attributi relativo allo stato
    void initState();

    const std::string backgroundPath = GAME_BACKGROUND_PATH;
    bool changeStateToNext = false;

    void handlePlayerMovements(float deltaTime);

    void handlePlayerHorizontalMovement(bool isKeyPressedA, bool isKeyPressedD, float deltaTime);

    void adjustAccelerationForDirectionChange(float accelerationRate, float deltaTime);

    bool deceleratePlayer(float deltaTime);

    static void clampPlayerVelocity(sf::Vector2f &velocity);

    void handlePlayerAnimations(float deltaTime, const std::string &animationType, int frameCount);

    void handleAnimations(float deltaTime);

    void handleFireAnimations(float deltaTime, const std::string &animationType, int frameCount);

    void setTextureForFire();

    void handleCollisions();

    void setTextureForPlayer();

    void loadAllTextures();

    void handleMovements(float deltaTime);

    //attributi relativi al gioco
    TextureManager textureManager;
    Player player;
    Fire fire;
    CollisionManager collisionManager;
    float animationTimer = 0.f;
    int currentFrame = 0;

};


#endif //JUMPER_SETTINGSMENU_H
