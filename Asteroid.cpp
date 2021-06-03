//
// Created by kkoz34 on 02.06.2021.
//

#include "Asteroid.h"

Asteroid::Asteroid(SpaceObject randObj, int lvl, Color color) {
    x = randObj.x;
    y= randObj.y;
    level = lvl;
    if(level==ASTEROID_LVL)
        radius = randObj.radius;
    else
        radius = randObj.radius/2;

    dx = -ASTEROID_SPEED_MAX + std::rand()%(2*ASTEROID_SPEED_MAX);
    dy = -ASTEROID_SPEED_MAX + std::rand()%(2*ASTEROID_SPEED_MAX);

    points = ASTEROID_POINTS;

    shape = CircleShape(radius);
    shape.setOutlineThickness( 3);
    shape.setOutlineColor(color);
    shape.setOrigin(radius, radius);
    shape.setFillColor(Color(0,0,0));
}

