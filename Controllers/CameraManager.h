//
// Created by Denis Jaupi on 27/11/23.
//

#ifndef JUMP_CAMERAMANAGER_H
#define JUMP_CAMERAMANAGER_H


#include <SFML/Graphics/View.hpp>
#include <SFML/System/Time.hpp>

class CameraManager {

public:
    CameraManager(sf::View& camera);

    void Update();
    void ShakeCamera(float duration);

private:
    sf::View& mainCamera;
    float shakeDuration;
    float shakeMagnitude;
    float dampingSpeed;
    sf::Time deltaTime;
    sf::Vector2f originalCameraCenter;

};


#endif //JUMP_CAMERAMANAGER_H
