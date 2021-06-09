//
// Created by kkoz34 on 02.06.2021.
//


#include "SpaceObject.h"


SpaceObject::SpaceObject(){}



SpaceObject::SpaceObject(float x, float y, float radius) : x(x), y(y), radius(radius) {
    shape = CircleShape(radius);
    shape.setOrigin(radius, radius);
}

void SpaceObject::update() {
    x += dx;
    y += dy;
    shape.setPosition(x,y);
}

void SpaceObject::wrapPosition() {
    if(x<0) x = WIDTH;
    if(x>WIDTH) x = 0;
    if(y<0) y=HEIGHT;
    if(y > HEIGHT) y = 0;
}

bool SpaceObject::collides(SpaceObject object) {
    float distance = ((x-object.x)*(x-object.x) + (y-object.y)*(y-object.y));
    float radiusesXD = (radius + object.radius)*(radius + object.radius);
    return distance<radiusesXD;

}

bool SpaceObject::beyondMap() {
    if(x>WIDTH || y>HEIGHT || x<0 || y<0)
        return true;
    return false;
}





