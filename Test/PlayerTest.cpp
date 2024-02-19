#include "gtest/gtest.h"
#include "../GUI/Player.h"

class PlayerTest : public ::testing::Test {
protected:
    Player player;

    void SetUp() override {
        //Da inserire valori di configurazione per i test
    }

    void TearDown() override {
        //Funzione che serve per rilasciare eventuali reisorse utilizzate dai singoli test (capire se può tornarci utile)
    }
};

TEST_F(PlayerTest, AccelerationEffect) {
    player.setVelocity(sf::Vector2f(1.25f, 0.0f));
    player.setAccelerationX(10.0f);

    float deltaTime = 0.5f;
    player.update(deltaTime);


    float expectedVelocityX = player.getAcceleration().x * deltaTime;
    float expectedPositionX = 0.5f * expectedVelocityX * deltaTime;

    EXPECT_FLOAT_EQ(player.getPosition().x, expectedPositionX);
}

TEST_F(PlayerTest, JumpingState) {
    EXPECT_FALSE(player.isJumping());
    player.jump(10);
    EXPECT_TRUE(player.isJumping());
}

TEST_F(PlayerTest, InverseDirection) {
    bool initialInverseState = player.getInverse();
    player.inverse();
    EXPECT_NE(player.getInverse(), initialInverseState);
    player.inverse();
    EXPECT_EQ(player.getInverse(), initialInverseState);
}

TEST_F(PlayerTest, HealthInitialization) {
    EXPECT_EQ(player.getHealth(), PLAYER_HEALTH);
}

TEST_F(PlayerTest, JumpingInitialState) {
    EXPECT_FALSE(player.isJumping());
}

TEST_F(PlayerTest, InverseDirectionInitialState) {
    EXPECT_EQ(player.getInverse(), false);
}

TEST_F(PlayerTest, TakeDamage) {
    int initialHealth = player.getHealth();
    player.takeDamage();
    EXPECT_EQ(player.getHealth(), initialHealth - 1);
}

TEST_F(PlayerTest, GainHealth) {
    int initialHealth = player.getHealth() - 1;
    player.gainHealth();
    EXPECT_EQ(player.getHealth(), initialHealth + 1);
}

TEST_F(PlayerTest, InverseDirectionToggle) {
    bool initialInverseState = player.getInverse();
    player.inverse();
    EXPECT_NE(player.getInverse(), initialInverseState);

    player.inverse();
    EXPECT_EQ(player.getInverse(), initialInverseState);
}

TEST_F(PlayerTest, JumpingStateToggle) {
    EXPECT_FALSE(player.isJumping());
    player.jump(10.0f);
    EXPECT_TRUE(player.isJumping());

    player.setJumping(false);
    EXPECT_FALSE(player.isJumping());
}

TEST_F(PlayerTest, HealthManipulation) {
    int initialHealth = player.getHealth();
    player.setHealth(initialHealth - 10);
    EXPECT_EQ(player.getHealth(), 0);
}

TEST_F(PlayerTest, TextureSetting) {
    sf::Texture newTexture;
    newTexture.loadFromFile("PNG/Player/Player.png");
    player.setTexture(newTexture);
    EXPECT_EQ(player.getSprite().getTexture(), &newTexture);
}

TEST_F(PlayerTest, UpdateFunctionality) {
    // Imposta una velocità iniziale e verifica la posizione dopo l'aggiornamento
    sf::Vector2f initialPosition = player.getOrigin();
    sf::Vector2f initialVelocity(5.0f, 0.0f);  // Velocità orizzontale di 5 unità/s
    player.setVelocity(initialVelocity);

    float deltaTime = 1.0f;  // Simuliamo 1 secondo di gioco
    player.update(deltaTime);

    float expectedPositionX = initialPosition.x + initialVelocity.x * deltaTime;
    float expectedPositionY = initialPosition.y + initialVelocity.y * deltaTime;

    EXPECT_FLOAT_EQ(player.getPosition().x, expectedPositionX);
    EXPECT_FLOAT_EQ(player.getPosition().y, expectedPositionY);

    // Ora, aggiungi un'accelerazione e verifica come cambia la posizione
    sf::Vector2f acceleration(10.0f, 0.0f);  // Accelerazione orizzontale di 10 unità/s^2
    player.setAccelerationX(acceleration.x);

    initialPosition = player.getOrigin();
    player.update(deltaTime);  // Aggiorna di nuovo per 1 secondo

    float expectedPositionXWithAcceleration = initialPosition.x + initialVelocity.x * deltaTime + 0.5f * acceleration.x * deltaTime * deltaTime;
    float expectedPositionYWithAcceleration = initialPosition.y + initialVelocity.y * deltaTime;

    EXPECT_FLOAT_EQ(player.getPosition().x, expectedPositionXWithAcceleration);
    EXPECT_FLOAT_EQ(player.getPosition().y, expectedPositionYWithAcceleration);
}

