//
// Created by tudor on 04/10/2023.
//

#include "PhysicsSystem.h"

const float PhysicsSystem::GRAVITY = -150.f;

void PhysicsSystem::applyGravity(Entity& entity, float deltaTime) {
    float verticalAcceleration = entity.getAcceleration().y;
    verticalAcceleration -= GRAVITY * deltaTime;
    entity.setVerticalVelocity(verticalAcceleration );
    entity.move(0.f, entity.getVerticalVelocity() * deltaTime);
}
