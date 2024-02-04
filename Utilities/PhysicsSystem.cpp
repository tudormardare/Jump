//
// Created by tudor on 04/10/2023.
//

#include <iostream>
#include "PhysicsSystem.h"

const float PhysicsSystem::GRAVITY = 5.f;

void PhysicsSystem::applyGravity(Entity& entity, float deltaTime) {
    float verticalAcceleration = entity.getAcceleration().y;
    verticalAcceleration += GRAVITY ;
    entity.setAcceleration(sf::Vector2f(entity.getAcceleration().x, verticalAcceleration));
}

void PhysicsSystem::standOn(Entity& entity, float deltaTime) {
    float verticalAcceleration = entity.getAcceleration().y;
    verticalAcceleration -= GRAVITY;
    entity.setAcceleration(sf::Vector2f(entity.getAcceleration().x, verticalAcceleration));
}
