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

void GameEngine::game() {
    std::srand(time(NULL));


    RenderWindow gameWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
    gameWindow.setVerticalSyncEnabled("controlled by application");
    gameWindow.setFramerateLimit(1000);
    game_init();


    while (gameWindow.isOpen() && player.object.is_alive) {
        gameWindow.clear();
        Event event;

        // pollEvent return true if event occured
        while (gameWindow.pollEvent(event)) {
            eventHandler(gameWindow, event);
        }
        //events

        spawnAsteroid();
        movePlayer(gameWindow);
        moveBullets(gameWindow);
        moveAsteroids(gameWindow);
        bulletCollision();
        playerCollision();

        scoreText.setString(std::to_string(player.score) + "\n" + (std::to_string(player.health)) +
                            "/" + std::to_string(PLAYER_HP));
        scoreText.setScale(2, 2);
        gameWindow.draw(scoreText);
        gameWindow.display();
    }

    scoreText.setPosition(WIDTH / 2, HEIGHT / 2);
    scoreText.setString(std::to_string(player.score));
    while (gameWindow.isOpen()) {
        gameWindow.clear();
        gameWindow.draw(scoreText);
        Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                gameWindow.close();
            }
        }
        gameWindow.display();
    }
}

void GameEngine::eventHandler(RenderWindow &gameWindow, const Event &event) {
    if (event.type == Event::Closed)
        gameWindow.close();

    if (event.type == Event::KeyReleased)
        if (event.key.code == Keyboard::Space) {
            newBullet();
        }
}

void GameEngine::moveAsteroids(RenderWindow &gameWindow) {
    for (auto &asteroid : asteroids) {
        asteroid.update();
        asteroid.object.shape.setPosition(asteroid.object.x, asteroid.object.y);
        gameWindow.draw(asteroid.object.shape);

    }
}

void GameEngine::moveBullets(RenderWindow &gameWindow) {
    for (auto b = bullets.begin(); b != bullets.end();) {
        if (b->beyondMap()) {
            b = bullets.erase(b);
            std::cout << "Deleting bullet" << std::endl;
        } else {
            b->update();
            b->shape.setPosition(b->x, b->y);
            gameWindow.draw(b->shape);
            b++;
        }
    }
}

void GameEngine::movePlayer(RenderWindow &gameWindow) {

    if (Keyboard::isKeyPressed(Keyboard::Left)) player.object.shape.rotate(-ROTATION_SPEED);

    if (Keyboard::isKeyPressed(Keyboard::Right)) player.object.shape.rotate(ROTATION_SPEED);

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        player.object.dx = cos((player.object.shape.getRotation() - 90) * DEG_RAD) * PLAYER_SPEED;
        player.object.dy = sin((player.object.shape.getRotation() - 90) * DEG_RAD) * PLAYER_SPEED;

    } else {
        player.object.dx = 0.99*player.object.dx;
        player.object.dy = 0.99*player.object.dy;
    }

    player.object.x += player.object.dx;
    player.object.y += player.object.dy;
    player.object.wrap_position();
    player.object.shape.setPosition(player.object.x, player.object.y);
    gameWindow.draw(player.object.shape);

}

GameEngine::GameEngine() {}

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
    result.x = player.object.x;
    result.y = player.object.y;
    result.dx = cos((player.object.shape.getRotation() - 90) * DEG_RAD) * BULLET_SPEED;
    result.dy = sin((player.object.shape.getRotation() - 90) * DEG_RAD) * BULLET_SPEED;
    bullets.push_back(result);
}

void GameEngine::spawnAsteroid() {
    if (asteroids.size() < ASTEROIDS_N || player.score > gameLevel*20000) {
        for (int i = 0; i < ASTEROIDS_N + gameLevel; ++i) {
            float x = rand() % WIDTH;
            float y = rand() % HEIGHT;
            SpaceObject a = SpaceObject(x, y, ASTEROID_RADIUS);
            while (player.object.collides(a)) {
                x = rand() % WIDTH;
                y = rand() % HEIGHT;
                a = SpaceObject(x, y, ASTEROID_RADIUS);
            }
            asteroids.push_back(Asteroid(a, 3));
        }
        gameLevel += 1;
    }
}

int GameEngine::bulletCollision() {
    //std::cout<<"bullet collision function<"<<std::endl;
    //std::cout<<bullets.size() <<" "<< asteroids.size()<<std::endl;
    int counter = 0;
    for (auto bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
        for (auto asteroid = asteroids.begin(); asteroid != asteroids.end() && bullet != bullets.end(); ++asteroid) {
            if (bullet->collides(asteroid->object)) {
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
            Asteroid tmp = Asteroid(asteroid.object, asteroid.level - 1);
            tmp.level = asteroid.level - 1;
            tmp.points = asteroid.points * 2;
            asteroids.push_back(tmp);
        }
}

void GameEngine::playerCollision() {
    for (auto a = asteroids.begin(); a != asteroids.end(); a++) {
        if (player.object.collides(a->object)) {
            player.health -= 1;
            if (player.health == 0) {
                player.object.is_alive = false;
            }
            int red = 255 * (1 - (static_cast<float>(player.health) / PLAYER_HP));
            int green = 255 * (static_cast<float>(player.health) / PLAYER_HP);
            std::cout << "red: " << red << "green: " << green << std::endl;
            player.object.shape.setOutlineColor(Color(red, green, 0));
        }
    }

}

