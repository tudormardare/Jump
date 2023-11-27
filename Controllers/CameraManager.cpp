//
// Created by Denis Jaupi on 27/11/23.
//

#include "CameraManager.h"

CameraManager::CameraManager(sf::View& camera) :
mainCamera(camera),
shakeDuration(0.0f),
shakeMagnitude(0.7f),
dampingSpeed(1.0f),
deltaTime(sf::seconds(0.1f)) {
}

void CameraManager::Update() {
    if (shakeDuration > 0) {
        int randomX = rand() % 5 - 2;
        int randomY = rand() % 5 - 2;
        mainCamera.move(sf::Vector2f(static_cast<float>(randomX), static_cast<float>(randomY)) * shakeMagnitude);

        shakeDuration -= deltaTime.asSeconds() * dampingSpeed;
    } else {
        shakeDuration = 0;
        mainCamera.setCenter(originalCameraCenter);
    }
}


void CameraManager::ShakeCamera(float duration) {
    originalCameraCenter = mainCamera.getCenter();
    shakeDuration = duration;
}

