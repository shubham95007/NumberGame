#include<iostream>
#include"game.h"
#include"defines.h"
game* Game = 0;
int main(int argv, char* argc[])
{

    Game = new game;
    Game->init("2D Puzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 310, 310, SDL_WINDOW_SHOWN);
    while(Game->running())
    {
        int x = SDL_GetTicks();
        Game->render();
        Game->handleEvents();
        Game->update();
        int y = SDL_GetTicks();
        SDL_Delay((1000+x-y)/60);

    }
    Game->clean();
    return 0;
}
