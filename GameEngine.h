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
    RenderWindow window;
    std::list<Asteroid> asteroids;
    std::list<SpaceObject> bullets;
    Player player;
    int gameLevel;
    Text scoreText;
    Font font;
    int xBombs = XBOMBS;



    void gameInit();

    int game(RenderWindow &window);

    void newBullet();

    void spawnAsteroid();

    int bulletCollision();

    void spawnSmallerAsteroid(Asteroid asteroid);

    void playerCollision();

    void movePlayer(RenderWindow &window);

    void moveBullets(RenderWindow &renderWindow);

    void moveAsteroids(RenderWindow &renderWindow);

    void eventHandler(RenderWindow &renderWindow, const Event &event);

    void newXBomb();
};


#endif //PROJEKT_ASTEROID_GAMEENGINE_H
