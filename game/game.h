#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SDL_EXIT_EXIT_GAME 0
#define SDL_EXIT_DEFAULT 1
#define FRAME 
#define FRAME_TARGET_TIME 10000/FRAME

typedef unsigned int uint;

void initGame(void);
void destroyGame(void);
void render(void);
uint input(void);
#endif