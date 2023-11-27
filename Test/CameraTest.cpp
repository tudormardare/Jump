#include "CameraManager.h"

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

EXPECT_FLOAT_EQ(cameraManager.GetShakeDuration(), 0.5f);
EXPECT_EQ(cameraManager.GetOriginalCameraCenter(), view.getCenter());
}



