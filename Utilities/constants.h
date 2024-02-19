//
// Created by tudor on 11/02/2024.
//

#ifndef JUMP_CONSTANTS_H
#define JUMP_CONSTANTS_H

// Dimensioni e posizioni dei pulsanti di pausa
#define PAUSE_BUTTON_HEIGHT 75
#define PAUSE_RESUME_BUTTON_PATH "PNG/MenuButton/PlayButton.png"
#define PAUSE_QUIT_BUTTON_PATH "PNG/MenuButton/ExitButton.png"
#define PAUSE_BUTTON_WIDTH 300
#define PAUSE_BUTTON_HEIGHT 75
#define PAUSE_BUTTON_DISTANCE 100
#define PAUSE_BUTTONS_NUMBER 2
#define PAUSE_BUTTONS_PATH "PNG/MenuButton/Button.png"
#define PAUSE_MENU_BACKGROUND_PATH "PNG/Background/background.png"

// Dimensioni della finestra
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 675

// Dimensioni e posizioni dei pulsanti del menu
#define MENU_BUTTON_WIDTH 200
#define MENU_BUTTON_HEIGHT 75
#define MENU_BUTTON_DISTANCE 50
#define MENU_BUTTONS_NUMBER 3
#define MENU_SETTINGS_BUTTON_PATH "PNG/MenuButton/GuideButton.png"
#define MENU_PLAY_BUTTON_PATH "PNG/MenuButton/PlayButton.png"
#define MENU_EXIT_BUTTON_PATH "PNG/MenuButton/ExitButton.png"
#define MENU_BACKGROUND_PATH "PNG/Background/background.png"
#define GAMEOVER_BUTTON_PATH "PNG/MenuButton/PlayButton.png"
#define GAME_BACKGROUND_PATH "PNG/Background/background.png"

// Percorsi delle texture dei pulsanti del settings
#define SETTINGS_BUTTON_PATH "PNG/MenuButton/BackButton.png"
#define SETTINGS_BUTTON_WIDTH 200
#define SETTINGS_BUTTON_HEIGHT 450
#define SETTINGS_BUTTON_DISTANCE 100
#define SETTINGS_BUTTON_NUMBER 1
#define SETTINGS_MENU_BACKGROUND_PATH "PNG/KeybindingsGuide/Keybindings.png"

// Fire
#define FIRE_TEXTURE_PATH "PNG/Fire/1_"
#define FIRE_SCALE 2.f
#define FIRE_TEXTURES 60
#define FIRE_MIN_FRAME_DURATION 1.f
#define FIRE_MAX_FRAME_DURATION 1.f
#define FIRE_RECTANGLE_WIDTH 16
#define FIRE_RECTANGLE_HEIGHT 16
#define FIRE_DEFAULT_SPEED 20.f

// Heart
#define HEART_SPAWN_INTERVAL 5.f
#define HEART_FALL_SPEED 100.f
#define HEART_SCALE 1.f
#define HEART_TEXTURES 1
#define HEART_MIN_FRAME_DURATION 1.f
#define HEART_MAX_FRAME_DURATION 1.f
#define HEART_TEXTURE_PATH "PNG/Heart/Heart_1_"

#define GAME_FOREGROUND_PATH "PNG/Map-platforms/Map.png"

//Player
#define PLAYER_TEXTURE "PNG/Player/Player.png"
#define PLAYER_HEALTH 3
#define PLAYER_RUNNING_TEXTURES 6
#define PLAYER_JUMPING_TEXTURES 4
#define PLAYER_FALLING_TEXTURES 2
#define PLAYER_IDLE_TEXTURES 2
#define PLAYER_CRUNCH_TEXTURES 4
#define PLAYER_DEAD_TEXTURES 7
#define PLAYER_FALLING_PATH "PNG/Player/FallingTextures/adventurer-fall-0"
#define PLAYER_RUNNING_PATH "PNG/Player/RunningTextures/adventurer-run-0"
#define PLAYER_JUMPING_PATH "PNG/Player/JumpingTextures/adventurer-jump-0"
#define PLAYER_CRUNCH_PATH "PNG/Player/CrunchTextures/adventurer-crouch-0"
#define PLAYER_DEAD_PATH "PNG/Player/DieTextures/adventurer-die-0"
#define PLAYER_IDLE_PATH "PNG/Player/IdleTextures/adventurer-idle-0"
#define PLAYER_SCALE 2.f
#define PLAYER_ACCELERATION_RATE 200.f
#define PLAYER_MAX_SPEED 250.f
#define PLAYER_DECELERATION_RATE 5.f
#define PLAYER_RUNNING_MIN_FRAME_DURATION 0.6f
#define PLAYER_RUNNING_MAX_FRAME_DURATION 0.6f
#define PLAYER_JUMPING_MIN_FRAME_DURATION 0.3f
#define PLAYER_JUMPING_MAX_FRAME_DURATION 0.2f
#define PLAYER_IDLE_MIN_FRAME_DURATION 0.5f
#define PLAYER_IDLE_MAX_FRAME_DURATION 1.f
#define PLAYER_FALLING_MIN_FRAME_DURATION 0.5f
#define PLAYER_FALLING_MAX_FRAME_DURATION 1.f

// Pumpkin
#define PUMPKIN_TEXTURE_PATH "PNG/Pumpkin/Pumpkin_1_"
#define PUMPKIN_SCALE 1.f
#define PUMPKIN_TEXTURES 1
#define PUMPKIN_MIN_FRAME_DURATION 1.f
#define PUMPKIN_MAX_FRAME_DURATION 1.f
#define PUMPKIN_SPAWN_INTERVAL 5.f
#define PUMPKIN_SPEED 100.f


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
    ePlayerBlinking = 6,
};




#endif //JUMP_CONSTANTS_H
