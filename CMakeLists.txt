cmake_minimum_required(VERSION 3.20)
project(Jump)


add_executable(Jump main.cpp Application/JumperApplication.cpp Application/JumperApplication.h Application/GameState.cpp Application/GameState.h Application/MenuState.cpp Application/MenuState.h Application/PauseState.cpp Application/PauseState.h Application/SettingsState.cpp Application/SettingsState.h Application/PlayingState.cpp Application/PlayingState.h GUI/MenuButton.cpp GUI/MenuButton.h)

add_subdirectory(Test)

if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
    include_directories(${SFML_INCLUDE_DIRS})
    set_target_properties(Jumper PROPERTIES
            MACOSX_BUNDLE TRUE
            MACOSX_BUNDLE_BUNDLE_NAME Jump
            MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
            )
endif()

if (WIN32)
    set (SFML_STATIC_LIBRARIES TRUE)
    set (SFML_DIR C:/SFML/lib/cmake/SFML)
    find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
endif()

target_link_libraries(Jump sfml-system sfml-window sfml-graphics sfml-audio sfml-network)