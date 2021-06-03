//
// Created by kkoz34 on 03.06.2021.
//

#include "Menu.h"

void Menu::startMenu() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);
    window.setVerticalSyncEnabled("controlled by application");
    window.setFramerateLimit(1000);


    if (!font.loadFromFile("../Resources/AmaticSC-Regular.ttf")) {
        printf("Error while loading font!\n");
        exit(1);
    }
    menuText.setString("Asteroids");
    menuText.setFont(font);
    menuText.setCharacterSize(56);
    menuText.setPosition(WIDTH / 2 - 56, HEIGHT / 2 - 56);

    clickToPlay.setString("Press Space to play...");
    clickToPlay.setFont(font);
    clickToPlay.setCharacterSize(24);
    clickToPlay.setPosition(WIDTH / 2.1, HEIGHT / 2);

    spawnBackground();

    while (window.isOpen()) {

        window.clear();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Space) {
                    GameEngine gameEngine;
                    inMainMenu = false;
                    endMenu = true;
                    int score = gameEngine.game(window);

                    Text scoreText;
                    scoreText.setPosition(WIDTH / 2, HEIGHT / 2);
                    scoreText.setString("Score: "+ std::to_string(score));
                    scoreText.setFont(font);
                    while (endMenu) {
                        window.clear();
                        window.draw(scoreText);
                        Event event;
                        while (window.pollEvent(event)) {
                            if (event.type == Event::Closed) {
                                window.close();
                            }
                            if(event.type == Event::KeyReleased){
                                if (event.key.code == Keyboard::Space)
                                    inMainMenu = true;
                                    endMenu = false;
                            }
                        }
                        window.display();
                    }
                }
            }
        }
        background(window);
        window.draw(menuText);
        window.draw(clickToPlay);
        window.display();

    }
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
