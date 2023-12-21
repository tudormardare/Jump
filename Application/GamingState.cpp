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
    //inserire il cambio di stato quando finisce il gioco o quando viene premuto esc
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
    player.draw(window);
    fire.draw(window);
    pumpkin.draw(window);
	gameMap.render(window);
    player.draw(window);

    gameTimer.displayElapsedTime(window);

}

void GamingState::update(sf::RenderWindow &window, float deltaTime) {
	gameTimer.update();
    //Aggiorna la posizione degli Sprite
    handleMovements(deltaTime);
    //Aggiorna animazione degli sprite
    handleAnimations(deltaTime);
    //Verifica le collisioni
    handleCollisions();

    //Aggiorna gli sprite
    player.update(deltaTime);
    fire.update(deltaTime);
    pumpkin.update(deltaTime);
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

    PhysicsSystem::applyGravity(player, deltaTime);

    handlePlayerHorizontalMovement(isKeyPressedA, isKeyPressedD, deltaTime);
    handlePlayerJump(isKeyPressedW, deltaTime);

    std::vector<CollisionManager::CollisionResult> collisions = collisionManager.checkMapCollision(player, gameMap.getMapHitboxes());
    for (const auto& collision : collisions) {
        if (collision.hasCollision) {
            handleCollisionMap(collision.direction);
        }
    }


    // Applica la gravità al giocatore


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

void GamingState::handlePlayerJump(bool isKeyPressedW, float deltaTime) {
    if (isKeyPressedW && !player.isJumping()) {
        // Inizia il salto
        sf::Vector2f velocity = player.getVelocity();
        player.setAccelerationY(-JUMP_FORCE * deltaTime); // Imposta la velocità iniziale verso l'alto
        player.setJumping(true);
    }

   /*sf::Vector2f position = player.getPosition();
    if (position.y <= player.getHitbox().height) {
        position.y = std::max(position.y, 0.0f); // Assicura che il giocatore non vada sotto la mappa
        player.setPosition(position);
        player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
        player.setAcceleration(sf::Vector2f(player.getAcceleration().x, 0));
        player.setJumping(false);
        PhysicsSystem::standOn(player, deltaTime);
        std::cout<<"Collisione con la mappa";
    }else{
        position.y += player.getVelocity().y * deltaTime;
        player.setPosition(position);
    }*/

    sf::Vector2f currentVelocity = player.getVelocity();
    currentVelocity.y += player.getAcceleration().y * deltaTime;
    clampPlayerYVelocity(currentVelocity);
    player.setVerticalVelocity(currentVelocity.y);
}



void GamingState::handleAnimations(float deltaTime) {
    bool isKeyPressedA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool isKeyPressedD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isKeyPressedW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool isJumping = isKeyPressedW;
    bool isMovingHorizontally = isKeyPressedA || isKeyPressedD;
    bool isFalling = player.getVelocity().y > 0;
    bool isOnGround = player.getVelocity().y == 0;
    bool isIdle = player.getVelocity().x == 0 && isOnGround;

    if (isJumping) {
        // Se il player sta saltando, visualizza l'animazione di salto
        textureManager.updateAnimation("Player", "Jumping", deltaTime, player);
    } else if (isFalling) {
        // Se il player sta cadendo (in aria con una velocità verso il basso), visualizza l'animazione di caduta
        textureManager.updateAnimation("Player", "Falling", deltaTime, player);
    } else if (isMovingHorizontally && isOnGround) {
        // Se il player si sta muovendo orizzontalmente ed è sul terreno, visualizza l'animazione di corsa
        textureManager.updateAnimation("Player", "Running", deltaTime, player);
    } else if (isIdle) {
        // Se il player non si sta muovendo, visualizza l'animazione d'inattività
        textureManager.updateAnimation("Player", "Idle", deltaTime, player);
    }

    handleFireBallsAnimations(deltaTime);
}


void  GamingState::handleCollisionMap(CollisionManager::CollisionDirection direction) {
    switch (direction) {
        case CollisionManager::CollisionDirection::Top:
            std::cout << "Collisione con la parte superiore della piattaforma" << std::endl;
            player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
            break;
        case CollisionManager::CollisionDirection::Bottom:
            std::cout << "Collisione con la parte inferiore della piattaforma" << std::endl;
            break;
        case CollisionManager::CollisionDirection::Left:
            std::cout << "Collisione sul lato sinistro" << std::endl;
            player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
            break;
        case CollisionManager::CollisionDirection::Right:
            std::cout << "Collisione sul lato destro" << std::endl;
            player.setVelocity(sf::Vector2f(0, player.getVelocity().y));
            break;
        case CollisionManager::CollisionDirection::None:
            break;
    }
}


void GamingState::loadAllTextures() {
    setTextureForPlayer();
    setTextureForFire();
    //Aggiungi altre texture
}

void GamingState::setTextureForPlayer() {

    std::map<std::string, AnimationConfig> playerAnimations = {
            {"Running", {PLAYER_RUNNING_PATH, PLAYER_RUNNING_TEXTURES, PLAYER_RUNNING_MIN_FRAME_DURATION, PLAYER_RUNNING_MAX_FRAME_DURATION, true}},
            {"Jumping", {PLAYER_JUMPING_PATH, PLAYER_JUMPING_TEXTURES, PLAYER_RUNNING_MIN_FRAME_DURATION, PLAYER_RUNNING_MAX_FRAME_DURATION, true}},
            {"Idle",    {PLAYER_IDLE_PATH,    PLAYER_IDLE_TEXTURES,    PLAYER_RUNNING_MIN_FRAME_DURATION,    PLAYER_RUNNING_MIN_FRAME_DURATION,    false}},
            {"Falling", {PLAYER_FALLING_PATH, PLAYER_FALLING_TEXTURES, PLAYER_FALLING_MIN_FRAME_DURATION, PLAYER_FALLING_MAX_FRAME_DURATION, false}}};


    textureManager.loadEntityTextures("Player", playerAnimations);

// Imposta la texture iniziale e la posizione del player
    player.setTexture(textureManager.getTexture("Player", "Idle", 0));
    player.setPosition(sf::Vector2f(100, 200));

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

void GamingState::clampPlayerYVelocity(sf::Vector2f &velocity) {
    velocity.y = std::clamp(velocity.y, -PLAYER_MAX_SPEED, PLAYER_MAX_SPEED);
}


void GamingState::handleCollisions() {
    //Prova collisioni con i nemici
    //std::vector<Entity*> colliders;
    //colliders.push_back(&pumpkin);
    //Entity* collider = CollisionManager::handleCircleEnemy(player, colliders);
    if (CollisionManager::checkCollision(player.getHitbox(), pumpkin.getHitbox())) {
        std::cout << "Collisione " ;
    }

   /* if (CollisionManager::checkMapCollision(player, gameMap.getMapHitboxes())) {
        std::cout << "Collisione con la mappa";
        player.setVelocity(sf::Vector2f(player.getVelocity().x, 0));
    }*/
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






