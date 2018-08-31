//
//  Video.hpp
//  sdl-test
//
//  Created by Daniel Mills on 2018-08-24.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#ifndef Video_hpp
#define Video_hpp

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include "constants.h"

class Video {
public:
    Video();
    ~Video();
    
    bool init();
    void setPixel(int, int, bool);
    void setPixel(int, bool);
    void drawScreen();
    void drawText(int, int, int, int, std::string);
    void clearScreen();
    void clearRenderer();
    void callRenderer();
    
private:
    const std::string mWindowName = "Snake";
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    TTF_Font* mFont;
    bool mPixels[PIXELS_WIDTH * PIXELS_HEIGHT];
    
    void renderPixel(int, int);
};

#endif /* Video_hpp */
