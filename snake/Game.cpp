//
//  Game.cpp
//  snake
//
//  Created by Daniel Mills on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#include "Game.hpp"

#include "Scenes/GameScene.cpp"
#include "Scenes/TitleScreen.cpp"

Game::Game() {
    mScreen.init();
    mScreen.clearScreen();
    
    mScenes.push_back(new TitleScene(&mScreen));
    mScenes.push_back(new GameScene(&mScreen));
}

Game::~Game() {
    for(auto s : mScenes) {
        delete s;
    }
}

Uint32 Game::getTime() {
    Uint32 now;
    
    now = SDL_GetTicks();
    if(mNextTime <= now) {
        return 0;
    } else {
        return mNextTime - now;
    }
}

void Game::start() {
    
    mRunning = true;
    mNextTime = SDL_GetTicks() + SCREEN_TICKS_PER_FRAME;
    
    while(mRunning) {
        update();
    }
}

void Game::update() {
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( e.type == SDL_QUIT )
        {
            mRunning = false;
        }
    }
    
    int sceneTransition = -1;
    
    mScenes[mCurrentScene]->update(&e, &sceneTransition);
    
    if(sceneTransition > -1) {
        mCurrentScene = sceneTransition;
        SDL_Delay(200);
        
    } else {
        mScenes[mCurrentScene]->render();
        SDL_Delay(getTime());
        mNextTime += SCREEN_TICKS_PER_FRAME;
    }    
}

void Game::render() {
    mScenes[mCurrentScene]->render();
}
