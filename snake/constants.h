//
//  constants.h
//  snake
//
//  Created by Daniel Mills on 2018-08-31.
//  Copyright © 2018 Daniel Mills. All rights reserved.
//

#ifndef constants_h
#define constants_h

#include <string>
#include <SDL2/SDL.h>

const int PIXELS_WIDTH = 64;
const int PIXELS_HEIGHT = 32;
const int PIXEL_SIZE = 10;

const int SCREEN_WIDTH = PIXELS_WIDTH * PIXEL_SIZE;
const int SCREEN_HEIGHT = PIXELS_HEIGHT * PIXEL_SIZE;

const int SCREEN_FPS = 20;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const int STARTING_SIZE = 3;

const SDL_Color BLACK = { 0, 0, 0 };

static const std::string FONT_FILENAME = "/Library/Fonts/Arial.ttf";

const int TITLE_STATE = 0;
const int GAME_STATE = 1;

#endif /* constants_h */
