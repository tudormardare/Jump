//
// Created by tudor on 11/02/2024.
//

#ifndef JUMP_CONSTANTS_H
#define JUMP_CONSTANTS_H

//GamingState
#define GAMING_MAX_HEARTS 3
#define GAMING_MAX_FIREBALLS 12

//Player
#define PLAYER_HEALTH_MAX 3


//FireBall
#define FIREBALL_SPEED 0.5f
#define OFFSET_FIREBALL_X 115
#define OFFSET_FIREBALL_Y 90
#define FIRE_SCALE 2.f
#define PUMPKIN_SCALE 1.f


enum class eTimer {
    ePumpkinSpawn = 0,
    eHearthSpawn = 1,
    eHeartDespawn = 2,
    eBlinking = 3,
    eFireballSpawn = 4,
    ePlayerInvincible = 5,
};




#endif //JUMP_CONSTANTS_H
