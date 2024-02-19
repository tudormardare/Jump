//
// Created by Denis Jaupi on 18/02/24.
//
#include "GameOverState.h"

GameOverState &GameOverState::GetInstance(sf::RenderWindow &window) {
    static GameOverState instance(window);
    instance.initState();
    return instance;
}

GameOverState::GameOverState(sf::RenderWindow &window) {
    initState();
}

void GameOverState::initState() {
    initGameOverButton();
}

void GameOverState::update(sf::RenderWindow &window, float deltaTime) {

}

void GameOverState::render(sf::RenderWindow &window) {
    handleGameOver(window);
}

GameState *GameOverState::changeState(sf::RenderWindow &window) {
    return nullptr;
}

void GameOverState::initGameOverButton() {
    // Inizializzazione del pulsante di gioco terminato con texture diversa
    sf::Texture gameOverButtonTexture;

    if (!gameOverButtonTexture.loadFromFile(GAMEOVER_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della texture del pulsante GAME OVER." << std::endl;
    }

    sf::Vector2f size(PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT);
    sf::Vector2f position((WINDOW_WIDTH) / 2.0f, (WINDOW_HEIGHT) / 1.2f);

    // Inizializzazione del pulsante di gioco terminato con texture diversa
    gameOverButton = std::make_unique<MenuButton>(size, position, gameOverButtonTexture);

}

void GameOverState::handleGameOver(sf::RenderWindow &window) {

    // Disegna lo sfondo del Game Over semitrasparente
    sf::Texture pauseTexture;
    if (!pauseTexture.loadFromFile("PNG/PauseBackground/TransparentBackground.png")) {
        std::cerr << "Impossibile caricare l'immagine di pausa.\n";
        return;
    }
    sf::Sprite pauseSprite(pauseTexture);
    float scaleX = static_cast<float>(window.getSize().x) / pauseSprite.getLocalBounds().width;
    float scaleY = static_cast<float>(window.getSize().y) / pauseSprite.getLocalBounds().height;
    pauseSprite.setScale(scaleX, scaleY);
    float posX = window.getSize().x - pauseSprite.getGlobalBounds().width;
    float posY = window.getSize().y - pauseSprite.getGlobalBounds().height;
    pauseSprite.setPosition(posX, posY);
    window.draw(pauseSprite);


    // Mostra un messaggio di game over
    sf::Font font;
    if (!font.loadFromFile("PNG/TimerFont/TimerFont.TTF")) {
        std::cerr << "Impossibile caricare il font\n";
        return;
    }
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(290, 200);
    gameOverText.setString("GAME OVER!");
    window.draw(gameOverText);

    sf::Text exitText;
    exitText.setFont(font);
    exitText.setCharacterSize(20);
    exitText.setFillColor(sf::Color::Red);
    exitText.setPosition(390, 300);
    exitText.setString("Press \"ESC\" to exit");
    window.draw(exitText);

    sf::Text bestTimeText;
    bestTimeText.setFont(font);
    bestTimeText.setCharacterSize(20);
    bestTimeText.setFillColor(sf::Color::White);
    bestTimeText.setPosition(395, 350);
    std::ostringstream formattedTime;
    formattedTime << std::fixed << std::setprecision(2) << gameTimer.getElapsedTime().asSeconds();
    bestTimeText.setString("Time: " + formattedTime.str() + " seconds");
    window.draw(bestTimeText);

    // Button to restart the game
    gameOverButton->draw(window);

}

void GameOverState::handleEvents(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (gameOverButton->isClicked(window)) {
            }
        }
    }

}

std::string GameOverState::getBackgroundPath() const {
    return std::string();
}
