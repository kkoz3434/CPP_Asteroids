//
// Created by kkoz34 on 02.06.2021.
//

#include "Asteroid.h"

Asteroid::Asteroid(SpaceObject randObj, int lvl) {
    object.x = randObj.x;
    object.y= randObj.y;
    object.radius = randObj.radius/2;

    object.dx = -ASTEROID_SPEED_MAX + std::rand()%(2*ASTEROID_SPEED_MAX);
    object.dy = -ASTEROID_SPEED_MAX + std::rand()%(2*ASTEROID_SPEED_MAX);
    level = lvl;

    object.shape = CircleShape(object.radius);
    object.shape.setOutlineThickness( 3);
    object.shape.setOutlineColor(Color(255,255,255));

    object.shape.setFillColor(Color(0,0,0));



}

void Asteroid::update(){
    object.wrap_position();
    object.update();
}
