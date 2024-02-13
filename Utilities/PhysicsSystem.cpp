//
// Created by tudor on 04/10/2023.
//

#include "PhysicsSystem.h"

const float PhysicsSystem::GRAVITY = 5.f;

void PhysicsSystem::applyGravity(Entity& entity) {
    float verticalAcceleration = entity.getAcceleration().y;
    verticalAcceleration += GRAVITY ;
    entity.setAcceleration(sf::Vector2f(entity.getAcceleration().x, verticalAcceleration));
}

void PhysicsSystem::standOn(Entity& entity) {
    entity.setAcceleration(sf::Vector2f(entity.getAcceleration().x, 0.f));
}
