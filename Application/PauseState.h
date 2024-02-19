//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_PAUSEMENU_H
#define JUMPER_PAUSEMENU_H


#include "GameState.h"
#include "MenuState.h"
#include "../GUI/MenuButton.h"
#include "SFML/Graphics.hpp"
#include "../Utilities/constants.h"

class PauseState : public GameState {
public:

    static PauseState &GetInstance(sf::RenderWindow &window);

    void handleEvents(sf::RenderWindow &window, const sf::Event &event) override;

    void update(sf::RenderWindow &window, float deltaTime) override;

    void render(sf::RenderWindow &window) override;

    GameState *changeState(sf::RenderWindow &window) override;

    PauseState(const PauseState &) = delete;

    void operator=(PauseState const &) = delete;

    std::string getBackgroundPath() const override;


private:
    PauseState(sf::RenderWindow &window){
        initState();
    };

    void initState();

    const std::string backgroundPath = PAUSE_MENU_BACKGROUND_PATH;
    bool changeStateToNext = false;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[PAUSE_BUTTONS_NUMBER];
};


#endif //JUMPER_PAUSEMENU_H
