//
// Created by kkoz34 on 02.06.2021.
//

#ifndef PROJEKT_ASTEROID_ASTEROID_H
#define PROJEKT_ASTEROID_ASTEROID_H


#include "SpaceObject.h"

class Asteroid {


public:
    Asteroid(SpaceObject object, int level=3);

    void update();

    SpaceObject object;

    Asteroid smallAsteroid(Asteroid asteroid);

    int level;
    int points;
};


#endif //PROJEKT_ASTEROID_ASTEROID_H
