//
// Created by kkoz34 on 03.06.2021.
//

#ifndef PROJEKT_ASTEROID_MENU_H
#define PROJEKT_ASTEROID_MENU_H


#include "GameEngine.h"

class Menu{
public:
    std::list<Asteroid> asteroids;
    bool inMainMenu = true;
    bool endMenu = false;
    Text menuText;
    Text clickToPlay;
    Font font;
    void startMenu();
    void background(RenderWindow &window);

    void spawnBackground();
};


#endif //PROJEKT_ASTEROID_MENU_H
