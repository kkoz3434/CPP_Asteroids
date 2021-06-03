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

using namespace sf;
class SpaceObject {
public:
    CircleShape shape;
    float x;
    float y;
    float dx;
    float dy;
    float radius;
    bool is_alive;


    SpaceObject();
    SpaceObject(float x, float y, float radius);
    void set_all(float new_x, float new_y, float new_radius);
    void update();
    void wrap_position();

    bool collides(SpaceObject object);
    bool beyondMap();







};


#endif //PROJEKT_ASTEROID_SPACEOBJECT_H
