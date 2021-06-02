//
// Created by kkoz34 on 02.06.2021.
//

#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <valarray>
#include "GameSetup.h"
#include "GameEngine.h"

void GameEngine::game_loop() {

}

void GameEngine::game_init() {

}

GameEngine::GameEngine() {
    RenderWindow gameWindow(sf::VideoMode(WIDTH, HEIGTH), TITLE);
}
