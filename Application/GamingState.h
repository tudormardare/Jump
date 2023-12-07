//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_SETTINGSMENU_H
#define JUMPER_SETTINGSMENU_H


#include <SFML/Graphics/Texture.hpp>
#include "GameState.h"
#include "../Controllers/CollisionManager.h"
#include "../GUI/Player.h"
#include "../GUI/Map.h"
#include "../GUI/Timer.h"

#define GAME_BACKGROUND_PATH "PNG/Background/background.png"
#define RUNNING_FRAMES 6

class GamingState: public GameState{


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
    explicit GamingState(sf::RenderWindow &window){
        initState();
    };

    // Metodi relativo allo stato
    void initState();
    bool changeStateToNext = false;

    // Metodi relativo all'animazione
    void runningAnimation(float deltaTime);
    void stopAnimation();

    // Attributi relativi al gioco
    const std::string backgroundPath = GAME_BACKGROUND_PATH;
    Map gameMap;
    Player  player;
    CollisionManager collisionManager;
    float animationTimer = 0.f;
    int currentFrame = 0;
    Timer gameTimer;

};


#endif //JUMPER_SETTINGSMENU_H
