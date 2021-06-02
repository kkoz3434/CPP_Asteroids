//
// Created by kkoz34 on 02.06.2021.
//

#ifndef PROJEKT_ASTEROID_GAMEENGINE_H
#define PROJEKT_ASTEROID_GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <valarray>
#include "GameSetup.h"
#include "Asteroid.h"

using namespace sf;

class GameEngine {
public:
    RenderWindow gameWindow;
    std::list<Asteroid> asteroids;
    //Player player;

    GameEngine();

    void game_init();

    void game_loop();
};


#endif //PROJEKT_ASTEROID_GAMEENGINE_H