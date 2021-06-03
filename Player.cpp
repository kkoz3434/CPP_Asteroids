//
// Created by kkoz34 on 02.06.2021.
//

#include "Player.h"

Player::Player() {
    object = SpaceObject(PLAYER_X, PLAYER_Y, PLAYER_RADIUS);
    score = 0;
    health = PLAYER_HP;
}

void Player::player_init(){
    object.shape = sf::CircleShape(PLAYER_RADIUS, 3);
    object.shape.setFillColor(sf::Color(0,0,0));
    object.shape.setOutlineThickness(3);
    object.shape.setOutlineColor(Color(0,255,0 ));
    object.shape.setPosition(sf::Vector2f(object.x, object.y));
    object.shape.setOrigin(PLAYER_RADIUS, PLAYER_RADIUS);
    object.shape.setScale(1,1.2);
}



