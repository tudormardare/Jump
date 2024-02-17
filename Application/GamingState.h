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
#include "../Utilities/TimerClass.h"
#include "../Utilities/constants.h"
#include "../GUI/Heart.h"
#include "../GUI/Ball.h"

#define GAME_BACKGROUND_PATH "PNG/Background/background.png"
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 675

// Dimensioni e posizioni dei pulsanti del menu
#define PAUSE_BUTTON_HEIGHT 75

// Percorsi delle texture dei pulsanti del menu
#define PAUSE_RESUME_BUTTON_PATH "PNG/MenuButton/PlayButton.png"
#define PAUSE_QUIT_BUTTON_PATH "PNG/MenuButton/ExitButton.png"


class GamingState : public GameState {


public:
    const float JUMP_FORCE = 600.f;

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

    void initTimer();

    const std::string backgroundPath = GAME_BACKGROUND_PATH;
    bool changeStateToNext = false;

    void handlePlayerMovements(float deltaTime);

    void handlePlayerHorizontalMovement(bool isKeyPressedA, bool isKeyPressedD, float deltaTime);

    void handleEnemyMovements(float deltaTime);

    void adjustAccelerationForDirectionChange(float accelerationRate, float deltaTime);

    bool deceleratePlayer(float deltaTime);

    static void clampPlayerVelocity(sf::Vector2f &velocity);

    void handleAnimations(float deltaTime);

    void handleEnemyAnimations(float deltaTime);

    void setTextureForEnemy();

    void handleCollisions();

    void setTextureForPlayer();

    void loadAllTextures();

    void handleMovements(float deltaTime);

    void initHearts();

    void setTextureForHeart();

    void handleHeartSpawn(float deltaTime);

    void spawnHeart();

    sf::Time getRandomSpawnInterval();

    void handleHeartCollisions(Heart &heart);

    void updateHearts(float deltaTime);

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
    Ball fireBall;


    std::vector<Heart> hearts;
    int currentNumHearts= 0;
    sf::Clock heartSpawnTimer;

    std::unique_ptr<MenuButton> gameOverButton;

    bool gameOver = false;

    void handleGameOver(sf::RenderWindow &window);

    void initGameOverButton();

    void initPauseButtons();

    void drawPause(sf::RenderWindow &window);

    void handlePlayerJump(bool isKeyPressedW, float deltaTime);

    void clampPlayerYVelocity(sf::Vector2f &velocity);

    void handleCollisionMap(CollisionManager::CollisionResult collision);

    void drawHitboxes(const std::vector<sf::FloatRect> &hitboxes, sf::RenderWindow &window);

};



#endif //JUMPER_SETTINGSMENU_H
