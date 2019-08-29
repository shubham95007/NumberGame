#include"soundM.h"
soundManager::soundManager()
{
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 512);

}
bool soundManager::load(std::string fileName, std::string id, soundType type)
{
    if(type == SOUND_SFX)
    {
        Mix_Chunk* chunk = Mix_LoadWAV(fileName.c_str());
        if(chunk == 0)
        {
            std::cout<<"unable to load sfx "<<fileName<<" "<<Mix_GetError()<<std::endl;
            return false;
        }
        m_sfx[id] = chunk;
        return true;
    }
    else if(type == SOUND_MUSIC)
    {
        Mix_Music* music = Mix_LoadMUS(fileName.c_str());
        if(music == 0)
        {
            std::cout<<"unable to load music "<<fileName<<" "<<Mix_GetError()<<std::endl;
            return false;
        }
        m_music[id] = music;
        return true;
    }
    std::cout<<"wrong soundtype\n";
    return false;
}
void soundManager::play_sound(std::string id, int loop)
{
    Mix_PlayChannel(-1, m_sfx[id], loop);
}
void soundManager::play_music(std::string id, int loop)
{
    Mix_PlayMusic(m_music[id], loop);
}
soundManager::~soundManager()
{
    Mix_CloseAudio();
}
