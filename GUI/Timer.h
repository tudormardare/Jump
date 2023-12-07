//
// Created by Denis Jaupi on 06/12/23.
//

#ifndef JUMP_TIMER_H
#define JUMP_TIMER_H


#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Timer{
public:
    Timer();

    void start();
    void stop();
    void update();

    sf::Time getElapsedTime() const;
    sf::Time getBestTime() const;

    void saveBestTime();
    void loadBestTime();

    void displayBestTime(sf::RenderWindow& window);
    void displayElapsedTime(sf::RenderWindow& window);


private:

    sf::Clock clock;
    sf::Time elapsedTime;
    sf::Time bestTime;
    bool isRunning;

    // Variabili relative al font
    sf::Font font;
    sf::Text bestTimeText;
    sf::Text elapsedTimeText;

    std::string bestTimeFilePath;
};


#endif //JUMP_TIMER_H
