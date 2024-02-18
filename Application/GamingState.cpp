//
// Created by tudor on 15/06/2023.
//

#define FRAME_DURATION 0.016f

#include <valarray>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <random>

#include "GamingState.h"
#include "MenuState.h"

nlohmann::json j;

GamingState &GamingState::GetInstance(sf::RenderWindow &window) {
    static GamingState instance(window);
    return instance;
}

void GamingState::initState() {
    gameOver = false;
    paused = false;
    changeStateToNext = false;

    // Clear degli elementi
    hearts.clear();
    pauseButtons.clear();
    player.resetHealth();

    // Inizializzazione di tutti gli elementi dello stato
    loadAllTextures();
    initPauseButtons();
    initGameOverButton();
    initTimer();

    std::ifstream i("hitbox/MapHitBoxes.json"); // Sostituisci con il percorso corretto del file
    i >> j;
}


//Game logic functions
GameState *GamingState::changeState(sf::RenderWindow &window) {
    //inserire il cambio di stato quando finisce il gioco o quando viene premuto esc
    if (changeStateToNext) {
        changeStateToNext = false;
        if (pauseButtons[1]->isClicked(window)) {
            gameTimer.saveBestTime();
            return &MenuState::GetInstance(window);
        }

    }
    return nullptr;
}

void GamingState::handleEvents(sf::RenderWindow &window, const sf::Event &event) {

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        window.close();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {

        gameTimer.stop();
        gameTimer.saveBestTime();
        window.close();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        if (!gameOver) {
            paused = !paused;
            if (paused) {
                gameTimer.pause();
            } else {
                gameTimer.resume();
            }
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (paused) {
                if (pauseButtons[1]->isClicked(window)) {
                    pauseButtons[1]->update(window);
                    changeStateToNext = true;
                    paused = false;
                }
                if (pauseButtons[0]->isClicked(window)) {
                    pauseButtons[0]->update(window);
                    gameTimer.resume();
                    paused = false;
                }
            } else if (gameOver) {
                if (gameOverButton->isClicked(window)) {
                    gameOverButton->update(window);
                    initState();
                }
            }

        }
    }

    if (event.type == sf::Event::KeyReleased) {
        if ((event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) && !player.isJumping()) {
            player.setTexture(textureManager.getTexture("Player", "Idle", 0));
        }
    }
}

