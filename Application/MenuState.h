//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_MAINMENU_H
#define JUMPER_MAINMENU_H



#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "../GUI/MenuButton.h"
#include "../GUI/Timer.h"
#include "PauseState.h"
#include "SettingsState.h"
#include "GamingState.h"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Graphics.hpp"
#include "../Utilities/constants.h"

class MenuState : public GameState {
public:
    static MenuState &GetInstance(sf::RenderWindow &window);

    void handleEvents(sf::RenderWindow &window, const sf::Event &event) override;
    void update(sf::RenderWindow &window, float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    GameState *changeState(sf::RenderWindow &window) override;

    std::string getBackgroundPath() const override;

private:
    MenuState(sf::RenderWindow &window);

    void initState();

private:
    const std::string backgroundPath = MENU_BACKGROUND_PATH;
    bool changeStateToNext = false;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[MENU_BUTTONS_NUMBER];
    Timer gameTimer;
};

#endif //JUMPER_MAINMENU_H
