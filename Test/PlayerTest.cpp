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
    player.setAccelerationX(10);
    player.update(0.5);
    EXPECT_FLOAT_EQ(player.getPosition().x, 2.5); // La posizione iniziale è 0, quindi dopo 0.5 secondi la posizione è 2.5 perchè nel update viene moltiplicato per il deltaTime sia
                                                            // la velocità che l'accelerazione
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

//TODO ( Sistemare manipolazione del test)

TEST_F(PlayerTest, HealthManipulation) {
    int initialHealth = player.getHealth();
    player.setHealth(initialHealth - 10);
    EXPECT_EQ(player.getHealth(), initialHealth - 10);
    player.setHealth(initialHealth + 10);
    EXPECT_EQ(player.getHealth(), initialHealth);
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

    EXPECT_FLOAT_EQ(player.getOrigin().x, initialPosition.x + initialVelocity.x * deltaTime);
    EXPECT_FLOAT_EQ(player.getOrigin().y, initialPosition.y + initialVelocity.y * deltaTime);

    // Ora, aggiungi un'accelerazione e verifica come cambia la posizione
    sf::Vector2f acceleration(10.0f, 0.0f);  // Accelerazione orizzontale di 10 unità/s^2
    player.setAcceleration(acceleration);

    initialPosition = player.getOrigin();
    player.update(deltaTime);  // Aggiorna di nuovo per 1 secondo

    float expectedPositionX = initialPosition.x + initialVelocity.x * deltaTime + 0.5f * acceleration.x * deltaTime * deltaTime;
    EXPECT_FLOAT_EQ(player.getOrigin().x, expectedPositionX);
    EXPECT_FLOAT_EQ(player.getOrigin().y, initialPosition.y);  // La posizione verticale non dovrebbe cambiare in questo test
}

