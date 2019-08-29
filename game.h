#ifndef GAME_H
#define GAME_H
#include"textureM.h"
#include"fontManager.h"
#include"soundM.h"
#include<iostream>
#include"defines.h"
#include"assets.h"
class game{
public:
    bool init(const char* title, int x, int y, int w, int h, int flag);
    void render();
    void handleEvents();
    void update();
    bool running(){return m_running;}
    void clean();
private:
    bool m_running = true;
    SDL_Window* win = nullptr;
    SDL_Renderer* renderer = nullptr;
    textureManager m_textureManager;
    soundManager m_soundManager;
    bool won = false;
    button m_button[16];

};


#endif // GAME_H
