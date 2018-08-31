//
//  Player.cpp
//  snake
//
//  Created by Daniel Mills on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#include "Player.hpp"
#include "constants.h"

Player::Player(int x, int y) {
    
    for(auto i = 0; i < STARTING_SIZE; i++) {
        Position start;
        start.x = x + i;
        start.y = y;
        body.push_front(start);
    }
    
    this->dx = 1;
    this->dy = 0;
}

Player::~Player() {}

Position Player::getDirection() {
    Position p;
    p.x = dx;
    p.y = dy;
    
    return p;
}

void Player::setDirection(int dx, int dy) {
    this->dx = dx;
    this->dy = dy;
}

std::deque<Position> Player::getBody() {
    return body;
}

void Player::add(Position p) {
    body.push_front(p);
}

void Player::remove() {
    body.pop_back();
}
