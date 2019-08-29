#include"textureM.h"
textureManager::textureManager()
{
    IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
    TTF_Init();
}
textureManager::~textureManager()
{
    IMG_Quit();
}
bool textureManager::load(std::string fileName, std::string id, SDL_Renderer* p_renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    if(!tempSurface)
    {
        std::cout<<"Image load error "<<SDL_GetError()<<std::endl;
        return false;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(p_renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if(!tex)
    {
        std::cout<<"Texture creation failed "<<SDL_GetError()<<std::endl;
        return false;
    }
    textureMap[id]=tex;
    return true;
}
void textureManager::draw(std::string id, int x, int y, int w, int h, SDL_Renderer* p_renderer)
{
    SDL_Rect src, dest;
    src.x = src.y = 0;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(textureMap[id], 0, 0, &src.w, &src.h);
    if(h > 0)
        dest.h = h;
    else
        dest.h = src.h;
    if(w > 0)
        dest.w = w;
    else
        dest.w = src.w;

    SDL_RenderCopy(p_renderer, textureMap[id], &src, &dest);
}
void textureManager::drawFrame(std::string id, int x, int y, int w, int h, int frameW, int frameH, int frame, double angle, SDL_Renderer* p_renderer)
{
    SDL_Rect src, dest;
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
    src.h = frameH;
    src.w = frameW;
    src.x = frameW*frame;
    src.y = 0;
    SDL_RenderCopyEx(p_renderer, textureMap[id], &src, &dest, angle, 0, SDL_FLIP_NONE);
}
bool textureManager::loadFont(std::string fileName, std::string fontId, int fontSize)
{
    TTF_Font* g_font = nullptr;
    g_font = TTF_OpenFont(fileName.c_str(), fontSize);
    if(!g_font){
        std::cout<<"Error loading font "<<TTF_GetError()<<std::endl;
        return false;
    }
    font[fontId] = g_font;
    return true;

}
void textureManager::drawText(std::string fontId, std::string text, int x, int y, int width, int height, SDL_Color p_color, SDL_Renderer* p_renderer)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = width;
    dest.h = height;
    SDL_Surface* tempSurface = nullptr;
    tempSurface = TTF_RenderText_Solid(font[fontId], text.c_str(), p_color);
    if(!tempSurface)
    {
        std::cout<<"error creating surface from text "<<TTF_GetError()<<"\n";
        SDL_FreeSurface(tempSurface);
        return;
    }
    SDL_Texture* p_texture = nullptr;
    p_texture = SDL_CreateTextureFromSurface(p_renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_RenderCopy(p_renderer, p_texture, NULL, &dest);
    SDL_DestroyTexture(p_texture);

}
void textureManager::drawText(std::string fontId, std::string text, int x, int y, SDL_Renderer* p_renderer)
{
    SDL_Surface* tempSurface = nullptr;
    SDL_Color p_color = {0,0,0,0};
    tempSurface = TTF_RenderText_Solid(font[fontId], text.c_str(), p_color);
    if(!tempSurface)
    {
        std::cout<<"error creating surface from text "<<TTF_GetError()<<"\n";
        SDL_FreeSurface(tempSurface);
        return;
    }
    SDL_Texture* p_texture = nullptr;
    p_texture = SDL_CreateTextureFromSurface(p_renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(p_texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(p_renderer, p_texture, NULL, &dest);
    SDL_DestroyTexture(p_texture);
}
