#include "game.h"
#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "perso.h"



/* init */
Perso::Perso():posx_(300), posy_(300),width_(50), height_(100), speedx_(1), speedy_(1.), dirx_(0), diry_(1){
}


/* all getters */
int Perso::getX(){
    return posx_;
}

int Perso::getY(){
    return posy_;
}

int Perso::getWidth(){
    return width_;
}

int Perso::getHeight(){
    return height_;
}

int Perso::getSpeedx(){
    return speedx_;
}

float Perso::getSpeedy(){
    return speedy_;
}

int Perso::getDirX(){
    return dirx_;
}

int Perso::getDirY(){
    return diry_;
}


/* all setters */
void Perso::jump(){
    
}

void Perso::fall(){
    int posy = posy_ + (speedy_);
    if (posy < (720 - height_)){ 
        posy_ = posy;
        speedy_ = speedy_ * 1;
    }else{
        speedy_ = 1;
    }
}

void Perso::setX(int x){
    posx_ = x;
}

void Perso::setY(int y){
    posy_ = y;
}

void Perso::setDirX(int dir){
    dirx_ = dir;
}

void Perso::setDirY(int dir){
    diry_ = dir;
}

void Perso::setSpeedx(int speed){
    speedx_ = speed;
}

void Perso::setSpeedy(float speed){
    speedy_ = speed;
}

/* other */
bool Perso::collide(){
    return (posx_ < 0 || posx_ > 1024 || posy_ < 0 || posy_ > 720);
}


            


