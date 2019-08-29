#include"assets.h"

button::button()
{
    time_t t;
	srand((unsigned)time(&t));
    w = 60;
    h = 60;
    x=y=0;
    caption = 0;
    number = 20;
    pressed = false;
    moving = false;
}
void setPosition(button p_button[16])
{
    for(int i=0;i<16;i++)
    {
        p_button[i].x=(p_button[i].number%4)*P_BUTTON_WIDTH;
        p_button[i].y=(p_button[i].number/4)*P_BUTTON_HEIGHT;
    }
}
bool button::changeCaption(int p_caption)
{
    if(p_caption >0 && p_caption <16)
    {
        caption = p_caption;
        return true;
    }
    return false;
}
void generateRandom(button p_button[16])
{
    int i = 0,flag=0;

	for(i=0;i<15;i++)
    {
        p_button[i].caption = i+1;
    }
    i=0;
    while(i<16)
    {
        int random = randomNumber(15);
        while(1)
        {
            flag=0;
            for(int j = 0;j<15;j++)
            {
                if(p_button[j].number==random)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                random = randomNumber(15);
            }
            else
                break;
        }
        p_button[i].number=random;
        i++;
    }
}
int randomNumber(int max)
{
    return rand()%(max+1);
}
std::string integerToString(int number)
{
    std::string str="";
    str = str+static_cast<char>(48 + number/10) + static_cast<char>(48 + number%10);
return str;

}

bool checkWon(button p_button[16])
{
    for(int i = 0;i<15;i++)
    {
        if(p_button[i].caption != p_button[i].number+1)
            return false;
    }
    return true;
}
