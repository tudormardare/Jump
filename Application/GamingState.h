//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_SETTINGSMENU_H
#define JUMPER_SETTINGSMENU_H


#include <SFML/Graphics/Texture.hpp>
#include <valarray>
#include <iostream>
#include "GameState.h"
#include "MenuState.h"
#include "../Controllers/CollisionManager.h"
#include "../GUI/Player.h"
#include "../Utilities/PhysicsSystem.h"
#include "../Utilities/TextureManager.h"
#include "../GUI/Fire.h"
#include "../GUI/Pumpkin.h"
#include "../GUI/Map.h"
#include "../GUI/Timer.h"
#include "../GUI/MenuButton.h"

#define GAME_BACKGROUND_PATH "PNG/Background/background.png"
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 675

// Dimensioni e posizioni dei pulsanti del menu
#define PAUSE_BUTTON_WIDTH 200
#define PAUSE_BUTTON_HEIGHT 75
#define PAUSE_BUTTON_DISTANCE 50
#define PAUSE_BUTTONS_NUMBER 3

// Percorsi delle texture dei pulsanti del menu
#define PAUSE_RESUME_BUTTON_PATH "PNG/MenuButton/GuideButton.png"
#define PAUSE_QUIT_BUTTON_PATH "PNG/MenuButton/PlayButton.png"


class GamingState : public GameState {


public:
    const float JUMP_FORCE = 5000.f;

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

    void handleFireBallsMovements(float deltaTime);

    void adjustAccelerationForDirectionChange(float accelerationRate, float deltaTime);

    bool deceleratePlayer(float deltaTime);

    static void clampPlayerVelocity(sf::Vector2f &velocity);

    void handleAnimations(float deltaTime);

    void handleFireBallsAnimations(float deltaTime);

    void setTextureForFire();

    void handleCollisions();

    void setTextureForPlayer();

    void loadAllTextures();

    void handleMovements(float deltaTime);

    //attributi relativi al gioco
    bool paused = false;
    TextureManager textureManager;
    Player player;
    Fire fire;
    Pumpkin pumpkin;
	Map gameMap;
    CollisionManager collisionManager;
    Timer gameTimer;
    std::vector<std::unique_ptr<MenuButton>> pauseButtons;


    void initPauseButtons();


    void handlePlayerJump(bool isKeyPressedW, float deltaTime);

    void clampPlayerYVelocity(sf::Vector2f &velocity);

    void handleCollisionMap(CollisionManager::CollisionDirection direction);
};


#endif //JUMPER_SETTINGSMENU_H
