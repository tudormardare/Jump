//
// Created by Denis Jaupi on 06/12/23.
//

#include "Timer.h"
#include <iostream>
#include <fstream>
#include <sstream>

Timer::Timer() : elapsedTime(sf::Time::Zero), bestTime(sf::Time::Zero), isRunning(false), bestTimeFilePath("best_time.txt") {
    // Carica il font
    if (!font.loadFromFile("/Users/denis/Projects/Jump/PNG/TimerFont/TimerFont.TTF")) {
        std::cerr << "Impossibile caricare il font.\n";
    }

    // Imposta le proprietà del testo
    bestTimeText.setFont(font);
    bestTimeText.setCharacterSize(20);
    bestTimeText.setFillColor(sf::Color::White);
    bestTimeText.setPosition(10, 10);

    // Carica il bestTime da file
    loadBestTime();
}

void Timer::start() {
    clock.restart();
    isRunning = true;
}

void Timer::stop() {
    if (isRunning) {
        elapsedTime += clock.getElapsedTime();
        isRunning = false;
    }
}

void Timer::update() {
    if (isRunning) {
        elapsedTime = clock.getElapsedTime();
    }
}

sf::Time Timer::getElapsedTime() const {
    return elapsedTime;
}

sf::Time Timer::getBestTime() const {
    return bestTime;
}

void Timer::saveBestTime() {
    if (elapsedTime > bestTime) {
        bestTime = elapsedTime;

        std::ofstream file(bestTimeFilePath);
        if (file.is_open()) {
            file << bestTime.asSeconds();
            file.close();
        } else {
            std::cerr << "Impossibile aprire il file per salvare il miglior tempo.\n";
        }
    }
}

void Timer::loadBestTime() {
    std::ifstream file(bestTimeFilePath);
    if (file.is_open()) {
        double loadedBestTime;
        file >> loadedBestTime;
        bestTime = sf::seconds(static_cast<float>(loadedBestTime));
        file.close();
    }
}

void Timer::displayBestTime(sf::RenderWindow& window) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << bestTime.asSeconds();
    std::string timeString = "Best Time: " + stream.str() + " s ";

    bestTimeText.setString(timeString);
    window.draw(bestTimeText);
}
