#include "utils.h"
#include "SFML/Audio.hpp"
#include <pthread.h>

template<typename T>
int countArray(T *array[]){
    for(int i; i<sizeof(array); i++){
        if(strcmp(array[i], '\0') == 0) return i-1;
    }
}

unsigned long createRGBA(int r, int g, int b, int a)
{
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
           + (a & 0xff);
}

bool playSound(std::string dir, bool music){
    if(music){
        sf::Music* music = new sf::Music();
        if (!music->openFromFile("fuck.ogg"))
            return false; // error
        music->play();
        return true;
    }
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(dir))
        return false;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    return true;
}
