//
//  Video.cpp
//  sdl-test
//
//  Created by Daniel Mills on 2018-08-24.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#include "Video.hpp"

Video::Video() {
    for(auto i =0; i < PIXELS_WIDTH * PIXELS_HEIGHT;i++) {
        mPixels[i] = false;
    }
}

Video::~Video() {
    mRenderer = NULL;
    TTF_Quit();
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

bool Video::init() {
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        std::cout <<"Error SDL_INIT" << SDL_LASTERROR << "\n";
        return false;
    }
    
    mWindow = SDL_CreateWindow(this->mWindowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if(mWindow == NULL) {
        std::cout <<"Error SDL_CreateWindow" << SDL_LASTERROR << "\n";
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    
    if(mRenderer == NULL) {
        std::cout <<"Error SDL_CreateRenderer" << SDL_LASTERROR << "\n";
        return false;
    }
    
    if(TTF_Init() == -1) {
        std::cout <<"Error TTF_Init " << TTF_GetError() << "\n";
        return false;
    }
    
    mFont = TTF_OpenFont(FONT_FILENAME.c_str(), 14);
    if(mFont == NULL) {
        std::cout << "Error TTF_OpenFont " << TTF_GetError() << "\n";
        return false;
    }
    
    return true;
}

void Video::clearScreen() {
    
    for(auto i =0; i < PIXELS_WIDTH * PIXELS_HEIGHT;i++) {
        mPixels[i] = false;
    }
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_RenderClear(mRenderer);
}

void Video::renderPixel(int x, int y) {
    SDL_Rect r;
    r.x = x * PIXEL_SIZE;
    r.y = y * PIXEL_SIZE;
    r.w = PIXEL_SIZE;
    r.h = PIXEL_SIZE;
    
    if(mPixels[y * PIXELS_WIDTH + x]) {
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0xFF);
    } else {
        SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    
    SDL_RenderFillRect(mRenderer, &r);
}

void Video::drawScreen() {
    
    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    
    for(auto i = 0; i < PIXELS_WIDTH; i++) {
        for(auto j = 0; j < PIXELS_HEIGHT; j++) {
            renderPixel(i, j);
        }
    }
}

void Video::setPixel(int x, int y, bool val) {
    int n = y * PIXELS_WIDTH + x;
    setPixel(n, val);
}

void Video::setPixel(int n, bool val) {
    mPixels[n] = val;
}

void Video::drawText(int x, int y, int w, int h, std::string str) {
    
    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(mFont, str.c_str(), BLACK);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(mRenderer, surfaceMessage);
    
    SDL_Rect message_rect;
    message_rect.x = x;
    message_rect.y = y;
    message_rect.w = w;
    message_rect.h = h;
    
    SDL_RenderCopy(mRenderer, Message, NULL, &message_rect);
}

void Video::callRenderer() {
    SDL_RenderPresent(mRenderer);
}

void Video::clearRenderer() {
    SDL_RenderClear(mRenderer);
}
