//
// Created by tudor on 15/06/2023.
//

#define FRAME_DURATION 0.016f

#include <valarray>
#include <iostream>
#include "GamingState.h"

GamingState &GamingState::GetInstance(sf::RenderWindow &window) {
    static GamingState instance(window);
    return instance;
}

void GamingState::initState() {
    //inizializzazione di tutti gli elementi dello stato
    loadAllTextures();
// Avvia il timer
    gameTimer.start();
    //startTimers(); TODO(da inserire la gestione dei timers per gli spawn dei nemici)
    //setTextureForPlayer();
}

std::string GamingState::getBackgroundPath() const {
    return GAME_BACKGROUND_PATH;
}

GameState *GamingState::changeState(sf::RenderWindow &window) {
    //inserire il cambio di stato quando finisce il gioco  o quando viene premuto esc
    return nullptr;
}

void GamingState::handleEvents(sf::RenderWindow &window, const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {

        // Ferma e salva il tempo quando esce dal gioco
        gameTimer.stop();
        gameTimer.saveBestTime();

        window.close();
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) {
            player.setTexture(textureManager.getTexture("Player", "Idle", 0));
        }
    }
}

void GamingState::render(sf::RenderWindow &window) {

    //inserire tutti i draw di tutti gli elemenenti
    gameMap.render(window);
    player.draw(window);
    fire.draw(window);
    pumpkin.draw(window);

    player.draw(window);
    player.renderHealth(window);

    gameTimer.displayElapsedTime(window);

}

void GamingState::update(sf::RenderWindow &window, float deltaTime) {
	gameTimer.update();
    //Verifica le collisioni
    handleCollisions();
    //Aggiorna la posizione degli Sprite
    handleMovements(deltaTime);
    //Aggiorna animazione degli sprite
    handleAnimations(deltaTime);

    //Aggiorna gli sprite
    player.update(deltaTime);

    //Aggiorna il pumpkin solo se non è stato colpito
    if (!pumpkin.isHit()) {
        fire.update(deltaTime);
        pumpkin.update(deltaTime);
    }
}

void GamingState::handleMovements(float deltaTime) {
    //Applica la gravità al giocatore e al powerUp TODO(Aggiungi powerUp)
    //PhysicsSystem::applyGravity(player, deltaTime);
    handlePlayerMovements(deltaTime);
    handleFireBallsMovements(deltaTime);
}

void GamingState::handlePlayerMovements(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isKeyPressedW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);

    handlePlayerHorizontalMovement(isKeyPressedA, isKeyPressedD, deltaTime);


    if (isKeyPressedW && !player.isJumping()) {
        player.jump(player.getVelocity().x);
    }

    // Applica la gravità al giocatore

    if (player.getPosition().y > 700) {
        player.setPosition(player.getPosition().x, 190);
        player.setAccelerationY(0.0f);
    }

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

    sf::Vector2f currentVelocity = player.getVelocity();
    currentVelocity.x += player.getAcceleration().x * deltaTime;
    clampPlayerVelocity(currentVelocity);
    player.setVelocity(currentVelocity);
}

void GamingState::handleAnimations(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isKeyPressedW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);


    if (isKeyPressedW) {
        textureManager.updateAnimation("Player", "Jumping", deltaTime, player);
    } else if (isKeyPressedA || isKeyPressedD) {
        textureManager.updateAnimation("Player", "Running", deltaTime, player);
    } else {
        textureManager.updateAnimation("Player", "Idle", deltaTime, player);
    }

    handleFireBallsAnimations(deltaTime);
}

void GamingState::loadAllTextures() {
    setTextureForPlayer();
    setTextureForFire();
    //Aggiungi altre texture
}

void GamingState::setTextureForPlayer() {

    std::map<std::string, AnimationConfig> playerAnimations = {
            {"Running", {PLAYER_RUNNING_PATH, PLAYER_RUNNING_TEXTURES, PLAYER_RUNNING_MIN_FRAME_DURATION, PLAYER_RUNNING_MAX_FRAME_DURATION, true}},
            {"Jumping", {PLAYER_JUMPING_PATH, PLAYER_JUMPING_TEXTURES, PLAYER_JUMPING_MIN_FRAME_DURATION, PLAYER_JUMPING_MAX_FRAME_DURATION, false}},
            {"Idle",    {PLAYER_IDLE_PATH,    PLAYER_IDLE_TEXTURES,    PLAYER_IDLE_MIN_FRAME_DURATION,    PLAYER_IDLE_MAX_FRAME_DURATION,    false}},
            {"Falling", {PLAYER_FALLING_PATH, PLAYER_FALLING_TEXTURES, PLAYER_FALLING_MIN_FRAME_DURATION, PLAYER_FALLING_MAX_FRAME_DURATION, false}}};


    textureManager.loadEntityTextures("Player", playerAnimations);

// Imposta la texture iniziale e la posizione del player
    player.setTexture(textureManager.getTexture("Player", "Idle", 0));
    player.setPosition(sf::Vector2f(100, 190));

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
    velocity.x = std::clamp(velocity.x, -PLAYER_MAX_SPEED, PLAYER_MAX_SPEED);
}

