//
// Created by tudor on 04/10/2023.
//

#include "../GUI/Entity.h"
#include <iostream>

class PhysicsSystem {
public:
    static const float GRAVITY;

    static void applyGravity(Entity& entity);

    static void standOn(Entity &entity);
};

