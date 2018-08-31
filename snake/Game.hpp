//
//  Game.hpp
//  snake
//
//  Created by Daniel Mills on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Video.hpp"
#include "Player.hpp"
#include <stdio.h>

class Game {
public:
    Game();
    ~Game();
    void start();
    
private:
    Video mScreen;
    Player mPlayer;
    bool mRunning;
    bool mInGame;
    Uint32 mNextTime;
    int mScore;
    Position mTarget;
    
    void update();
    void render();
    
    void updateGame();
    void renderGame();
    void resetGame();
    
    Uint32 getTime();
    void setNewTarget();
};

#endif /* Game_hpp */
