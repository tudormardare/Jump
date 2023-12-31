//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_GAME_H
#define JUMPER_GAME_H


#define PLAYING_BUTTON_PATH "PNG/MenuButton/BackButton.png"
#define PLAYING_BUTTON_WIDTH 200
#define PLAYING_BUTTON_HEIGHT 450
#define PLAYING_BUTTON_DISTANCE 100
#define PLAYING_BUTTON_NUMBER 1
#define PLAYING_MENU_BACKGROUND_PATH "PNG/KeybindingsGuide/Keybindings.png"

#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "../GUI/MenuButton.h"
#include "SFML/Graphics.hpp"
#include "iostream"

class SettingsState : public GameState {
public:
    static SettingsState &GetInstance(sf::RenderWindow &window);

    void handleEvents(sf::RenderWindow &window, const sf::Event &event) override;

    void update(sf::RenderWindow &window, float deltaTime) override;

    void render(sf::RenderWindow &window) override;

    GameState *changeState(sf::RenderWindow &window) override;

    SettingsState(const SettingsState &) = delete;

    void operator=(SettingsState const &) = delete;

    std::string getBackgroundPath() const override;

private:
    SettingsState(sf::RenderWindow &window){
        initState();
    };

    void initState();

    const std::string backgroundPath = PLAYING_MENU_BACKGROUND_PATH;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    bool changeStateToNext = false;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[PLAYING_BUTTON_NUMBER];

};


#endif //JUMPER_GAME_H
