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
    Text clickToPlayText;
    Text scoreText;
    Text endText;
    Text pressEscapeText;
    Text authorText;
    Font font;

    int score = 0;
    void startMenu();
    void background(RenderWindow &window);

    void spawnBackground();

    void textInit();

    void startGame(RenderWindow &window, int &score);

    void endScreen(RenderWindow &window);

    void textEnd();
};


#endif //PROJEKT_ASTEROID_MENU_H
