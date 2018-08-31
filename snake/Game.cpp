//
//  Game.cpp
//  snake
//
//  Created by Daniel Mills on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#include "Game.hpp"

Game::Game() : mPlayer(15, 15) {
    mScreen.init();
    mScreen.clearScreen();
    mScore = 0;
}

Game::~Game() {}

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
    mInGame = false;
    mNextTime = SDL_GetTicks() + SCREEN_TICKS_PER_FRAME;
    
    resetGame();
    
    while(mRunning) {
        SDL_Event e;
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                mRunning = false;
            } else if(e.type == SDL_KEYDOWN) {
                SDL_Keycode key = e.key.keysym.sym;
                
                if(!mInGame && key == SDLK_SPACE) {
                    mInGame = true;
                    resetGame();
                } else {
                
                    Position playerPosition = mPlayer.getDirection();
                    if(key == SDLK_UP && playerPosition.y != 1) {
                        mPlayer.setDirection(0, -1);
                    }
                    
                    if(key == SDLK_DOWN && playerPosition.y != -1) {
                        mPlayer.setDirection(0, 1);
                    }
                    
                    if(key == SDLK_LEFT && playerPosition.x != 1) {
                        mPlayer.setDirection(-1, 0);
                    }
                    
                    if(key == SDLK_RIGHT && playerPosition.x != -1) {
                        mPlayer.setDirection(1, 0);
                    }
                }
            }
        }
        
        this->update();
        this->render();
        
        SDL_Delay(getTime());
        mNextTime += SCREEN_TICKS_PER_FRAME;
    }
}

void Game::setNewTarget() {
    mTarget.x = rand() % PIXELS_WIDTH;
    mTarget.y = rand() % PIXELS_HEIGHT;
}

void Game::update() {
    
    if(mInGame) {
        this->updateGame();
    }
}

void Game::updateGame() {
    Position head;
    auto body = mPlayer.getBody();
    Position direction = mPlayer.getDirection();
    Position currentHead = body.front();
    head.x = currentHead.x += direction.x;
    head.y = currentHead.y += direction.y;
    
    for(auto it = body.begin(); it != body.end(); it++) {
        if(it->x == head.x && it->y == head.y) {
            mInGame = false;
            SDL_Delay(500);
        }
    }
    
    if(head.x == mTarget.x && head.y == mTarget.y) {
        setNewTarget();
        mScore++;
    } else {
        mPlayer.remove();
    }
    
    if(head.x > PIXELS_WIDTH - 1) {
        head.x = 0;
    } else if(head.x < 0) {
        head.x = PIXELS_WIDTH - 1;
    }
    
    if(head.y > PIXELS_HEIGHT - 1) {
        head.y = 0;
    } else if(head.y < 0) {
        head.y = PIXELS_HEIGHT - 1;
    }
    
    mPlayer.add(head);
}

void Game::render() {
    if(mInGame) {
        this->renderGame();
    } else {
        mScreen.clearRenderer();
        mScreen.drawText(60, 120-75, 500, 75, "SNAKE PRESS SPACE KEY TO START");
        mScreen.callRenderer();
    }
}

void Game::renderGame() {
    mScreen.clearRenderer();
    mScreen.clearScreen();
    auto body = mPlayer.getBody();
    for(auto it = body.begin(); it != body.end();it++) {
        mScreen.setPixel(it->x, it->y, true);
    }
    
    mScreen.setPixel(mTarget.x, mTarget.y, true);
    mScreen.drawScreen();
    
    mScreen.drawText(5, 5, 75, 20, "Score: " + std::to_string(mScore));
    mScreen.callRenderer();
}

void Game::resetGame() {
    mScore = 0;
    mPlayer = Player(10, 10);
    setNewTarget();
}
