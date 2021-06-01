//
// Created by kkoz34 on 01.06.2021.
//

#ifndef PROJEKT_ASTEROID_ASTEROID_H
#define PROJEKT_ASTEROID_ASTEROID_H


class Asteroid {
protected:
    float x;
    float y;
    float dx;
    float dy;
    int size; // from 3 ro 1, 1 is the smallest

public:
    Asteroid(float x, float y, float dx, float dy, int size)
    : x{x}, y{y}, dx{dx}, dy{dy}, size{size}{}


};


#endif //PROJEKT_ASTEROID_ASTEROID_H
