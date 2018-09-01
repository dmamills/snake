//
//  GameScene.hpp
//  snake
//
//  Created by ccbb on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include "Video.hpp"
#include <stdio.h>

class Scene {
    
public:
    virtual void render( ) {}
    virtual void update(SDL_Event*, int*){}
};

#endif /* GameScene_hpp */
