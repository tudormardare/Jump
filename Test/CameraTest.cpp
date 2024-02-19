//
// Created by Denis Jaupi on 27/11/23.
//

#include <SFML/Graphics.hpp>
#include "gtest/gtest.h"
#include "../Controllers/CameraManager.h"


TEST(CameraManager, ShakeCamera) {
    sf::View view;
    CameraManager cameraManager(view);

    cameraManager.ShakeCamera(0.5f);

// Restituisce la durata dello shake
    EXPECT_FLOAT_EQ(cameraManager.GetShakeDuration(), 0.5f);
// Restituisce la posizione originale della camera
    EXPECT_EQ(cameraManager.GetOriginalCameraCenter(), view.getCenter());
}


TEST(CameraManager, Update) {
    sf::View view;
    CameraManager cameraManager(view);
    cameraManager.ShakeCamera(0.5f);


    for (int i = 0; i < 100; ++i)
        cameraManager.Update();
}

