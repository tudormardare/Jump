//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_GAME_H
#define JUMPER_GAME_H


#define PLAYING_BUTTON_PATH "PNG/PlayingButton/PlayingButton.png"
#define PLAYING_BUTTON_WIDTH 200
#define PLAYING_BUTTON_HEIGHT 50
#define PLAYING_BUTTON_DISTANCE 100
#define PLAYING_BUTTON_NUMBER 4
#define PLATING_MENU_BACKGROUND_PATH "PNG/Background/background.png"

#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "../GUI/MenuButton.h"
#include "SFML/Graphics.hpp"
#include "iostream"

class PlayingState : public GameState {
public:
    static PlayingState &GetInstance(sf::RenderWindow &window);

    void handleEvents(sf::RenderWindow &window, const sf::Event &event) override;

    void update(sf::RenderWindow &window) override;

    void render(sf::RenderWindow &window) override;

    GameState *changeState(sf::RenderWindow &window) override;

    PlayingState(const PlayingState &) = delete;

    void operator=(PlayingState const &) = delete;

    std::string getBackgroundPath() const override;

private:
    PlayingState(sf::RenderWindow &window){
        initButtons();
    };

    void initButtons();

    const std::string backgroundPath = PLATING_MENU_BACKGROUND_PATH;
    bool changeStateToNext = false;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[PLAYING_BUTTON_NUMBER];

};


#endif //JUMPER_GAME_H
