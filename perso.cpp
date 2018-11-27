#include "game.h"
#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "perso.h"




/* init */
Perso::Perso():posx_(490), posy_(310),width_(PERSO_SIZE), height_(PERSO_SIZE), speedx_(PERSO_SPEED), speedy_(1.), dirx_(0), diry_(1), orientation_(1), initJump_(0), initFall_(SDL_GetTicks()), initFallPosy_(SCREEN_HEIGHT - posy_), initFallSpeedy_(0), isJumping_(0), hasJustLanded_(false){
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
    if(isJumping_ < 2){
        speedy_ = JUMP_SPEED;
        initFall_ = SDL_GetTicks();
        initFallPosy_ = (SCREEN_HEIGHT - posy_);
        initFallSpeedy_ = speedy_;
        
    }
    
}

void Perso::dash(Map map){
   /* int posx = posx_ + (DASH_VAL * orientation_);
    if(!collideY(map, posy_)){
        posx_ = posx;
    }else{
        if(posx >= SCREEN_WIDTH - width_){
            posx_ = SCREEN_WIDTH - width_ - 1;
        }else{
            posx_ = 0;
        }
    }
    */
   int yolo = map.map_[0][0];
   yolo ++;
    
}

void Perso::fall(Map map){
    int ground = 60;
    int screen_heigth = SCREEN_HEIGHT - SQUARE_SIZE;
    double posy = (initFallPosy_) + (initFallSpeedy_ * (SDL_GetTicks() - initFall_)) +  ((int)(GRAVITY * ((SDL_GetTicks() - initFall_)*(SDL_GetTicks() - initFall_)))>>1) ; // equation 
    posy = posy > 0 ? posy : PERSO_SIZE;
    bool coll = collide(posx_ ,(int)posy);
    
    if (!coll){ //saut
        posy_ = (int)(screen_heigth - posy);
        speedy_ = initFallSpeedy_ + GRAVITY * (SDL_GetTicks() - initFall_);
        initJump_ = SDL_GetTicks();

    }else{
            posy_ = screen_heigth - SQUARE_SIZE - PERSO_SIZE;
            isJumping_ = 0;
    }
}





bool Perso::collide(int posx, int posy){
        bool coll = false;
        coll = coll || posy - PERSO_SIZE < 0 ;
        coll = coll || posx < 0 ;
        coll = coll || posx + PERSO_SIZE > SCREEN_WIDTH - SQUARE_SIZE;
        return coll;
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

void Perso::incIsJumping(){
    isJumping_ += 1;
}

void Perso::setOrientation(int orientation){
    orientation_ = orientation;
}

/* other */



            


