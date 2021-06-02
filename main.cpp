#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <valarray>
#include "GameSetup.h"
#include "SpaceObject.h"

using namespace sf;

const float degreeRadian = M_PI / 180;


int main() {
    std::cout << sin(360 * degreeRadian) << std::endl;
    RenderWindow gameWindow(sf::VideoMode(WIDTH, HEIGTH), "Asteroids_kkoz3434");
    gameWindow.setVerticalSyncEnabled("controlled by application");
    gameWindow.setFramerateLimit(60);
    SpaceObject spaceObject;

    float x, y;
    float dx, dy;
    dx = 0;
    dy = 0;
    x = 350;
    y = 240;
    float angle =0;
    CircleShape triangle(20.0f, 3);
    triangle.setOrigin(20,20);
    triangle.scale(1, 1.3);
    triangle.setFillColor(sf::Color(255, 255, 255)); // green
    triangle.setPosition(sf::Vector2f(x, y));
    std::cout << triangle.getRotation() << std::endl;

    while (gameWindow.isOpen()) {
        gameWindow.clear();
        sf::Event event;
        // pollEvent return true if event occured
        while (gameWindow.pollEvent(event)) {
            if (event.type == Event::Closed)
                gameWindow.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            triangle.rotate(-5.0f);

            std::cout << triangle.getRotation() << " my angle: " << angle << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            triangle.rotate(5.0f);

            std::cout << triangle.getRotation() << " my angle: " << angle << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            dx = cos((triangle.getRotation() - 90)* degreeRadian)*5;
            dy = sin((triangle.getRotation() -90 )* degreeRadian)*5;
            std::cout<< "dx = " << dx << "|| y = "<<dy<<std::endl;
            x += dx;
            y += dy;
        }


        triangle.setPosition(sf::Vector2f(x, y));
        gameWindow.draw(triangle);
        gameWindow.display();
    }
    return 0;
}
