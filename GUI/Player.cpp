#include <iostream>
#include "Player.h"

// Constructor
Player::Player() {
    initTexture();
    initSprite();
}

// Private functions
void Player::initTexture() {
    loadStandardTexture();
    loadAnimationTextures(PLAYER_RUNNING_PATH, PLAYER_RUNNING_TEXTURES, runningTextures);
    loadAnimationTextures(PLAYER_JUMPING_PATH, PLAYER_JUMPING_TEXTURES, jumpingTextures);
    loadAnimationTextures(PLAYER_IDLE_PATH, PLAYER_IDLE_TEXTURES, idleTextures);
    loadAnimationTextures(PLAYER_FALLING_PATH, PLAYER_FALLING_TEXTURES, fallingTextures);
}

void Player::loadStandardTexture() {
    if (!standardTexture.loadFromFile(PLAYER_TEXTURE)) {
        std::cout << "Error loading texture from file: " << PLAYER_TEXTURE << std::endl;
    }
}

void Player::loadAnimationTextures(const std::string& basePath, int textureCount, std::unique_ptr<sf::Texture> texturesArray[]) {
    for (int i = 0; i < textureCount; i++) {
        std::string path = basePath + std::to_string(i) + ".png";
        texturesArray[i] = std::make_unique<sf::Texture>();
        if (!texturesArray[i]->loadFromFile(path)) {
            std::cout << "Error loading texture from file: " << path << std::endl;
        }
    }
}

void Player::initSprite() {
    sprite.setTexture(standardTexture);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);

    setVelocity(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, 0));
}

// Movement
void Player::move(float dirX, float dirY) {
    sprite.move(dirX, dirY);
}

// Update & Draw
void Player::update(float deltaTime) {
    // Implement the update logic here
    velocity.x += acceleration.x * deltaTime;
    velocity.y += acceleration.y * deltaTime;

    // Aggiorna la posizione basandoti sulla velocità
    move(velocity.x * deltaTime, velocity.y * deltaTime);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

// Getters & Setters
sf::Vector2f Player::getAcceleration() const {
    return acceleration;
}

void Player::setAccelerationX(float newAccelerationX) {
    acceleration.x = newAccelerationX;
}


void Player::changeRunningTexture(int textureNumber) {
    if(textureNumber >= 0 && textureNumber < PLAYER_RUNNING_TEXTURES) {
        sprite.setTexture(*runningTextures[textureNumber]);
    }else {
        std::cerr << "Invalid texture number provided for running animation: " << textureNumber << std::endl;
        sprite.setTexture(standardTexture);
    }
}

sf::Vector2f Player::getOrigin() const {
    return sprite.getOrigin();
}

void Player::setHealth(int newHealth) {
    health = newHealth;
}

int Player::getHealth() const {
    return health;
}

void Player::setDefaultTexture() {
    sprite.setTexture(standardTexture);
}



void Player::inverse() {
    if(sprite.getScale().x > 0) {
        sprite.setScale(-PLAYER_SCALE, PLAYER_SCALE);
        inverseX = true;
    } else {
        sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
        inverseX = false;
    }
}

bool Player::getInverse() const {
    return inverseX;
}

void Player::changeJumpingTexture(int textureNumber) {
    if(textureNumber >= 0 && textureNumber < PLAYER_JUMPING_TEXTURES) {
        sprite.setTexture(*jumpingTextures[textureNumber]);
    } else {
        std::cerr << "Invalid texture number provided for jumping animation: " << textureNumber << std::endl;
        sprite.setTexture(standardTexture);
    }
}

void::Player::changeIdleTexture(int textNumber){
    if(textNumber >= 0 && textNumber < PLAYER_IDLE_TEXTURES) {
        sprite.setTexture(*idleTextures[textNumber]);
    } else {
        std::cerr << "Invalid texture number provided for idle animation: " << textNumber << std::endl;
        sprite.setTexture(standardTexture);
    }
}
void::Player::changeFallingTexture(int textNumber){
    if(textNumber >= 0 && textNumber < PLAYER_FALLING_TEXTURES) {
        sprite.setTexture(*fallingTextures[textNumber]);
    } else {
        std::cerr << "Invalid texture number provided for falling animation: " << textNumber << std::endl;
        sprite.setTexture(standardTexture);
    }
}

bool Player::isJumping() const {
    return jumping;
}

void Player::setJumping(bool jumping) {
    Player::jumping = jumping;
}

void Player::jump(float initialVelocity) {
    if (!jumping) { // Controlla se il giocatore non sta già saltando
        velocity.y = -initialVelocity; // Velocità negativa per muoversi verso l'alto
        jumping = true;
    }
}