void GamingState::handleCollisions() {
    //Prova collisioni con i nemici
    //std::vector<Entity*> colliders;
    //colliders.push_back(&pumpkin);
    //Entity* collider = CollisionManager::handleCircleEnemy(player, colliders);
    if (CollisionManager::checkCollision(player.getHitbox(), pumpkin.getHitbox())) {
        std::cout << "Collisione ";
        pumpkin.setHit(true);
        pumpkin.setPosition(sf::Vector2f(-1000, -1000));
        fire.setPosition(sf::Vector2f(-1000, -1000));
    }
}

void GamingState::setTextureForFire() {
   std::map<std::string, AnimationConfig> fireAnimations = {
            {"Fire", {FIRE_TEXTURE_PATH, FIRE_TEXTURES, FIRE_MIN_FRAME_DURATION, FIRE_MAX_FRAME_DURATION, false}}
   };

   std::map<std::string, AnimationConfig> pumpkinAnimation = {
           {"Pumpkin", {PUMPKIN_TEXTURE_PATH, PUMPKIN_TEXTURES, PUMPKIN_MIN_FRAME_DURATION, PUMPKIN_MAX_FRAME_DURATION, false}}
   };
        textureManager.loadEntityTextures("Fire", fireAnimations);
        textureManager.loadEntityTextures("Pumpkin", pumpkinAnimation);

        fire.setTexture(textureManager.getTexture("Fire", "Fire", 0));
        fire.setPosition(sf::Vector2f(- 200, 100));
        fire.setVelocity(sf::Vector2f(FIRE_DEFAULT_SPEED, 0)   );

        //Aggiungi funzione per centrare l'immagine TODO(Settare il global bounds per centrare l'immagine)
        pumpkin.setTexture(textureManager.getTexture("Pumpkin", "Pumpkin", 0));
        pumpkin.setPosition(sf::Vector2f(- 85, 190));
        pumpkin.setVelocity(sf::Vector2f(FIRE_DEFAULT_SPEED, 0)   );
}

void GamingState::handleFireBallsAnimations(float deltaTime) {
    textureManager.updateAnimation("Fire", "Fire", deltaTime, fire);
}

void GamingState::handleFireBallsMovements(float deltaTime) {
    //Verficare se il fuoco è uscito dallo schermo
    if (fire.getPosition().x > WINDOW_WIDTH) {
        fire.setPosition(sf::Vector2f(- 200, 100));
    }

    if (pumpkin.getPosition().x > WINDOW_WIDTH + 115) {
        pumpkin.setPosition(sf::Vector2f(- 85, 190));
    }
    //Aggiorna la velocità in base al tempo passato dall'inzio del gioco
}

void GamingState::spawnPumpkin() {
    // Da quale lato spawna
    int side = rand() % 2;

    Pumpkin newPumpkin;

    // Imposta la posizione in base al lato scelto
    if (side == 0) {
        newPumpkin.setPosition(sf::Vector2f(-85, 190));
        newPumpkin.setVelocity(sf::Vector2f(FIRE_DEFAULT_SPEED, 0));
    } else {
        newPumpkin.setPosition(sf::Vector2f(WINDOW_WIDTH + 85, 190));
        newPumpkin.setVelocity(sf::Vector2f(-FIRE_DEFAULT_SPEED, 0));
    }

    // Aggiungi la nuova zucca alla tua collezione di zucche (o gestiscila come preferisci)
    // pumpkinCollection.push_back(newPumpkin);

    // Controlla se c'è una collisione con il player e gestisci la scomparsa del pumpkin
    if (CollisionManager::checkCollision(player.getHitbox(), newPumpkin.getHitbox())) {
        std::cout << "Collisione con nuova zucca!\n";
        newPumpkin.setHit(true);
        newPumpkin.setPosition(sf::Vector2f(-1000, -1000));
        fire.setPosition(sf::Vector2f(-1000, -1000));
    }

}







