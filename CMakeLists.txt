cmake_minimum_required(VERSION 3.20)
project(Jump)

# Abilita C++17
set(CMAKE_CXX_STANDARD 17)

add_executable(Jump main.cpp Application/JumperApplication.cpp Application/JumperApplication.h Application/GameState.cpp Application/GameState.h Application/MenuState.cpp Application/MenuState.h Application/PauseState.cpp Application/PauseState.h Application/GamingState.cpp Application/GamingState.h Application/SettingsState.cpp Application/SettingsState.h GUI/MenuButton.cpp GUI/MenuButton.h Controllers/CollisionManager.cpp Controllers/CollisionManager.h GUI/Player.h GUI/Player.cpp GUI/Entity.h GUI/Entity.cpp GUI/Map.cpp GUI/Map.h Utilities/PhysicsSystem.cpp Utilities/PhysicsSystem.h Utilities/TextureManager.cpp Utilities/TextureManager.h)

add_subdirectory(Test)

if (APPLE)
    find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
    include_directories(${SFML_INCLUDE_DIRS})
    set_target_properties(Jump PROPERTIES
            MACOSX_BUNDLE TRUE
            MACOSX_BUNDLE_BUNDLE_NAME Jump
            MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
            )
    target_link_libraries(Jump sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
endif()

if (WIN32)
    set (SFML_STATIC_LIBRARIES TRUE)
    set (SFML_DIR C:/SFML/lib/cmake/SFML)
    find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
    target_link_libraries(Jump sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
endif()



