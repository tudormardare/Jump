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

TEST_F(GamingStateTest, Render) {
    ASSERT_NO_THROW(gamingState->render(window));
}
