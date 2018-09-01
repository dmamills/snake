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
#include "Scene.hpp"
#include <vector>
#include <stdio.h>

class Game {
public:
    Game();
    ~Game();
    void start();
    
private:
    Video mScreen;
    bool mRunning;
    Uint32 mNextTime;
    std::vector<Scene*> mScenes;
    int mCurrentScene = 0;
    
    void update();
    void render();
    Uint32 getTime();

};

#endif /* Game_hpp */
