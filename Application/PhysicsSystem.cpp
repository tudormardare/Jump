//
// Created by tudor on 04/10/2023.
//

#include "PhysicsSystem.h"

const float PhysicsSystem::GRAVITY = -9.81f;

void PhysicsSystem::applyGravity(Entity& entity, float deltaTime) {
    float verticalVelocity = entity.getVerticalVelocity();
    verticalVelocity -= GRAVITY * deltaTime;
    entity.setVerticalVelocity(verticalVelocity);
    entity.move(0.f, verticalVelocity * deltaTime);
}
