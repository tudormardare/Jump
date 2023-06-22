//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_PAUSEMENU_H
#define JUMPER_PAUSEMENU_H


#define PAUSE_BUTTON_WIDTH 300
#define PAUSE_BUTTON_SCALE_Y 100
#define PAUSE_BUTTON_DISTANCE 100
#define PAUSE_BUTTONS_NUMBER 2
#define PAUSE_BUTTONS_STARTING_X 350
#define PAUSE_BUTTONS_STARTING_Y 100
#define PAUSE_BUTTONS_PATH "PNG/ButtonStart.png"


#include "GameState.h"
#include "MenuState.h"
#include "../GUI/MenuButton.h"
#include "SFML/Graphics.hpp"

class PauseState: public GameState{
public:

    static PauseState& GetInstance(sf::RenderWindow &window);
    void handleEvents(sf::RenderWindow& window,const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    GameState* changeState() override;
    PauseState(const PauseState&) = delete;
    void operator=(PauseState const&) = delete;


private:
    PauseState(sf::RenderWindow &window): window(window){
        if (!buttonTexture.loadFromFile(PAUSE_BUTTONS_PATH)){
            std::cerr << "Errore durante il caricamento della texture del pulsante." << std::endl;
        }
        sf::Vector2f scale(PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_SCALE_Y);
        sf::Vector2f startingPosition(PAUSE_BUTTONS_STARTING_X, PAUSE_BUTTONS_STARTING_Y);

        //Inizializzazione dei bottoni
        for(int i = 0; i < PAUSE_BUTTONS_NUMBER; i++){
            buttons[i] = std::make_unique<MenuButton>(scale, startingPosition + sf::Vector2f(0, i * PAUSE_BUTTON_DISTANCE), buttonTexture);

        }
    };

    bool changeStateToNext = false;
    sf::RenderWindow& window;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[PAUSE_BUTTONS_NUMBER];
};


#endif //JUMPER_PAUSEMENU_H
