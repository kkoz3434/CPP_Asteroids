//
// Created by kkoz34 on 02.06.2021.
//

#ifndef PROJEKT_ASTEROID_PLAYER_H
#define PROJEKT_ASTEROID_PLAYER_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <valarray>
#include "GameSetup.h"
#include "SpaceObject.h"

class Player: public SpaceObject {
public:
    int score;
    int health;

    Player();
    void player_init();
    void playerUpdate();
};
#endif //PROJEKT_ASTEROID_PLAYER_H
