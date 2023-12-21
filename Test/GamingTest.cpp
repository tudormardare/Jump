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

    gamingState.update(window, deltaTime);

    // TODO()Verifica che lo stato del gioco sia aggiornato come previsto
    // TODO()Ad esempio, controlla se il player si è mosso o se gli stati dei nemici sono cambiati
}

TEST_F(GamingStateTest, Render) {
    ASSERT_NO_THROW(gamingState.render(window));
}

