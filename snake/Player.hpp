//
//  Player.hpp
//  snake
//
//  Created by Daniel Mills on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <deque>

struct Position {
    int x;
    int y;
};

class Player {
public:
    Player(int, int);
    ~Player();
    
    void setDirection(int, int);
    Position getDirection();
    void add(Position);
    void remove();

    std::deque<Position> getBody();
private:
    int dx;
    int dy;
    std::deque<Position> body;
};

#endif /* Player_hpp */
