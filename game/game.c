#include <stdio.h>
#include <stdlib.h>
#include "./game.h"

#define SDL_EXIT_EXIT_GAME 0
#define SDL_EXIT_DEFAULT 1

int width = 600;
int height = 420;

SDL_Window *window;
SDL_Renderer *renderer;

void initGame(void){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "initGame::SDL_Init: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALLOW_HIGHDPI);
    if(window == NULL){
        fprintf(stderr, "initGame::SDL_CreateWindow: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == NULL){
        fprintf(stderr, "initGame::SDL_CreateRenderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void destroyGame(void){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


void render(void){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

uint input(void){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                return SDL_EXIT_EXIT_GAME;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    return SDL_EXIT_EXIT_GAME;
                break;
        }
    }
    return SDL_EXIT_DEFAULT;
}