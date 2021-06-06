//
// Created by kkoz34 on 03.06.2021.
//

#include "Menu.h"

void Menu::startMenu() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);
    window.setVerticalSyncEnabled("controlled by application");
    window.setFramerateLimit(60);

    textInit();
    spawnBackground();

    while (window.isOpen()) {

        window.clear();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(0);
            }



            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Space) {
                    startGame(window, score);
                    textEnd();
                    endScreen(window);
                }
                if(event.key.code == Keyboard::Escape)
                    window.close();
            }
        }
        background(window);
        window.draw(pressEscapeText);
        window.draw(menuText);
        window.draw(clickToPlayText);
        window.draw(authorText);
        window.display();

    }
    exit(0);
}

void Menu::textEnd() {
    endText = clickToPlayText;
    endText.setString("Press LControl...");
    endText.setPosition(WIDTH /2.1, HEIGHT / 2);
    scoreText.setPosition(WIDTH / 2-56, HEIGHT / 2-56);
    scoreText.setCharacterSize(56);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setFont(font);
}

void Menu::endScreen(RenderWindow &window) {
    while (endMenu) {
        window.clear();
        background(window);
        window.draw(scoreText);
        window.draw(endText);
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(0);
            }
            if(event.type == Event::KeyReleased){
                if (event.key.code == Keyboard::LControl) {
                    inMainMenu = true;
                    endMenu = false;
                }
            }
        }
        window.display();
    }
}

void Menu::startGame(RenderWindow &window, int &score) {
    GameEngine gameEngine;
    score= gameEngine.game(window);
    inMainMenu = false;
    endMenu = true;
}

void Menu::textInit() {
    if (!font.loadFromFile("../Resources/AmaticSC-Regular.ttf")) {
        printf("Error while loading font!\n");
        exit(1);
    }

    authorText.setString("J a k u b  K o z l a k");
    authorText.setFont(font);
    authorText.setCharacterSize(16);
    authorText.setPosition(WIDTH / 2 - 56, HEIGHT / 2 - 56-10);
    pressEscapeText.setString("Press  Escape  to  quit");
    pressEscapeText.setFont(font);
    pressEscapeText.setCharacterSize(24);
    pressEscapeText.setPosition(20,20);

    menuText.setString("Asteroids");
    menuText.setFont(font);
    menuText.setCharacterSize(56);
    menuText.setPosition(WIDTH / 2 - 56, HEIGHT / 2 - 56);

    clickToPlayText.setString("Press Space...");
    clickToPlayText.setFont(font);
    clickToPlayText.setCharacterSize(24);
    clickToPlayText.setPosition(WIDTH / 2.1, HEIGHT / 2);
}

void Menu::spawnBackground() {
    for (int i = 0; i < MENU_ASTEROIDS; ++i) {
        float x = rand() % WIDTH;
        float y = rand() % HEIGHT;
        float radius = 20 + rand() % ASTEROID_RADIUS;
        SpaceObject a = SpaceObject(x, y, radius);
        asteroids.push_back(Asteroid(a));
    }
}

void Menu::background(RenderWindow &window) {
    for (auto &asteroid : asteroids) {
        asteroid.update();
        asteroid.wrap_position();
        window.draw(asteroid.shape);
    }
}
