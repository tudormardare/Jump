# File sorgente per i test
set(TEST_SOURCE_FILES
        runAllTests.cpp
        CollisionTest.cpp
        CameraTest.cpp
        PlayerTest.cpp
        MapTest.cpp
        ../GUI/Map.cpp
        ../GUI/Player.cpp
		../GUI/Fire.cpp
		../GUI/Pumpkin.cpp
        ../GUI/Entity.cpp
        ../Utilities/TextureManager.cpp
        ../Utilities/PhysicsSystem.cpp
		../GUI/Timer.cpp
		../GUI/Ball.cpp
		../GUI/Heart.cpp
		../Application/MenuState.cpp
		../Application/SettingsState.cpp
		../Application/PauseState.cpp
		../GUI/MenuButton.cpp


        # Aggiungi altri file sorgente dei test qui
        ../Application/GamingState.cpp
	../Controllers/CollisionManager.cpp
        ../Controllers/CameraManager.cpp GamingTest.cpp
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
target_include_directories(runAllTests PRIVATE ../Application/)
target_include_directories(runAllTests PRIVATE ../Utilities/)
