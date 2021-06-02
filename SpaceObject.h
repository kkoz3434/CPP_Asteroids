//
// Created by kkoz34 on 02.06.2021.
//

#ifndef PROJEKT_ASTEROID_SPACEOBJECT_H
#define PROJEKT_ASTEROID_SPACEOBJECT_H


#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <valarray>
#include "GameSetup.h"
class SpaceObject {
public:
    float x;
    float y;
    float dx;
    float dy;
    float radius;
    bool is_alive;

    SpaceObject();

    void set_all(float new_x, float new_y, float new_radius);

    virtual void update();




};


#endif //PROJEKT_ASTEROID_SPACEOBJECT_H
