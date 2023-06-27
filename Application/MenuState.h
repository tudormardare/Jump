//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_MAINMENU_H
#define JUMPER_MAINMENU_H

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 675
#define MENU_BUTTON_WIDTH 200
#define MENU_BUTTON_HEIGHT 75
#define MENU_BUTTON_DISTANCE 100
#define MENU_BUTTONS_NUMBER 3
#define MENU_BUTTONS_PATH "PNG/MenuButton/Button.png"


#define MENU_BACKGROUND_PATH "PNG/Background/background.png"

#include "GameState.h"
#include "PauseState.h"
#include "PlayingState.h"
#include "SFML/Graphics.hpp"
#include "../GUI/MenuButton.h"
#include "iostream"

class MenuState : public GameState {
public:

    static MenuState &GetInstance(sf::RenderWindow &window);

    void handleEvents(sf::RenderWindow &window, const sf::Event &event) override;

    void update() override;

    void render(sf::RenderWindow &window) override;

    GameState *changeState() override;

    MenuState(const MenuState &) = delete;

    void operator=(MenuState const &) = delete;

    std::string getBackgroundPath() const override;

private:
    MenuState(sf::RenderWindow &window) : window(window) {
        initButtons();
    };

    void initButtons();

    const std::string backgroundPath = MENU_BACKGROUND_PATH;
    bool changeStateToNext = false;
    sf::RenderWindow &window;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[MENU_BUTTONS_NUMBER];

};


#endif //JUMPER_MAINMENU_H
