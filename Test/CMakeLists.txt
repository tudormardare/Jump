# File sorgente per i test
set(TEST_SOURCE_FILES
        runAllTests.cpp
        CollisionTest.cpp
        CameraTest.cpp
        PlayerTest.cpp
        MapTest.cpp
        ../GUI/Map.cpp
        ../GUI/Player.cpp
        ../GUI/Entity.cpp
        ../Controllers/CollisionManager.cpp
        ../Controllers/CameraManager.cpp
        # Aggiungi altri file sorgente dei test qui
        )

# Configurazione Google Test
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Crea l'eseguibile per i test
add_executable(runAllTests ${TEST_SOURCE_FILES})

# Link delle librerie per i test
target_link_libraries(runAllTests gtest gtest_main sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Link file header
target_include_directories(runAllTests PRIVATE ../GUI/)
target_include_directories(runAllTests PRIVATE ../Controllers/)
