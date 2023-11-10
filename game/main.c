#include "./game.h"

#undef main

int main(){
    initGame();
    while(input()){
        render();
    }
    destroyGame();
}