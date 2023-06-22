//
// Created by tudor on 15/06/2023.
//

#ifndef JUMPER_GAME_H
#define JUMPER_GAME_H


#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
#define PLAYING_BUTTONS_PATH "PNG/PlayingButton.png"
#define PLAYING_BUTTONS_WIDTH 200
#define PLAYING_BUTTONS_HEIGHT 50
#define PLAYING_BUTTONS_DISTANCE 100
#define PLAYING_BUTTONS_STARTING_X 350
#define PLAYING_BUTTONS_STARTING_Y 100
#define PLAYING_BUTTONS_NUMBER 4


#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "../GUI/MenuButton.h"
#include "SFML/Graphics.hpp"
#include "iostream"

class PlayingState: public GameState{
public:
        static PlayingState& GetInstance(sf::RenderWindow &window);
        void handleEvents(sf::RenderWindow& window, const sf::Event& event) override;
        void update() override;
        void render(sf::RenderWindow& window) override;
        GameState* changeState() override;
        PlayingState(const PlayingState&) = delete;
        void operator=(PlayingState const&) = delete;
private:
    PlayingState(sf::RenderWindow &window): window(window){
        if(!buttonTexture.loadFromFile(PLAYING_BUTTONS_PATH)){
            std::cout << "Errore durante il caricamento della texture del pulsante." << std::endl;
        }
        sf::Vector2f scale(PLAYING_BUTTONS_WIDTH, PLAYING_BUTTONS_HEIGHT);
        sf::Vector2f position(PLAYING_BUTTONS_STARTING_X, PLAYING_BUTTONS_STARTING_Y);

        //Inizializzazione dei bottoni
        for(int i = 0; i < PLAYING_BUTTONS_NUMBER; i++){
            buttons[i] = std::make_unique<MenuButton>(scale, position + sf::Vector2f(0, i * PLAYING_BUTTONS_DISTANCE), buttonTexture);
        }
    };

    bool changeStateToNext = false;
    sf::RenderWindow& window;
    sf::Texture buttonTexture;
    std::unique_ptr<MenuButton> buttons[PLAYING_BUTTONS_NUMBER];

};


#endif //JUMPER_GAME_H
