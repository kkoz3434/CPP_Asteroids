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
#include "Player.h"

using namespace sf;

class GameEngine {
public:
    RenderWindow gameWindow;
    std::list<Asteroid> asteroids;
    std::list<SpaceObject> bullets;
    Player player;
    int gameLevel;

    GameEngine();

    void game_init();

    void game();

    void newBullet();

    void spawnAsteroid();

    int bulletCollision();

    void spawnSmallerAsteroid(Asteroid asteroid);

    void playerCollision();

    void movePlayer(RenderWindow &gameWindow);

    void moveBullets(RenderWindow &gameWindow);

    void moveAsteroids(RenderWindow &gameWindow);
};


#endif //PROJEKT_ASTEROID_GAMEENGINE_H
