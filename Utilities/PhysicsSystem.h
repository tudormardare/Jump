//
// Created by tudor on 04/10/2023.
//

#include "../GUI/Entity.h"

class PhysicsSystem {
public:
    static const float GRAVITY;

    static void applyGravity(Entity& entity, float deltaTime);
};

