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
    std::srand(10980);

    RenderWindow gameWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
    gameWindow.setVerticalSyncEnabled("controlled by application");
    gameWindow.setFramerateLimit(5);
    game_init();

    for (int i = 0; i < ASTEROIDS_N; i++) {
        spawnAsteroid();

    }

    while (gameWindow.isOpen()) {
        gameWindow.clear();
        Event event;

        // pollEvent return true if event occured
        while (gameWindow.pollEvent(event)) {
            if (event.type == Event::Closed)
                gameWindow.close();

            if (event.type == Event::KeyReleased)
                if (event.key.code == Keyboard::Space) {
                    newBullet();
                }
        }
        //events

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player.object.shape.rotate(-ROTATION_SPEED);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player.object.shape.rotate(ROTATION_SPEED);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            player.object.dx = cos((player.object.shape.getRotation() - 90) * DEG_RAD) * PLAYER_SPEED;
            player.object.dy = sin((player.object.shape.getRotation() - 90) * DEG_RAD) * PLAYER_SPEED;
            player.object.x += player.object.dx;
            player.object.y += player.object.dy;
            player.object.wrap_position();
        }

        for (auto b = bullets.begin(); b != bullets.end();) {
            if (b->beyondMap()) {
                b= bullets.erase(b);
                std::cout << "Deleting bullet" << std::endl;
            } else {
                b->update();
                b->shape.setPosition(b->x, b->y);
                gameWindow.draw(b->shape);
                b++;
            }
        }

        for (auto a = asteroids.begin(); a != asteroids.end(); a++) {
            a->update();
            a->object.shape.setPosition(a->object.x, a->object.y);
            gameWindow.draw(a->object.shape);

        }
        bulletCollision();

        player.object.shape.setPosition(player.object.x, player.object.y);
        gameWindow.draw(player.object.shape);
        gameWindow.display();
    }
}

void GameEngine::game_init() {
    player = Player();
    player.player_init();
}

GameEngine::GameEngine() {
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
    float x = rand() % WIDTH;
    float y = rand() % HEIGHT;
    SpaceObject a = SpaceObject(x, y, ASTEROID_RADIUS);
    while (player.object.collides(a)) {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        a = SpaceObject(x, y, ASTEROID_RADIUS);
    }
    asteroids.push_back( Asteroid(a));
}

void GameEngine::bulletCollision() {
    //std::cout<<"bullet collision function<"<<std::endl;
    std::cout<<bullets.size() <<" "<< asteroids.size()<<std::endl;
    for(auto bullet = bullets.begin(); bullet != bullets.end();) {
        for(auto asteroid = asteroids.begin(); asteroid != asteroids.end();) {
            if (!bullet->collides(asteroid->object)) {
                std::cout<<"Chyba trafiony"<<std::endl;
                asteroid = asteroids.erase(asteroid);
                bullet = bullets.erase(bullet);
                std::cout << "Trafiony" << std::endl;
            }
            else{
                bullet++;
                asteroid++;
            }
        }
    }
}


void GameEngine::update(SpaceObject object) {

}
