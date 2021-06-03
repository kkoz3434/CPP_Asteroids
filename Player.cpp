//
// Created by kkoz34 on 02.06.2021.
//

#include "Player.h"

Player::Player() {
    x = PLAYER_X;
    y=PLAYER_Y;
    radius = PLAYER_RADIUS;
    score = 0;
    health = PLAYER_HP;
}

void Player::player_init(){
    shape = sf::CircleShape(PLAYER_RADIUS, 3);
    shape.setFillColor(sf::Color(0,0,0));
    shape.setOutlineThickness(3);
    shape.setOutlineColor(Color(0,255,0 ));
    shape.setPosition(WIDTH/2, HEIGHT/2);
    shape.setOrigin(PLAYER_RADIUS, PLAYER_RADIUS);
    shape.setScale(1,1.2);
}

void Player::playerUpdate() {
    int red = 255 * (1 - (static_cast<float>(health) / PLAYER_HP));
    int green = 255 * (static_cast<float>(health) / PLAYER_HP);
    shape.setOutlineColor(Color(red, green, 0));
    SpaceObject::update();
}



