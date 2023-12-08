//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_MAINMENU_H
#define JUMPER_MAINMENU_H

// Dimensioni della finestra
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 675

// Dimensioni e posizioni dei pulsanti del menu
#define MENU_BUTTON_WIDTH 200
#define MENU_BUTTON_HEIGHT 75
#define MENU_BUTTON_DISTANCE 50
#define MENU_BUTTONS_NUMBER 3

// Percorsi delle texture dei pulsanti del menu
#define MENU_SETTINGS_BUTTON_PATH "PNG/MenuButton/SettingsButton.png"
#define MENU_PLAY_BUTTON_PATH "PNG/MenuButton/PlayButton.png"
#define MENU_EXIT_BUTTON_PATH "PNG/MenuButton/ExitButton.png"

// Percorso dell'immagine di sfondo del menu
#define MENU_BACKGROUND_PATH "PNG/Background/background.png"


#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "../GUI/MenuButton.h"
#include "../GUI/Timer.h"
#include "PauseState.h"
#include "SettingsState.h"
#include <iostream>

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
