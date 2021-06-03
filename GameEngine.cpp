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
#include "Player.h"

int GameEngine::game(RenderWindow &window) {
    std::srand(time(NULL));
    game_init();
    window.display();
    while (window.isOpen() && player.health > 0) {
        window.clear();

        Event event;
        while (window.pollEvent(event)) {
            eventHandler(window, event);
        }

        if (asteroids.size() < ASTEROIDS_N || player.score > gameLevel*20000)
            spawnAsteroid();

        movePlayer(window);
        moveBullets(window);
        moveAsteroids(window);
        bulletCollision();
        playerCollision();
        scoreText.setString("LEVEL: "+ std::to_string(gameLevel)+ "\n"+std::to_string(player.score) + "\n" + (std::to_string(player.health)) +
                            "/" + std::to_string(PLAYER_HP));
        scoreText.setCharacterSize(36);
        window.draw(scoreText);
        window.display();
    }
    return player.score;
}

void GameEngine::eventHandler(RenderWindow &renderWindow, const Event &event) {
    if (event.type == Event::Closed)
        renderWindow.close();

    if (event.type == Event::KeyReleased)
        if (event.key.code == Keyboard::Space) {
            newBullet();
        }
}

void GameEngine::moveAsteroids(RenderWindow &renderWindow) {
    for (auto &asteroid : asteroids) {
        asteroid.update();
        asteroid.wrap_position();
        renderWindow.draw(asteroid.shape);

    }
}

void GameEngine::moveBullets(RenderWindow &renderWindow) {
    for (auto b = bullets.begin(); b != bullets.end();) {
        if (b->beyondMap()) {
            b = bullets.erase(b);
            std::cout << "Deleting bullet" << std::endl;
        } else {
            b->update();
            renderWindow.draw(b->shape);
            b++;
        }
    }
}

void GameEngine::movePlayer(RenderWindow &window) {

    if (Keyboard::isKeyPressed(Keyboard::Left)) player.shape.rotate(-ROTATION_SPEED);

    if (Keyboard::isKeyPressed(Keyboard::Right)) player.shape.rotate(ROTATION_SPEED);

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        player.dx = cos((player.shape.getRotation() - 90) * DEG_RAD) * PLAYER_SPEED;
        player.dy = sin((player.shape.getRotation() - 90) * DEG_RAD) * PLAYER_SPEED;

    } else {
        player.dx = 0.99f*player.dx;
        player.dy = 0.99f*player.dy;
    }

    player.playerUpdate();
    player.wrap_position();
    window.draw(player.shape);

}

void GameEngine::game_init() {
    player = Player();
    player.player_init();
    gameLevel = 0;

    if (!font.loadFromFile("../Resources/AmaticSC-Regular.ttf")) {
        printf("Error while loading font!\n");
        exit(1);
    }
    scoreText.setFont(font);
    String score;
    scoreText.setString(std::to_string(player.score) + "\n" + (std::to_string(player.health)) +
                        "/" + std::to_string(PLAYER_HP));


}

void GameEngine::newBullet() {
    SpaceObject result;
    result.radius = BULLET_SIZE;
    result.shape = CircleShape(BULLET_SIZE);
    result.shape.setOrigin(BULLET_SIZE, BULLET_SIZE);
    result.x = player.x;
    result.y = player.y;
    result.dx = cos((player.shape.getRotation() - 90) * DEG_RAD) * BULLET_SPEED;
    result.dy = sin((player.shape.getRotation() - 90) * DEG_RAD) * BULLET_SPEED;
    bullets.push_back(result);
}

void GameEngine::spawnAsteroid() {
        for (int i = 0; i < ASTEROIDS_N + gameLevel; ++i) {
            float x = rand() % WIDTH;
            float y = rand() % HEIGHT;
            SpaceObject a = SpaceObject(x, y, ASTEROID_RADIUS);
            while (player.collides(a)) {
                x = rand() % WIDTH;
                y = rand() % HEIGHT;
                a = SpaceObject(x, y, ASTEROID_RADIUS);
            }
            asteroids.push_back(Asteroid(a, ASTEROID_LVL));
        }
        gameLevel += 1;
}

int GameEngine::bulletCollision() {
    int counter = 0;
    for (auto bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
        for (auto asteroid = asteroids.begin(); asteroid != asteroids.end() && bullet != bullets.end(); ++asteroid) {
            if (bullet->collides(*asteroid)) {
                spawnSmallerAsteroid(*asteroid);
                player.score += asteroid->points;
                asteroid = asteroids.erase(asteroid);
                bullet = bullets.erase(bullet);
                --asteroid;
                --bullet;
                counter++;
            }
        }
    }
    return counter;
}

void GameEngine::spawnSmallerAsteroid(Asteroid asteroid) {
    if (asteroid.level > 1)
        for (int i = 0; i < NEW_ASTEROIDS; i++) {
            Asteroid tmp = Asteroid(asteroid, asteroid.level - 1, asteroid.shape.getOutlineColor());
            tmp.level = asteroid.level - 1;
            tmp.points = asteroid.points * 2;
            asteroids.push_back(tmp);
        }
}

void GameEngine::playerCollision() {
    for (auto a = asteroids.begin(); a != asteroids.end(); a++) {
        if (player.collides(*a)) {
            player.health -= 1;
            a->shape.setOutlineColor(player.shape.getOutlineColor());
        }
    }

}


