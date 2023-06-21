//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_MAINMENU_H
#define JUMPER_MAINMENU_H

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_DISTANCE 100
#define BUTTONS_NUMBER 3
#define BUTTONS_STARTING_X 200
#define BUTTONS_STARTING_Y 200
#define MENU_BUTTONS_PATH "../PNG/Button.png"

#include "GameState.h"
#include "PauseState.h"
#include "PlayingState.h"
#include "SFML/Graphics.hpp"
#include "../GUI/MenuButton.h"

class MenuState: public GameState{
public:

    static MenuState& GetInstance(sf::RenderWindow &window);
    void handleEvents(sf::RenderWindow& window, const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    GameState* changeState() override;
    MenuState(const MenuState&) = delete;
    void operator=(MenuState const&) = delete;
private:
    MenuState(sf::RenderWindow &window): window(window){
        if (!buttonTexture.loadFromFile(MENU_BUTTONS_PATH)){
            std::cout << "Errore durante il caricamento della texture del pulsante." << std::endl;
        }
        sf::Vector2f size(BUTTON_WIDTH, BUTTON_HEIGHT);
        sf::Vector2f startingPosition(BUTTONS_STARTING_X, BUTTONS_STARTING_Y);

        buttons[0] = std::make_unique<MenuButton>(size,startingPosition, buttonTexture);
        buttons[1] = std::make_unique<MenuButton>(size, startingPosition + sf::Vector2f(0, BUTTON_DISTANCE), buttonTexture);
        buttons[2] = std::make_unique<MenuButton>(size, startingPosition + sf::Vector2f(0, 2*BUTTON_DISTANCE), buttonTexture);
    };


    bool changeStateToNext = false;
    sf::RenderWindow& window;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[BUTTONS_NUMBER];

};


#endif //JUMPER_MAINMENU_H
