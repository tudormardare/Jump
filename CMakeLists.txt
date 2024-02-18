cmake_minimum_required(VERSION 3.20)
project(Jump)

# Abilita C++17
set(CMAKE_CXX_STANDARD 17)

# File sorgente
set(SOURCE_FILES
        main.cpp
        Application/JumperApplication.cpp
        Application/GameState.cpp
        Application/MenuState.cpp
        Application/PauseState.cpp
        Application/GamingState.cpp
        Application/SettingsState.cpp
        GUI/MenuButton.cpp
        Controllers/CollisionManager.cpp
        GUI/Player.cpp
        GUI/Entity.cpp
        GUI/Fire.h
        GUI/Fire.cpp
        GUI/Ghost.cpp
        GUI/Ghost.h
        GUI/Pumpkin.cpp
        GUI/Pumpkin.h
        GUI/Map.cpp
        Utilities/TextureManager.cpp
        Utilities/PhysicsSystem.cpp
        Controllers/CameraManager.cpp
        Controllers/CameraManager.h
        GUI/Timer.cpp
        GUI/Timer.h
        GUI/Heart.cpp
        GUI/Heart.h
	Utilities/TimerClass.cpp
        Utilities/TimerClass.h
        Application/GameOverState.cpp
        Application/GameOverState.h

)



add_executable(Jump ${SOURCE_FILES})

# Configurazioni per macOS
if (APPLE)
    find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
    target_include_directories(Jump PRIVATE ${SFML_INCLUDE_DIRS})
    set_target_properties(Jump PROPERTIES
            MACOSX_BUNDLE TRUE
            MACOSX_BUNDLE_BUNDLE_NAME Jump
            MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
            )
endif()

# Configurazioni per Windows
if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR C:/SFML/lib/cmake/SFML)
    find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
endif()



target_link_libraries(Jump sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Aggiungi la directory dei test
add_subdirectory(Test)