void GamingState::initPauseButtons() {
    // Inizializzazione dei pulsanti di pausa con texture diverse
    sf::Texture resumeButtonTexture, quitButtonTexture;

    if (!resumeButtonTexture.loadFromFile(PAUSE_RESUME_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della texture del pulsante RESUME." << std::endl;
    }
    if (!quitButtonTexture.loadFromFile(PAUSE_QUIT_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della texture del pulsante QUIT." << std::endl;
    }

    sf::Vector2f size(PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT);
    float totalHeight =
            (PAUSE_BUTTONS_NUMBER * PAUSE_BUTTON_HEIGHT) + (PAUSE_BUTTON_DISTANCE * (PAUSE_BUTTONS_NUMBER - 1));
    sf::Vector2f startingPosition((WINDOW_WIDTH) / (float) 2, (WINDOW_HEIGHT - totalHeight) / (float) 1.5);

    // Inizializzazione dei pulsanti di pausa con texture diverse
    pauseButtons.emplace_back(std::make_unique<MenuButton>(size, startingPosition, resumeButtonTexture));
    pauseButtons.emplace_back(std::make_unique<MenuButton>(size, startingPosition + sf::Vector2f(0,
                                                                                                 PAUSE_BUTTON_HEIGHT +
                                                                                                 PAUSE_BUTTON_DISTANCE),
                                                           quitButtonTexture));


}

void GamingState::initGameOverButton() {
    // Inizializzazione del pulsante di gioco terminato con texture diversa
    sf::Texture gameOverButtonTexture;

    if (!gameOverButtonTexture.loadFromFile(PAUSE_RESUME_BUTTON_PATH)) {
        std::cout << "Errore durante il caricamento della texture del pulsante GAME OVER." << std::endl;
    }

    sf::Vector2f size(PAUSE_BUTTON_WIDTH, PAUSE_BUTTON_HEIGHT);
    sf::Vector2f position((WINDOW_WIDTH) / 2.0f, (WINDOW_HEIGHT) / 1.2f);

    // Inizializzazione del pulsante di gioco terminato con texture diversa
    gameOverButton = std::make_unique<MenuButton>(size, position, gameOverButtonTexture);
}

void GamingState::drawPause(sf::RenderWindow &window) {

    // Renderizza "Press "P" to pause"
    sf::Font font;
    if (!font.loadFromFile("PNG/TimerFont/TimerFont.TTF")) {
        std::cerr << "Impossibile caricare il font\n";
        return;
    }
    sf::Text pauseText;
    pauseText.setFont(font);
    pauseText.setCharacterSize(20);
    pauseText.setFillColor(sf::Color::White);
    pauseText.setPosition(window.getSize().x - 300, 10);
    pauseText.setString("Press \"P\" to pause");
    window.draw(pauseText);

    if (paused) {
        // Disegna lo sfondo della pausa semitrasparente
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


        // Disegna i pulsanti di pausa
        for (auto &button: pauseButtons) {
            button->draw(window);
        }
    }
}

void GamingState::handleGameOver(sf::RenderWindow &window) {
    if (player.getHealth() <= 0) {
        gameOver = true;

        // Ferma e salva il tempo quando finisce il gioco
        gameTimer.stop();
        gameTimer.saveBestTime();



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
}

std::string GamingState::getBackgroundPath() const {
    return GAME_BACKGROUND_PATH;
}

void GamingState::loadAllTextures() {
    setTextureForPlayer();
    setTextureForEnemy();
    setTextureForHeart();

    //Aggiungi altre texture
}

//Rendering functions
void GamingState::render(sf::RenderWindow &window) {

    //TODO:Inserire nei test
    player.getHitbox();
    sf::RectangleShape rectangle(sf::Vector2f(player.getHitbox().width, player.getHitbox().height));
    sf::VertexArray points(sf::Points, 1);
    points[0].position = sf::Vector2f(player.getCenter().x, player.getCenter().y);
    points[0].color = sf::Color::Red;
    rectangle.setPosition(player.getHitbox().left, player.getHitbox().top);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1.f);
    window.draw(rectangle);
    window.draw(points);
    drawHitboxes(gameMap.getMapHitboxes(), window);
    gameMap.render(window);
    //fire.draw(window);
    for(auto &fireBall: fireBalls){
        fireBall.draw(window);
    }
    //pumpkin.draw(window);

    if(Timers.isStarted(eTimer::ePlayerInvincible) && !Timers.isExpired(eTimer::ePlayerInvincible)){
        if(Timers.isExpired(eTimer::ePlayerBlinking) && !Timers.isPaused(eTimer::ePlayerBlinking)){
            player.setVisibility(!player.isVisible());
            Timers.restartTimer(eTimer::ePlayerBlinking);
            std::cout << "Dentro a invincibilità" << std::endl;
        }
        if(player.isVisible()){
            player.draw(window);
        }
    }else {
        player.draw(window);
    }
    player.renderHealth(window);
    gameTimer.displayElapsedTime(window);


    for (int i = 0; i < hearts.size(); i++) {

        if(i == 0 && Timers.isStarted(eTimer::eBlinking) && !Timers.isExpired(eTimer::eBlinking)) {
                hearts[i].draw(window);
        }else if(i == 0 && !Timers.isStarted(eTimer::eBlinking)){
                hearts[i].draw(window);
        }else if (i != 0){
            hearts[i].draw(window);
        }

        if(Timers.isExpired(eTimer::eBlinking)){
            Timers.restartTimer(eTimer::eBlinking);
        }


        sf::RectangleShape rectangle(sf::Vector2f(hearts[i].getHitbox().width, hearts[i].getHitbox().height));
        sf::VertexArray points(sf::Points, 1);
        points[0].position = sf::Vector2f(hearts[i].getCenter().x, hearts[i].getCenter().y);
        points[0].color = sf::Color::Red;
        rectangle.setPosition(hearts[i].getHitbox().left, hearts[i].getHitbox().top);
        rectangle.setFillColor(sf::Color::Transparent);
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setOutlineThickness(1.f);
        window.draw(rectangle);
        window.draw(points);

    }

    for(auto &fireBall: fireBalls){
        sf::RectangleShape rectangle(sf::Vector2f(fireBall.getPumpkin().getHitbox().width, fireBall.getPumpkin().getHitbox().height));
        sf::VertexArray points(sf::Points, 1);
        points[0].position = sf::Vector2f(fireBall.getPumpkin().getCenter().x, fireBall.getPumpkin().getCenter().y);
        points[0].color = sf::Color::Red;
        rectangle.setPosition(fireBall.getPumpkin().getHitbox().left, fireBall.getPumpkin().getHitbox().top);
        rectangle.setFillColor(sf::Color::Transparent);
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setOutlineThickness(1.f);
        window.draw(rectangle);
        window.draw(points);
    }

    drawPause(window);
    handleGameOver(window);

}

void GamingState::update(sf::RenderWindow &window, float deltaTime) {
    if (!paused && !gameOver) {

        gameTimer.update();

        //Gestisce i timers
        handleTimers(deltaTime);

        //Aggiorna la posizione degli Sprite
        handleMovements(deltaTime);

        //Aggiorna animazione degli sprite
        handleAnimations(deltaTime);

        //Verifica le collisioni
        handleCollisions();

        sf::Vector2f currentVelocity = player.getVelocity();
        currentVelocity.y += player.getAcceleration().y;
        currentVelocity.x += player.getAcceleration().x;
        clampPlayerYVelocity(currentVelocity);
        clampPlayerVelocity(currentVelocity);
        player.setVelocity(currentVelocity * deltaTime);

        for(auto &heart: hearts){
            float heartVelocity = heart.getVelocity().y;
            heartVelocity += heart.getAcceleration().y;

            heart.setVelocity(sf::Vector2f(0, heartVelocity * deltaTime));

        }

        if(Timers.isExpired(eTimer::eHeartDespawn)){
            std::cout << "Dentro" << std::endl;
            Timers.restartTimer(eTimer::eHeartDespawn);
        }



        //Aggiorna gli sprite
        player.update(deltaTime);
        updateHearts(deltaTime);


        updateFireBalls(deltaTime);
        //TODO:GESTIRE COLLISIONI CON I NEMICI
       if (paused) {
            for (auto &button: pauseButtons) {
                button->update(window);
            }
        } else if (gameOver) {
            gameOverButton->update(window);
        }

    }
}

// Player functions
void GamingState::handleMovements(float deltaTime) {
    //Applica la gravità al giocatore e al powerUp TODO(Aggiungi powerUp)
    //PhysicsSystem::applyGravity(player, deltaTime);
    handlePlayerMovements(deltaTime);
    for (auto &heart: hearts) {
        PhysicsSystem::applyGravity(heart);
        //heart.setVelocity(sf::Vector2f(0, 3));
    }
}

void GamingState::handlePlayerMovements(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isKeyPressedW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);

    handlePlayerHorizontalMovement(isKeyPressedA, isKeyPressedD, deltaTime);
    handlePlayerJump(isKeyPressedW, deltaTime);

    PhysicsSystem::applyGravity(player);

}

void GamingState::handlePlayerHorizontalMovement(bool isKeyPressedA, bool isKeyPressedD, float deltaTime) {
    int movementDirection = (isKeyPressedA ? -1 : 0) + (isKeyPressedD ? 1 : 0);

    if (movementDirection != 0) {
        if (player.getInverse() != (movementDirection < 0)) {
            player.inverse();
        }
        adjustAccelerationForDirectionChange((float) movementDirection * PLAYER_ACCELERATION_RATE, deltaTime);
    } else {
        deceleratePlayer(deltaTime);
    }
}

void GamingState::handlePlayerJump(bool isKeyPressedW, float deltaTime) {
    if (isKeyPressedW && !player.isJumping() && player.getVelocity().y == 0) {
        player.setAccelerationY(-JUMP_FORCE); // Imposta la velocità iniziale verso l'alto
        player.setJumping(true);
        player.setTexture(textureManager.getTexture("Player", "Jumping", 0));
    }

}

void GamingState::handleAnimations(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isMovingHorizontally = (isKeyPressedA || isKeyPressedD);
    bool isFalling = player.getVelocity().y > 0;
    bool isIdle = player.getVelocity().x == 0 && !player.isJumping();

    if (player.isJumping() && textureManager.getCurrentIndex("Player") < 2) {
        // Se il player sta saltando, visualizza l'animazione di salto
        textureManager.updateAnimation("Player", "Jumping", deltaTime, player);
    } else if (player.isJumping() && player.getAcceleration().y >= -2 && player.getVelocity().y <= 0 &&
               textureManager.getCurrentIndex("Player") != 3) {
        textureManager.setSpecificFrame("Player", "Jumping", 3, player);
    } else if (isFalling) {
        // Se il player sta cadendo (in aria con una velocità verso il basso), visualizza l'animazione di caduta
        textureManager.updateAnimation("Player", "Falling", deltaTime, player);
    } else if (isMovingHorizontally && !player.isJumping()) {
        // Se il player si sta muovendo orizzontalmente ed è sul terreno, visualizza l'animazione di corsa
        textureManager.updateAnimation("Player", "Running", deltaTime, player);
    } else if (isIdle) {
        // Se il player non si sta muovendo, visualizza l'animazione d'inattività
        textureManager.updateAnimation("Player", "Idle", deltaTime, player);
    }

    handleEnemyAnimations(deltaTime);
    for(auto &heart: hearts){
        textureManager.updateAnimation(heart.getName(), "Heart", deltaTime, heart);
    }
}

void GamingState::handleCollisionMap(CollisionManager::CollisionResult collision) {
    switch (collision.direction) {
        case CollisionManager::CollisionDirection::Top:

            if (!player.isJumping()) {
                PhysicsSystem::standOn(player);
                if (collision.overlap > 5)
                    player.setPosition(player.getPosition().x, player.getPosition().y - collision.overlap);
                player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
            }

            //std::cout << "Collisione con la parte superiore della piattaforma" << std::endl;
            if (player.getAcceleration().y > 0 &&
                ((player.getHitbox().top + player.getHitbox().height) - 10) <= collision.platformPosition.y) {
                player.setJumping(false);
                std::cout << "Collisione con la parte superiore della piattaforma" << std::endl;
                player.setTexture(textureManager.getTexture("Player", "Idle", 0));
                textureManager.resetAnimation("Player", "Jumping");
                player.setPosition(player.getPosition().x, player.getPosition().y - collision.overlap);
                player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
                player.setAcceleration(sf::Vector2f(player.getAcceleration().x, 0));
            }
            break;
        case CollisionManager::CollisionDirection::Bottom:
            //std::cout << "Collisione con la parte inferiore della piattaforma" << std::endl;
            /*player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
            player.setAcceleration(sf::Vector2f(player.getAcceleration().x, 0));
            player.setPosition(player.getPosition().x, player.getPosition().y + collision.overlap);*/
            break;
        case CollisionManager::CollisionDirection::Left:
            if (player.isJumping()) break;
            player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
            player.setAccelerationX(0);
            player.setPosition(player.getPosition().x - collision.overlap,
                               player.getPosition().y); //sposta il player indietro TODO: sistemare
            break;
        case CollisionManager::CollisionDirection::Right:
            if (player.isJumping()) break;
            player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
            player.setAccelerationX(0);
            player.setPosition(player.getPosition().x + collision.overlap, player.getPosition().y);
            break;
        case CollisionManager::CollisionDirection::None:
            break;
    }

}

void GamingState::setTextureForPlayer() {

    std::map<std::string, AnimationConfig> playerAnimations = {
            {"Running",        {PLAYER_RUNNING_PATH, PLAYER_RUNNING_TEXTURES, PLAYER_RUNNING_MIN_FRAME_DURATION, PLAYER_RUNNING_MAX_FRAME_DURATION, true}},
            {"Jumping",        {PLAYER_JUMPING_PATH, PLAYER_JUMPING_TEXTURES, PLAYER_JUMPING_MIN_FRAME_DURATION, PLAYER_JUMPING_MIN_FRAME_DURATION, false}},
            {"Idle",           {PLAYER_IDLE_PATH,    PLAYER_IDLE_TEXTURES,    PLAYER_RUNNING_MIN_FRAME_DURATION, PLAYER_RUNNING_MIN_FRAME_DURATION, false}},
            {"Falling",        {PLAYER_FALLING_PATH, PLAYER_FALLING_TEXTURES, PLAYER_FALLING_MIN_FRAME_DURATION, PLAYER_FALLING_MAX_FRAME_DURATION, false}},
            {"CrunchTextures", {PLAYER_CRUNCH_PATH,  PLAYER_CRUNCH_TEXTURES,  PLAYER_RUNNING_MAX_FRAME_DURATION, PLAYER_RUNNING_MAX_FRAME_DURATION, false}},
            {"Die",            {PLAYER_DEAD_PATH,    PLAYER_DEAD_TEXTURES,    PLAYER_RUNNING_MAX_FRAME_DURATION, PLAYER_RUNNING_MAX_FRAME_DURATION, false}}};
    {
        // Carica le texture del player
        textureManager.loadEntityTextures("Player", playerAnimations);
    }


    textureManager.loadEntityTextures("Player", playerAnimations);

// Imposta la texture iniziale e la posizione del player
    player.setTexture(textureManager.getTexture("Player", "Idle", 0));
    player.setPosition(sf::Vector2f(100, 500));

}

void GamingState::adjustAccelerationForDirectionChange(float accelerationRate, float deltaTime) {
    float direction = (accelerationRate > 0) ? 1.0f : -1.0f;
    if (direction * player.getVelocity().x < 0) { // Cambio di direzione
        deceleratePlayer(deltaTime); // Prima decelera
        if (player.getVelocity().x == 0) {
            player.setAccelerationX(accelerationRate); // Poi inizia ad accelerare nella nuova direzione
        }
    } else {
        player.setAccelerationX(accelerationRate); // Accelerazione normale
    }
}

bool GamingState::deceleratePlayer(float deltaTime) {
    const float Threshold = 0.1f; // Velocità sotto la quale il giocatore si ferma
    float deceleration = (player.getVelocity().x > 0) ? -PLAYER_DECELERATION_RATE : PLAYER_DECELERATION_RATE;
    player.setAccelerationX(deceleration);

    // Se la velocità è minore di un certo valore, il giocatore si ferma
    if (std::abs(player.getVelocity().x) < Threshold) {
        player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
        player.setAccelerationX(0.f);
        return true; // Il giocatore si è fermato
    }
    return false; // Il giocatore è ancora in movimento
}

void GamingState::clampPlayerVelocity(sf::Vector2f &velocity) {
    velocity.x = std::clamp(velocity.x, -PLAYER_MAX_SPEED * 2, PLAYER_MAX_SPEED * 2);
}

void GamingState::clampPlayerYVelocity(sf::Vector2f &velocity) {
    velocity.y = std::clamp(velocity.y, -PLAYER_MAX_SPEED * 4, PLAYER_MAX_SPEED * 2);
}

void GamingState::handleCollisions() {
    //Prova collisioni con i nemici
    //std::vector<Entity*> colliders;
    //colliders.push_back(&pumpkin);
    //Entity* collider = CollisionManager::handleCircleEnemy(player, colliders);

    /* if (CollisionManager::checkMapCollision(player, gameMap.getMapHitboxes())) {
         std::cout << "Collisione con la mappa";
         player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
     }*/

    std::vector<CollisionManager::CollisionResult> collisions = CollisionManager::checkMapCollision(player,
                                                                                                   gameMap.getMapHitboxes());
    for (const auto &collision: collisions) {
        if (collision.hasCollision) {
            handleCollisionMap(collision);
        }
    }
    bool hitted = false;
    for(auto &fireBall: fireBalls){
        if (CollisionManager::checkCircleCollision(fireBall.getPumpkin(), player)) {
            hitted = true;
        }
    }
    if(hitted && !player.isInvincible()) {
        player.takeDamage();
        player.setInvincible(true);
        Timers.restartTimer(eTimer::ePlayerInvincible);
        if(player.getHealth() > 0) {
            Timers.restartTimer(eTimer::ePlayerBlinking);
        }else{
            Timers.pauseTimer(eTimer::ePlayerBlinking);
        }
    }
}

//Enemy functions
void GamingState::setTextureForEnemy() {
    std::map<std::string, AnimationConfig> fireAnimations = {
            {"Fire", {FIRE_TEXTURE_PATH, FIRE_TEXTURES, FIRE_MIN_FRAME_DURATION, FIRE_MAX_FRAME_DURATION, false}}
    };

    std::map<std::string, AnimationConfig> pumpkinAnimation = {
            {"Pumpkin",
             {PUMPKIN_TEXTURE_PATH, PUMPKIN_TEXTURES, PUMPKIN_MIN_FRAME_DURATION, PUMPKIN_MAX_FRAME_DURATION,
              false}}
    };
    textureManager.loadEntityTextures("FireBall", fireAnimations, GAMING_MAX_FIREBALLS);
    textureManager.loadEntityTextures("Pumpkin", pumpkinAnimation);
}

void GamingState::handleEnemyAnimations(float deltaTime) {
    for(auto &fireBall: fireBalls){
        textureManager.updateAnimation(fireBall.getName(), "Fire", deltaTime, fireBall.getFire());
    }
}

void GamingState::setTextureForHeart() {
    std::map<std::string, AnimationConfig> heartAnimations = {
            {"Heart",
             {HEART_TEXTURE_PATH, HEART_TEXTURES, HEART_MIN_FRAME_DURATION, HEART_MAX_FRAME_DURATION, false}}
    };

    textureManager.loadTexturesFromSpriteSheetWithLineNumber("Heart", "PNG/Heart/heartAnimation.png", heartAnimations,
                                                             32,
                                                             32, GAMING_MAX_HEARTS);
}

void GamingState::spawnHeart() {
    Heart heart;
    heart.setTexture(textureManager.getTexture("Heart1", "Heart", 0));

    // Controlla se ci sono già 2 cuori sulla mappa
    if (hearts.size() < GAMING_MAX_HEARTS) {
        int xPosition = randomBetween(40, WINDOW_WIDTH - 40);
        std::cout << "Spawned heart at " << xPosition << std::endl;
        heart.setPosition(sf::Vector2f((float) xPosition, 0));
        heart.setName("Heart" + std::to_string(hearts.size() + 1));
        hearts.push_back(heart);
    }

}

void GamingState::handleTimers(float deltaTime) {
    if(Timers.isExpired(eTimer::eHeartDespawn)){
        hearts.erase(hearts.begin());
        int i = 1;
        for(auto &heart : hearts){
            heart.setName("Heart" + std::to_string(i));
            i++;
        }
        if(!hearts.empty())
            Timers.restartTimer(eTimer::eHeartDespawn);
    }

  if(Timers.isExpired(eTimer::eHearthSpawn)){
    spawnHeart();
    if(!Timers.isStarted(eTimer::eHeartDespawn))
      Timers.startTimer(eTimer::eHeartDespawn);
    Timers.restartTimer(eTimer::eHearthSpawn);
  }

  if(Timers.getElapsedTime(eTimer::eHeartDespawn) > 2000){
      Timers.startTimer(eTimer::eBlinking);
  }
}

void GamingState::handleHeartCollisions(Heart &heart) {
    if (CollisionManager::checkCollision(player.getHitbox(), heart.getHitbox())) {
        heart.setCollected(true);
        player.gainHealth();
        heart.setPosition(sf::Vector2f(-1000, -1000));
    }

    std::vector<CollisionManager::CollisionResult> collisions = CollisionManager::checkMapCollision(heart,
                                                                                                   gameMap.getMapHitboxes());
    for (const auto &collision: collisions) {
        if (collision.hasCollision) {
            heart.setVelocity(sf::Vector2f(0, 0));
            heart.setAcceleration(sf::Vector2f(0, 0));
            heart.setPosition(sf::Vector2f(heart.getPosition().x, heart.getPosition().y - collision.overlap));
        }
    }
}

void GamingState::updateHearts(float deltaTime) {
    //handleHeartSpawn(deltaTime);

    // Itera attraverso i cuori e applica le operazioni necessarie
    for (auto &heart: hearts) {
        heart.update(deltaTime);
        handleHeartCollisions(heart);
    }

    // Rimuovi i cuori raccolti dal vettore
    hearts.erase(std::remove_if(hearts.begin(), hearts.end(), [](const Heart &heart) {
        return heart.isCollected();
    }), hearts.end());
}

void GamingState::drawHitboxes(const std::vector<sf::FloatRect> &hitboxes, sf::RenderWindow &window) {
    for (const auto &hitbox: hitboxes) {
        sf::RectangleShape rectangle(sf::Vector2f(hitbox.width, hitbox.height));
        rectangle.setPosition(hitbox.left, hitbox.top);
        rectangle.setFillColor(sf::Color::Transparent);
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setOutlineThickness(1.f);

        window.draw(rectangle);
    }
}

void GamingState::initTimer() {
    gameTimer.reset();
    gameTimer.start();
    Timers.addTimer(eTimer::eHearthSpawn, std::chrono::milliseconds(8000), [&]() { },
                    TimerClass::eTimerMode::OnceDown);
    Timers.addTimer(eTimer::eHeartDespawn, std::chrono::milliseconds(12000), [&]() { std::cout << "Despawned heart"; },
                    TimerClass::eTimerMode::OnceDown);
    Timers.addTimer(eTimer::eBlinking, std::chrono::milliseconds(1000), [&]() { },
                    TimerClass::eTimerMode::OnceDown);
    Timers.addTimer(eTimer::eFireballSpawn, std::chrono::milliseconds(1000), [&]() { spawnFireBall(); },
                    TimerClass::eTimerMode::Cyclic);

    Timers.addTimer(eTimer::ePlayerInvincible, std::chrono::milliseconds(5000), [&]() {
        player.setInvincible(false);
        player.setVisibility(true);
        },
                    TimerClass::eTimerMode::OnceDown);

    Timers.addTimer(eTimer::ePlayerBlinking, std::chrono::milliseconds(200), [&]() { },
                    TimerClass::eTimerMode::OnceDown);

    Timers.startTimer(eTimer::eHearthSpawn);
    Timers.startTimer(eTimer::eFireballSpawn);


}

int GamingState::randomBetween(int min, int max) {
    if (max <= min) return min;

    int range = max - min + 1;
    int randomNumber = min + (rand() % range);
    return randomNumber;
}

void GamingState::spawnFireBall() {
    Ball fireBall;
    fireBall.setPumpkinTexture(textureManager.getTexture("Pumpkin", "Pumpkin", 0));

    if (fireBalls.size() < GAMING_MAX_FIREBALLS) {
        int yPosition = randomBetween(10, WINDOW_HEIGHT - 200);
        int xPosition = randomBetween(1, 2);
        if (xPosition == 1) {
            fireBall.setInverse(false);
            fireBall.setFireScale(FIRE_SCALE, FIRE_SCALE);
            fireBall.setPumpkinScale(PUMPKIN_SCALE, PUMPKIN_SCALE);
            fireBall.setPosition(sf::Vector2f( -200 , (float) yPosition));
            fireBall.setVelocity(1, 0);
        }else{
            fireBall.setInverse(true);
            fireBall.setFireScale(-FIRE_SCALE, FIRE_SCALE);
            fireBall.setPumpkinScale(-PUMPKIN_SCALE, PUMPKIN_SCALE);
            fireBall.setPosition(sf::Vector2f(WINDOW_WIDTH + 200, (float) yPosition));
            fireBall.setVelocity(-1, 0);
            fireBall.setName("FireBall" + std::to_string(fireBalls.size() + 1));
        }

        fireBall.setName("FireBall" + std::to_string(fireBalls.size() + 1));
        fireBall.setFireTexture(textureManager.getTexture(fireBall.getName(), "Fire", 0));
        fireBalls.push_back(fireBall);
    }
}

void GamingState::updateFireBalls(float deltaTime) {

    for(auto &fireBall: fireBalls){
        if(fireBall.getInverse() && fireBall.getPosition().x < -200){
            int yPosition = randomBetween(10, WINDOW_HEIGHT - 200);
            int xPosition = randomBetween(1, 2);
            if(xPosition == 1)
                fireBall.setPosition(sf::Vector2f(WINDOW_WIDTH + 200, (float) yPosition));
            else {
                fireBall.setInverse(false);
                fireBall.setPosition(sf::Vector2f(-200, (float) yPosition));
                fireBall.setFireScale(FIRE_SCALE, FIRE_SCALE);
                fireBall.setPumpkinScale(PUMPKIN_SCALE, PUMPKIN_SCALE);
                fireBall.setVelocity(1, 0);
            }

        }else if(!fireBall.getInverse() && fireBall.getPosition().x > WINDOW_WIDTH + 200){
            int yPosition = randomBetween(10, WINDOW_HEIGHT - 200);
            int xPosition = randomBetween(1, 2);
            if(xPosition == 1)
                fireBall.setPosition(sf::Vector2f(-200, (float) yPosition));
            else {
                fireBall.setInverse(true);
                fireBall.setPosition(sf::Vector2f(WINDOW_WIDTH + 200, (float) yPosition));
                fireBall.setFireScale(-FIRE_SCALE, FIRE_SCALE);
                fireBall.setPumpkinScale(-PUMPKIN_SCALE, PUMPKIN_SCALE);
                fireBall.setVelocity(-1, 0);
            }
        }
    }

    for(auto &fireBall: fireBalls){
        fireBall.update(deltaTime);
    }

}

