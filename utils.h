#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "config.hpp"
class Sprite // why the shit didn't i extend this class to sf::Sprite
{
public:
    int ID;
    sf::Texture texture;
    sf::Sprite  sprite;
    bool load(std::string file){
        if (!texture.loadFromFile(file))
            return false;
        sprite.setTexture(texture);
        return true;
    }
    void setPosition(float x, float y){
        sprite.setPosition(x, y);
    }
};

//Sprite allOjects;
template<typename T> int countArray(T *array[]);
//void updateObj(sf::RenderWindow *app, Sprite *objArray[]);

bool add(Sprite *obj);

unsigned long createRGBA(int r, int g, int b, int a);

bool playSound(std::string dir, bool music);
//template<typename T> void switchState();

extern int objCount;
#endif // UTILS_H_INCLUDED
