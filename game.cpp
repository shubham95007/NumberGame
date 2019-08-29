#include"game.h"
bool game::init(const char* title, int x, int y, int w, int h, int flag)
{
    if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO|SDL_INIT_EVENTS)!=0)
    {
        std::cout<<"SDL Initialization failed "<<SDL_GetError()<<std::endl;
        SDL_Quit();
        return false;
    }
     else
    {
        std::cout<<"SDL Initialization successful\n";
    }
    win = SDL_CreateWindow(title, x, y, w, h, flag);
    if(!win)
    {
        std::cout<<"Window creation failed "<<SDL_GetError()<<std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return false;
    }
    else
    {
        std::cout<<"Window creation successful\n";
    }
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        std::cout<<"Renderer creation failed "<<SDL_GetError()<<std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return false;
    }
    else
    {
        std::cout<<"renderer creation successful";
    }
    m_textureManager.load("assets/button001.png","button01",renderer);
    m_textureManager.load("assets/button002.png","button02",renderer);
    m_textureManager.load("assets/button003.png","button03",renderer);
    m_textureManager.load("assets/button004.png","button04",renderer);
    m_textureManager.load("assets/button005.png","button05",renderer);
    m_textureManager.load("assets/button006.png","button06",renderer);
    m_textureManager.load("assets/button007.png","button07",renderer);
    m_textureManager.load("assets/button008.png","button08",renderer);
    m_textureManager.load("assets/button009.png","button09",renderer);
    m_textureManager.load("assets/button010.png","button10",renderer);
    m_textureManager.load("assets/button011.png","button11",renderer);
    m_textureManager.load("assets/button012.png","button12",renderer);
    m_textureManager.load("assets/button013.png","button13",renderer);
    m_textureManager.load("assets/button014.png","button14",renderer);
    m_textureManager.load("assets/button015.png","button15",renderer);
    m_textureManager.load("assets/pic2.jpg","background",renderer);
    m_textureManager.load("assets/reset.png","reset",renderer);
    m_soundManager.load("assets/click1.wav","click",SOUND_SFX);
    generateRandom(m_button);
    return true;
}
void game::render()
{

    SDL_RenderClear(renderer);
    m_textureManager.draw("background",0,0,310,310,renderer);
    for(int i = 0;i<16;i++)
    {
       // std::cout<<"i= "<<i<<", caption= "<<m_button[i].caption<<", num = "<<m_button[i].number<<", x = "<<m_button[i].x<<"\n";
        if(m_button[i].caption!=0)
        {
                m_textureManager.draw(std::string("button")+integerToString(i+1),60+m_button[i].x,60+m_button[i].y, m_button[i].w, m_button[i].h,renderer);
                //std::cout<<"button"+static_cast<char>(48 + (i-1)/10)+ static_cast<char>(48 + (i-1)%10);
        }
    }

 SDL_RenderPresent(renderer);

}
void game::handleEvents()
{
    SDL_Event ev;

    int button_x, button_y;
    int buttons = SDL_GetMouseState(&button_x, &button_y);
    if(buttons & SDL_BUTTON_LEFT)
    {
        for(int i = 0;i<15;i++)
        {
            if(button_x > 70+m_button[i].x && button_x <70+ m_button[i].x + m_button[i].w && button_y > 70+m_button[i].y && button_y < 70+m_button[i].y + m_button[i].h)
            {
                if(m_button[i].number == m_button[15].number + 4 && m_button[15].number <= 11)
                {
                    m_button[i].number = m_button[15].number;
                    m_button[15].number += 4;
                    won = checkWon(m_button);
                    m_soundManager.play_sound("click",0);
                    break;
                }
                else if(m_button[i].number == m_button[15].number-4 && m_button[15].number >=4)
                {
                    m_button[i].number = m_button[15].number;
                    m_button[15].number -= 4;
                    won = checkWon(m_button);
                    m_soundManager.play_sound("click",0);
                    break;
                }
                else if(m_button[i].number == m_button[15].number+1 && m_button[15].number%4!=3)
                {
                    m_button[i].number = m_button[15].number;
                    m_button[15].number += 1;
                    won = checkWon(m_button);
                    m_soundManager.play_sound("click",0);
                    break;
                }
                else if(m_button[i].number == m_button[15].number-1 && m_button[15].number%4!=0)
                {
                    m_button[i].number = m_button[15].number;
                    m_button[15].number -= 1;
                    won = checkWon(m_button);
                    m_soundManager.play_sound("click",0);
                    break;
                }

            }
        }
    }

    while(SDL_PollEvent(&ev)!=0)
    {
        switch(ev.type)
        {
        case SDL_QUIT:
            m_running = false;
            break;
        case SDL_KEYDOWN:
            switch(ev.key.keysym.scancode)
            {
            case SDL_SCANCODE_2:
                won = true;
            break;
            case SDL_SCANCODE_KP_8:
            case SDL_SCANCODE_W:
                if(m_button[15].number > 11)
                    break;
                    for(int i=0;i<16;i++)
                    {
                        if(m_button[i].number == m_button[15].number+4)
                        {
                            m_button[i].number = m_button[15].number;
                        }
                    }
                    m_button[15].number += 4;
                    won = checkWon(m_button);
                break;
            case SDL_SCANCODE_KP_2:
            case SDL_SCANCODE_S:

                if(m_button[15].number < 4)
                    break;
                    for(int i=0;i<16;i++)
                    {
                        if(m_button[i].number == m_button[15].number-4)
                        {
                            m_button[i].number = m_button[15].number;
                        }
                    }
                    m_button[15].number -= 4;
                    won = checkWon(m_button);

                break;
            case SDL_SCANCODE_KP_4:
            case SDL_SCANCODE_A:

                if(m_button[15].number%4 == 3)
                    break;
                    for(int i = 0;i<16;i++)
                    {
                        if(m_button[i].number == m_button[15].number+1)
                        {
                            m_button[i].number = m_button[15].number;
                        }
                    }
                    m_button[15].number += 1;
                    won = checkWon(m_button);
                    break;
            case SDL_SCANCODE_KP_6:
            case SDL_SCANCODE_D:

                if(m_button[15].number%4 == 0)
                    break;
                    for(int i = 0;i<16;i++)
                    {
                        if(m_button[i].number == m_button[15].number-1)
                        {
                            m_button[i].number = m_button[15].number;
                        }
                    }
                    m_button[15].number -= 1;
                    won = checkWon(m_button);
                    break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}
void game::update()
{
    setPosition(m_button);
    if(won)
    {
    static int count = 0;
    count++;
     generateRandom(m_button);
     m_soundManager.play_sound("click",0);
     if(count>10)
     {
         count = 0;
         won = false;
     }
    }
}
void game::clean()
{
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
