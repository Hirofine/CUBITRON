#include "game.h"
#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "perso.h"



/* init */
Perso::Perso():posx_(300), posy_(300),width_(100), height_(100), speedx_(3), speedy_(1.), dirx_(0), diry_(1), initJump_(0), initFall_(0), initFallPosy_(0), initFallSpeedy_(0), isJumping_(0){
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
    if(isJumping_ == 0){
        speedy_ = 2.3;
        initFall_ = SDL_GetTicks();
        initFallPosy_ = (720 - posy_);
        initFallSpeedy_ = speedy_;
        
    }
    
}

void Perso::fall(){
    double posy = (initFallPosy_) + (initFallSpeedy_ * (SDL_GetTicks() - initFall_)) +  ((int)(-0.01 * ((SDL_GetTicks() - initFall_)*(SDL_GetTicks() - initFall_)))>>1) ;
    if (posy < 720 && (posy > 100) && !collide()){ 
        posy_ = (int)(720 - posy);
        speedy_ = initFallSpeedy_ + -0.01 * (SDL_GetTicks() - initFall_);
    }else{
        if(posy < 100){
            posy_ = 620;
            isJumping_ = 0;
            
        }else{
            speedy_ = 0;
        }
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

void Perso::setIsJumping(int val){
    isJumping_ = val; 
}

/* other */
bool Perso::collide(){
    return (posx_ < 0 || posx_ > 1024 || posy_ < 0 || posy_ > 720);
}


            


