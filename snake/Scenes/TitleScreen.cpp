//
//  TitleScreen.cpp
//  snake
//
//  Created by ccbb on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#include <stdio.h>

#include "constants.h"
#include "Scene.hpp"

class TitleScene : public Scene {
    
public:
    TitleScene(Video* video) {
        this->mScreen = video;
    };
    
    ~TitleScene() {}
    
    void update(SDL_Event* e, int* sceneTransition) {
        
        SDL_Keycode key = e->key.keysym.sym;
        
        if(key == SDLK_SPACE) {
            *sceneTransition = GAME_STATE;
        }
    }
    
    void render() {
        mScreen->clearRenderer();
        mScreen->drawText(60, 120-75, 500, 75, "SNAKE PRESS SPACE KEY TO START");
        mScreen->callRenderer();
    }
    
private:
    Video* mScreen;
};
