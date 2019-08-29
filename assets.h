#ifndef ASSETS_H
#define ASSETS_H
#include<iostream>
#include<SDL.h>
#include<time.h>
#include"defines.h"
class button{
    public:
        button();
        bool changeCaption(int p_caption);
        bool isPressed(){return pressed;}
        void init(int x_pos, int y_pos, int width, int height);
        int x;
        int y;
        int w;
        int h;
        int caption;
        int number;
        bool moving;
    private:
        bool pressed;


};
void generateRandom(button p_button[16]);
void setPosition(button p_button[16]);
int randomNumber(int max);
std::string integerToString(int number);
bool checkWon(button p_button[16]);
#endif // ASSETS_H
