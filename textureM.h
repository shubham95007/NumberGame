#ifndef TEXTUREM_H
#define TEXTUREM_H
#include<iostream>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<map>
#include"defines.h"
class textureManager
{
public:
    textureManager();
    ~textureManager();
    bool load(std::string fileName, std::string id, SDL_Renderer* p_renderer);
    bool loadFont(std::string fileName, std::string fontId, int fontSize);
    void draw(std::string id, int x, int y, int w, int h, SDL_Renderer* p_renderer);
    void drawFrame(std::string id, int x, int y, int w, int h, int frameW, int frameH, int frame, double angle, SDL_Renderer* p_renderer);

    void drawText(std::string fontId, std::string text, int x, int y, int width, int height , SDL_Color p_color, SDL_Renderer* p_renderer);
    void drawText(std::string fontId, std::string text, int x, int y, SDL_Renderer* p_renderer);


private:
    std::map<std::string, SDL_Texture*> textureMap;
    std::map<std::string, TTF_Font*>font;
};
#endif // TEXTUREM_H
