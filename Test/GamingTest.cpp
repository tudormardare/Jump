#include <gtest/gtest.h>
#include "GamingState.h"

#include <gtest/gtest.h>
#include "GamingState.h"

class GamingStateTest : public ::testing::Test {
protected:
    sf::RenderWindow window;
    GamingState& gamingState;

    GamingStateTest() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test Window"),
                        gamingState(GamingState::GetInstance(window)) {}

    void SetUp() override {
        // Configurazione iniziale da aggiungere se vogliamo
    }

    void TearDown() override {
        // Pulizia dopo ogni test, se necessario
    }
};

TEST_F(GamingStateTest, HandleEvents) {
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::Escape;

    gamingState.handleEvents(window, event);


}

TEST_F(GamingStateTest, Update) {
    float deltaTime = 0.016f;

    // Salva lo stato iniziale del giocatore e degli Sprite degli avversari
    sf::Vector2f initialPlayerPosition = gamingState.getPlayer().getPosition();
    sf::Vector2f initialPumpkinPosition = gamingState.getPumpkin().getPosition();
    // Salva lo stato iniziale di altri elementi, se necessario

    gamingState.update(window, deltaTime);

    // Verifica che il giocatore si sia mosso come previsto
    sf::Vector2f expectedPlayerPosition = initialPlayerPosition + gamingState.getPlayer().getVelocity() * deltaTime;
    EXPECT_EQ(gamingState.getPlayer().getPosition(), expectedPlayerPosition);

    // Verifica che lo stato degli Sprite degli avversari sia aggiornato come previsto
    sf::Vector2f expectedPumpkinPosition = initialPumpkinPosition + gamingState.getPumpkin().getVelocity() * deltaTime;
    EXPECT_EQ(gamingState.getPumpkin().getPosition(), expectedPumpkinPosition);

}

TEST_F(GamingStateTest, Render) {
    ASSERT_NO_THROW(gamingState.render(window));
}
