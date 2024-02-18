//
// Created by Denis Jaupi on 18/02/24.
//


#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"
#include "GamingState.h"
#include "MenuState.h"
#include "../GUI/MenuButton.h"
#include "../GUI/Player.h"
#include "SFML/Graphics.hpp"
#include "../GUI/Timer.h"
#include <valarray>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

#define GAMEOVER_BUTTON_PATH "PNG/MenuButton/PlayButton.png"

class GameOverState : public GameState {
public:
    static GameOverState &GetInstance(sf::RenderWindow &window);

    void initState();
    void update(sf::RenderWindow &window, float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    GameState *changeState(sf::RenderWindow &window) override;
    void handleEvents(sf::RenderWindow &window, const sf::Event &event) override;
    std::string getBackgroundPath() const override;

private:
    GameOverState(sf::RenderWindow &window);

    std::unique_ptr<MenuButton> gameOverButton;
    Player player;
    Timer gameTimer;

    void initGameOverButton();
    void handleGameOver(sf::RenderWindow &window);
};


#endif //JUMP_GAMEOVERSTATE_H
