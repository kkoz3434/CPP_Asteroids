# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/kkoz34/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kkoz34/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/projekt_asteroid.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projekt_asteroid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projekt_asteroid.dir/flags.make

CMakeFiles/projekt_asteroid.dir/main.cpp.o: CMakeFiles/projekt_asteroid.dir/flags.make
CMakeFiles/projekt_asteroid.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projekt_asteroid.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projekt_asteroid.dir/main.cpp.o -c "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/main.cpp"

CMakeFiles/projekt_asteroid.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projekt_asteroid.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/main.cpp" > CMakeFiles/projekt_asteroid.dir/main.cpp.i

CMakeFiles/projekt_asteroid.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projekt_asteroid.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/main.cpp" -o CMakeFiles/projekt_asteroid.dir/main.cpp.s

CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.o: CMakeFiles/projekt_asteroid.dir/flags.make
CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.o: ../SpaceObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.o -c "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/SpaceObject.cpp"

CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/SpaceObject.cpp" > CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.i

CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/SpaceObject.cpp" -o CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.s

CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.o: CMakeFiles/projekt_asteroid.dir/flags.make
CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.o: ../GameEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.o -c "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/GameEngine.cpp"

CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/GameEngine.cpp" > CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.i

CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/GameEngine.cpp" -o CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.s

CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.o: CMakeFiles/projekt_asteroid.dir/flags.make
CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.o: ../Asteroid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.o -c "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/Asteroid.cpp"

CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/Asteroid.cpp" > CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.i

CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/Asteroid.cpp" -o CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.s

CMakeFiles/projekt_asteroid.dir/Player.cpp.o: CMakeFiles/projekt_asteroid.dir/flags.make
CMakeFiles/projekt_asteroid.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/projekt_asteroid.dir/Player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projekt_asteroid.dir/Player.cpp.o -c "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/Player.cpp"

CMakeFiles/projekt_asteroid.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projekt_asteroid.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/Player.cpp" > CMakeFiles/projekt_asteroid.dir/Player.cpp.i

CMakeFiles/projekt_asteroid.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projekt_asteroid.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/Player.cpp" -o CMakeFiles/projekt_asteroid.dir/Player.cpp.s

# Object files for target projekt_asteroid
projekt_asteroid_OBJECTS = \
"CMakeFiles/projekt_asteroid.dir/main.cpp.o" \
"CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.o" \
"CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.o" \
"CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.o" \
"CMakeFiles/projekt_asteroid.dir/Player.cpp.o"

# External object files for target projekt_asteroid
projekt_asteroid_EXTERNAL_OBJECTS =

projekt_asteroid: CMakeFiles/projekt_asteroid.dir/main.cpp.o
projekt_asteroid: CMakeFiles/projekt_asteroid.dir/SpaceObject.cpp.o
projekt_asteroid: CMakeFiles/projekt_asteroid.dir/GameEngine.cpp.o
projekt_asteroid: CMakeFiles/projekt_asteroid.dir/Asteroid.cpp.o
projekt_asteroid: CMakeFiles/projekt_asteroid.dir/Player.cpp.o
projekt_asteroid: CMakeFiles/projekt_asteroid.dir/build.make
projekt_asteroid: /usr/lib/x86_64-linux-gnu/libsfml-system.so
projekt_asteroid: /usr/lib/x86_64-linux-gnu/libsfml-window.so
projekt_asteroid: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
projekt_asteroid: /usr/lib/x86_64-linux-gnu/libsfml-network.so
projekt_asteroid: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
projekt_asteroid: CMakeFiles/projekt_asteroid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable projekt_asteroid"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projekt_asteroid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projekt_asteroid.dir/build: projekt_asteroid

.PHONY : CMakeFiles/projekt_asteroid.dir/build

CMakeFiles/projekt_asteroid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projekt_asteroid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projekt_asteroid.dir/clean

CMakeFiles/projekt_asteroid.dir/depend:
	cd "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid" "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid" "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug" "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug" "/media/kkoz34/Dysk lokalny/4 semestr/cpp laby/projekt_asteroid/cmake-build-debug/CMakeFiles/projekt_asteroid.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/projekt_asteroid.dir/depend

