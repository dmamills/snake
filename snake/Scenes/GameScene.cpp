//
//  GameScene.cpp
//  snake
//
//  Created by ccbb on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#include <stdio.h>
#include "Scene.hpp"
#include "Player.hpp"


class GameScene : public Scene {
    
public:
    GameScene(Video* video) {
        this->mScreen = video;
        resetGame();
    };
    
    ~GameScene() { }
    
    void update(SDL_Event* e, int* sceneTransition) {
        
        if(e->type == SDL_KEYDOWN) {
            
            SDL_Keycode key = e->key.keysym.sym;
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
        
        Position head;
        auto body = mPlayer.getBody();
        Position direction = mPlayer.getDirection();
        Position currentHead = body.front();
        head.x = currentHead.x += direction.x;
        head.y = currentHead.y += direction.y;
        
        for(auto it = body.begin(); it != body.end(); it++) {
            if(it->x == head.x && it->y == head.y) {
                *sceneTransition = TITLE_STATE;
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
    
    void render() {
        mScreen->clearRenderer();
        mScreen->clearScreen();
        auto body = mPlayer.getBody();
        for(auto it = body.begin(); it != body.end();it++) {
            mScreen->setPixel(it->x, it->y, true);
        }
        
        mScreen->setPixel(mTarget.x, mTarget.y, true);
        mScreen->drawScreen();
        
        mScreen->drawText(5, 5, 75, 20, "Score: " + std::to_string(mScore));
        mScreen->callRenderer();
    }
    
    void setNewTarget() {
        mTarget.x = rand() % PIXELS_WIDTH;
        mTarget.y = rand() % PIXELS_HEIGHT;
    }

    void resetGame () {
        mScore = 0;
        mPlayer = Player(10, 10);
        setNewTarget();
    }
    
private:
    Video* mScreen;
    Player mPlayer;
    Position mTarget;
    int mScore = 0;
    
};
