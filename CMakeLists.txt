cmake_minimum_required(VERSION 3.19)
project(projekt_asteroid)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekt_asteroid main.cpp GameSetup.h SpaceObject.cpp SpaceObject.h GameEngine.cpp GameEngine.h
        Asteroid.cpp Asteroid.h Player.cpp Player.h Menu.cpp Menu.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(projekt_asteroid ${SFML_LIBRARIES})
endif()