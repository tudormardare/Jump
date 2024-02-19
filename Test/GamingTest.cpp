#include <gtest/gtest.h>
#include "GamingState.h"


class GamingStateTest : public ::testing::Test {
protected:
    sf::RenderWindow window;
    GamingState* gamingState;

    void SetUp() override {
        gamingState = &GamingState::GetInstance(window);
        // Qui puoi caricare una texture di prova e impostare le hitbox di prova
    }

    void TearDown() override {
        // Non c'è bisogno di cancellare gamingState perché è un singleton
    }
};


TEST_F(GamingStateTest, HandleEvents) {
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::Escape;

    gamingState->handleEvents(window, event);

}

TEST_F(GamingStateTest, Update) {
    float deltaTime = 0.016f;

    // Salva lo stato iniziale del giocatore e degli Sprite degli avversari
    sf::Vector2f initialPlayerPosition = gamingState->getPlayer().getPosition();
    sf::Vector2f initialPumpkinPosition = gamingState->getPumpkin().getPosition();
    // Salva lo stato iniziale di altri elementi, se necessario

    gamingState->update(window, deltaTime);

    // Verifica che il giocatore si sia mosso come previsto
    sf::Vector2f expectedPlayerPosition = initialPlayerPosition + gamingState->getPlayer().getVelocity() * deltaTime;
    float tolerance = 0.1f;
    EXPECT_NEAR(gamingState->getPlayer().getPosition().x, expectedPlayerPosition.x, tolerance);
    EXPECT_NEAR(gamingState->getPlayer().getPosition().y, expectedPlayerPosition.y, tolerance);


    // Verifica che lo stato degli Sprite degli avversari sia aggiornato come previsto
    sf::Vector2f expectedPumpkinPosition = initialPumpkinPosition + gamingState->getPumpkin().getVelocity() * deltaTime;
    EXPECT_EQ(gamingState->getPumpkin().getPosition(), expectedPumpkinPosition);

}

TEST_F(GamingStateTest, Render) {
    ASSERT_NO_THROW(gamingState->render(window));
}
