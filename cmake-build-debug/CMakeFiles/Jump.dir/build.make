# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/denis/CLionProjects/Jump

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/denis/CLionProjects/Jump/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Jump.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Jump.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Jump.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Jump.dir/flags.make

CMakeFiles/Jump.dir/main.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/main.cpp.o: /Users/denis/CLionProjects/Jump/main.cpp
CMakeFiles/Jump.dir/main.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Jump.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/main.cpp.o -MF CMakeFiles/Jump.dir/main.cpp.o.d -o CMakeFiles/Jump.dir/main.cpp.o -c /Users/denis/CLionProjects/Jump/main.cpp

CMakeFiles/Jump.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/main.cpp > CMakeFiles/Jump.dir/main.cpp.i

CMakeFiles/Jump.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/main.cpp -o CMakeFiles/Jump.dir/main.cpp.s

CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o: /Users/denis/CLionProjects/Jump/Application/JumperApplication.cpp
CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o -MF CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o.d -o CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o -c /Users/denis/CLionProjects/Jump/Application/JumperApplication.cpp

CMakeFiles/Jump.dir/Application/JumperApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/Application/JumperApplication.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/Application/JumperApplication.cpp > CMakeFiles/Jump.dir/Application/JumperApplication.cpp.i

CMakeFiles/Jump.dir/Application/JumperApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/Application/JumperApplication.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/Application/JumperApplication.cpp -o CMakeFiles/Jump.dir/Application/JumperApplication.cpp.s

CMakeFiles/Jump.dir/Application/GameState.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/Application/GameState.cpp.o: /Users/denis/CLionProjects/Jump/Application/GameState.cpp
CMakeFiles/Jump.dir/Application/GameState.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Jump.dir/Application/GameState.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/Application/GameState.cpp.o -MF CMakeFiles/Jump.dir/Application/GameState.cpp.o.d -o CMakeFiles/Jump.dir/Application/GameState.cpp.o -c /Users/denis/CLionProjects/Jump/Application/GameState.cpp

CMakeFiles/Jump.dir/Application/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/Application/GameState.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/Application/GameState.cpp > CMakeFiles/Jump.dir/Application/GameState.cpp.i

CMakeFiles/Jump.dir/Application/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/Application/GameState.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/Application/GameState.cpp -o CMakeFiles/Jump.dir/Application/GameState.cpp.s

CMakeFiles/Jump.dir/Application/MenuState.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/Application/MenuState.cpp.o: /Users/denis/CLionProjects/Jump/Application/MenuState.cpp
CMakeFiles/Jump.dir/Application/MenuState.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Jump.dir/Application/MenuState.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/Application/MenuState.cpp.o -MF CMakeFiles/Jump.dir/Application/MenuState.cpp.o.d -o CMakeFiles/Jump.dir/Application/MenuState.cpp.o -c /Users/denis/CLionProjects/Jump/Application/MenuState.cpp

CMakeFiles/Jump.dir/Application/MenuState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/Application/MenuState.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/Application/MenuState.cpp > CMakeFiles/Jump.dir/Application/MenuState.cpp.i

CMakeFiles/Jump.dir/Application/MenuState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/Application/MenuState.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/Application/MenuState.cpp -o CMakeFiles/Jump.dir/Application/MenuState.cpp.s

CMakeFiles/Jump.dir/Application/PauseState.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/Application/PauseState.cpp.o: /Users/denis/CLionProjects/Jump/Application/PauseState.cpp
CMakeFiles/Jump.dir/Application/PauseState.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Jump.dir/Application/PauseState.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/Application/PauseState.cpp.o -MF CMakeFiles/Jump.dir/Application/PauseState.cpp.o.d -o CMakeFiles/Jump.dir/Application/PauseState.cpp.o -c /Users/denis/CLionProjects/Jump/Application/PauseState.cpp

CMakeFiles/Jump.dir/Application/PauseState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/Application/PauseState.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/Application/PauseState.cpp > CMakeFiles/Jump.dir/Application/PauseState.cpp.i

CMakeFiles/Jump.dir/Application/PauseState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/Application/PauseState.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/Application/PauseState.cpp -o CMakeFiles/Jump.dir/Application/PauseState.cpp.s

CMakeFiles/Jump.dir/Application/SettingsState.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/Application/SettingsState.cpp.o: /Users/denis/CLionProjects/Jump/Application/SettingsState.cpp
CMakeFiles/Jump.dir/Application/SettingsState.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Jump.dir/Application/SettingsState.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/Application/SettingsState.cpp.o -MF CMakeFiles/Jump.dir/Application/SettingsState.cpp.o.d -o CMakeFiles/Jump.dir/Application/SettingsState.cpp.o -c /Users/denis/CLionProjects/Jump/Application/SettingsState.cpp

