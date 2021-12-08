#ifndef STATES_HPP_INCLUDED
#define STATES_HPP_INCLUDED
#include "SFML/Audio.hpp"
#include <math.h>

#include "utils.h"
#define PI 3.14159265
class State{
public:
    Sprite *objArray[MAX_OBJ_SIZE];
    int objCount = 0;
    bool* add(Sprite *obj){
        obj->ID = objCount++;
        objArray[objCount - 1] = obj;
    }
    void updateObj(sf::RenderWindow* app){
        for(int i=0; i<objCount; i++){
            app->draw(objArray[i]->sprite);
        }
    }
    State(void){}
    ~State(void){
        for(int i=0; i<objCount; i++){
            delete objArray[i];
        }
    }
    virtual void* create(){};
    virtual void* update(){};
    virtual void* keyPress(){};
};
State *curState;
template<typename T>
void switchState(){
    delete curState;
    T *gamestate = new T();
    gamestate->create();
    curState = gamestate;
    //gamestate->create();
    //curUpdate = (void*)&gamestate->update;
}
class MenuState : public State
{
public:
    void* create() override {
    }
    void* update() override{
    }
};

class MainState : public State
{
public:
    Sprite *logo;
    Sprite *them;
    Sprite *black;
    bool aktivate = false;
    float time;
    virtual void* create() override {
        logo = new Sprite();
        logo->load("boohbah.png");
        add(logo);
        them = new Sprite();
        them->load("them.png");
        them->setPosition(150, 300);
        add(them);
        black = new Sprite();
        black->load("black.png");
        add(black);
        black->sprite.setColor((sf::Color)createRGBA(0, 0, 0, 0));
        playSound("fuck.ogg", true);
        //std::cout<<playSound("fuck.ogg")?"succeeded":"jk it didn't";
    };
    int as = 0;
    void* update() override {
        time += 0.1;
        them->sprite.move(0, 10 * sin(time * (PI*0.2) / 2));

        if(aktivate){
                as+=2;
            black->sprite.setColor((sf::Color)createRGBA(0, 0, 0, as));
            if(as > 253){
                aktivate = false;
                switchState<MenuState>();
            }
        }
    };
    void* keyPress() override {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            aktivate = true;
        }
    };
};

#endif // STATES_HPP_INCLUDED
