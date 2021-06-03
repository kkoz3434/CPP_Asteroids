//
// Created by kkoz34 on 02.06.2021.
//

#ifndef PROJEKT_ASTEROID_ASTEROID_H
#define PROJEKT_ASTEROID_ASTEROID_H


#include "SpaceObject.h"
#include <SFML/Graphics.hpp>
class Asteroid: public SpaceObject{
public:
    Asteroid(SpaceObject object, int level=ASTEROID_LVL, sf::Color color = Color(255,255,255));

    int level;
    int points;
};


#endif //PROJEKT_ASTEROID_ASTEROID_H
