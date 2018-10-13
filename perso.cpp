#include "game.h"
#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "perso.h"



/* init */
Perso::Perso():posx_(300), posy_(300),width_(PERSO_SIZE), height_(PERSO_SIZE), speedx_(3), speedy_(1.), dirx_(0), diry_(1), orientation_(1), initJump_(0), initFall_(0), initFallPosy_(0), initFallSpeedy_(0), isJumping_(0){
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
        speedy_ = JUMP_SPEED;
        initFall_ = SDL_GetTicks();
        initFallPosy_ = (SCREEN_HEIGHT - posy_);
        initFallSpeedy_ = speedy_;
        
    }
    
}

void Perso::dash(){
    int posx = posx_ + (DASH_VAL * orientation_);
    if(!collide()){
        posx_ = posx;
    }else{
        if(posx >= SCREEN_WIDTH - width_){
            posx_ = SCREEN_WIDTH - width_ - 1;
        }else{
            posx_ = 0;
        }
    }
    
    
}

void Perso::fall(){
    double posy = (initFallPosy_) + (initFallSpeedy_ * (SDL_GetTicks() - initFall_)) +  ((int)(GRAVITY * ((SDL_GetTicks() - initFall_)*(SDL_GetTicks() - initFall_)))>>1) ;
    if (posy < SCREEN_HEIGHT && (posy > height_) && !collide()){ 
        posy_ = (int)(SCREEN_HEIGHT - posy);
        speedy_ = initFallSpeedy_ + GRAVITY * (SDL_GetTicks() - initFall_);
    }else{
        if(posy < height_){
            posy_ = SCREEN_HEIGHT - height_;
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

void Perso::setOrientation(int orientation){
    orientation_ = orientation;
}

/* other */
bool Perso::collide(){
    return (posx_ < 0 || posx_ > SCREEN_WIDTH - width_ || posy_ < 0 || posy_ > SCREEN_HEIGHT - height_);
}


            


