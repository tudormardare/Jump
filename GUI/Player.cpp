#include <iostream>
#include "Player.h"

Player::Player() {
    initSprite();
}

void Player::initSprite() {
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setScale(PLAYER_SCALE, PLAYER_SCALE);
    maxSpeed = sf::Vector2f(PLAYER_MAX_SPEED , PLAYER_MAX_SPEED );
    setVelocity(sf::Vector2f(0, 0));
}

void Player::move(float dirX, float dirY) {
    sprite.move(dirX, dirY);
}

void Player::update(float deltaTime) {
    move(velocity.x , velocity.y );
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Player::setAccelerationX(float newAccelerationX) {
    acceleration.x = newAccelerationX;
}
void Player::setAccelerationY(float newAccelerationY) {
    acceleration.y = newAccelerationY;
}


sf::Vector2f Player::getOrigin() const {
    return sprite.getOrigin();
}

void Player::setHealth(int newHealth) {
    hp = newHealth;
    if (hp < 0) {
        hp = 0;
    }
    if (hp > hpMax) {
        hp = hpMax;
    }
}

int Player::getHealth() const {
    return hp;
}


void Player::inverse() {
    if (sprite.getScale().x > 0) {
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


bool Player::isJumping() const {
    return jumping;
}

void Player::jump(float initialVelocity) {
    if (!jumping) { // Controlla se il giocatore non sta già saltando
        velocity.y = -initialVelocity;
        jumping = true;
    }
}

void Player::setJumping(bool newJumping) {
    jumping = newJumping;
}

void Player::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    setCollisionRect();
}

void Player::takeDamage(const int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    if (hp > hpMax) {
        hp = hpMax;
    }
}


void Player::renderHealth(sf::RenderWindow &window) {
    sf::Font font;
    if (font.loadFromFile("PNG/TimerFont/TimerFont.TTF")) {
        sf::Text healthText;
        healthText.setFont(font);
        healthText.setCharacterSize(20);
        healthText.setFillColor(sf::Color::White);

        // Ottiene la salute del giocatore e la mostra
        healthText.setString("Health: " + std::to_string(hp) + "/" + std::to_string(hpMax));
        healthText.setPosition(10, 40);

        window.draw(healthText);
    } else {
        std::cerr << "Impossibile caricare il font per la salute del giocatore.\n";
    }
}




