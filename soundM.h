#ifndef SOUNDM_H
#define SOUNDM_H
#include<SDL_mixer.h>
#include<iostream>
#include<map>

enum soundType{SOUND_MUSIC = 0, SOUND_SFX = 1};

class soundManager{
public:
    soundManager();
    ~soundManager();
    bool load(std::string fileName, std::string id, soundType type);
    void play_sound(std::string id, int loop);
    void play_music(std::string id, int loop);

private:
    std::map<std::string, Mix_Chunk*>m_sfx;
    std::map<std::string, Mix_Music*>m_music;


};
#endif // SOUNDM_H