CMakeFiles/Jump.dir/Application/SettingsState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/Application/SettingsState.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/Application/SettingsState.cpp > CMakeFiles/Jump.dir/Application/SettingsState.cpp.i

CMakeFiles/Jump.dir/Application/SettingsState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/Application/SettingsState.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/Application/SettingsState.cpp -o CMakeFiles/Jump.dir/Application/SettingsState.cpp.s

CMakeFiles/Jump.dir/Application/PlayingState.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/Application/PlayingState.cpp.o: /Users/denis/CLionProjects/Jump/Application/PlayingState.cpp
CMakeFiles/Jump.dir/Application/PlayingState.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Jump.dir/Application/PlayingState.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/Application/PlayingState.cpp.o -MF CMakeFiles/Jump.dir/Application/PlayingState.cpp.o.d -o CMakeFiles/Jump.dir/Application/PlayingState.cpp.o -c /Users/denis/CLionProjects/Jump/Application/PlayingState.cpp

CMakeFiles/Jump.dir/Application/PlayingState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/Application/PlayingState.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/Application/PlayingState.cpp > CMakeFiles/Jump.dir/Application/PlayingState.cpp.i

CMakeFiles/Jump.dir/Application/PlayingState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/Application/PlayingState.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/Application/PlayingState.cpp -o CMakeFiles/Jump.dir/Application/PlayingState.cpp.s

CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o: /Users/denis/CLionProjects/Jump/GUI/MenuButton.cpp
CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o -MF CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o.d -o CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o -c /Users/denis/CLionProjects/Jump/GUI/MenuButton.cpp

CMakeFiles/Jump.dir/GUI/MenuButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/GUI/MenuButton.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/GUI/MenuButton.cpp > CMakeFiles/Jump.dir/GUI/MenuButton.cpp.i

CMakeFiles/Jump.dir/GUI/MenuButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/GUI/MenuButton.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/GUI/MenuButton.cpp -o CMakeFiles/Jump.dir/GUI/MenuButton.cpp.s

CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o: CMakeFiles/Jump.dir/flags.make
CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o: /Users/denis/CLionProjects/Jump/Controllers/CollisionManager.cpp
CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o: CMakeFiles/Jump.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o -MF CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o.d -o CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o -c /Users/denis/CLionProjects/Jump/Controllers/CollisionManager.cpp

CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denis/CLionProjects/Jump/Controllers/CollisionManager.cpp > CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.i

CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denis/CLionProjects/Jump/Controllers/CollisionManager.cpp -o CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.s

# Object files for target Jump
Jump_OBJECTS = \
"CMakeFiles/Jump.dir/main.cpp.o" \
"CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o" \
"CMakeFiles/Jump.dir/Application/GameState.cpp.o" \
"CMakeFiles/Jump.dir/Application/MenuState.cpp.o" \
"CMakeFiles/Jump.dir/Application/PauseState.cpp.o" \
"CMakeFiles/Jump.dir/Application/SettingsState.cpp.o" \
"CMakeFiles/Jump.dir/Application/PlayingState.cpp.o" \
"CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o" \
"CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o"

# External object files for target Jump
Jump_EXTERNAL_OBJECTS =

Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/main.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/Application/JumperApplication.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/Application/GameState.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/Application/MenuState.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/Application/PauseState.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/Application/SettingsState.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/Application/PlayingState.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/GUI/MenuButton.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/Controllers/CollisionManager.cpp.o
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/build.make
Jump.app/Contents/MacOS/Jump: /usr/local/lib/libsfml-graphics.2.5.1.dylib
Jump.app/Contents/MacOS/Jump: /usr/local/lib/libsfml-audio.2.5.1.dylib
Jump.app/Contents/MacOS/Jump: /usr/local/lib/libsfml-network.2.5.1.dylib
Jump.app/Contents/MacOS/Jump: /usr/local/lib/libsfml-window.2.5.1.dylib
Jump.app/Contents/MacOS/Jump: /usr/local/lib/libsfml-system.2.5.1.dylib
Jump.app/Contents/MacOS/Jump: CMakeFiles/Jump.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Jump.app/Contents/MacOS/Jump"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Jump.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Jump.dir/build: Jump.app/Contents/MacOS/Jump
.PHONY : CMakeFiles/Jump.dir/build

CMakeFiles/Jump.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Jump.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Jump.dir/clean

CMakeFiles/Jump.dir/depend:
	cd /Users/denis/CLionProjects/Jump/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/denis/CLionProjects/Jump /Users/denis/CLionProjects/Jump /Users/denis/CLionProjects/Jump/cmake-build-debug /Users/denis/CLionProjects/Jump/cmake-build-debug /Users/denis/CLionProjects/Jump/cmake-build-debug/CMakeFiles/Jump.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Jump.dir/depend

