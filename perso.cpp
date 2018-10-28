#include "game.h"
#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "perso.h"




/* init */
Perso::Perso():posx_(490), posy_(310),width_(PERSO_SIZE), height_(PERSO_SIZE), speedx_(3), speedy_(1.), dirx_(0), diry_(1), orientation_(1), initJump_(0), initFall_(0), initFallPosy_(0), initFallSpeedy_(0), isJumping_(0){
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

void Perso::dash(Map map){
    int posx = posx_ + (DASH_VAL * orientation_);
    if(!collide(map, posx, posy_)){
        posx_ = posx;
    }else{
        if(posx >= SCREEN_WIDTH - width_){
            posx_ = SCREEN_WIDTH - width_ - 1;
        }else{
            posx_ = 0;
        }
    }
    
    
}

void Perso::fall(Map map){
    
    double posy = (initFallPosy_) + (initFallSpeedy_ * (SDL_GetTicks() - initFall_)) +  ((int)(GRAVITY * ((SDL_GetTicks() - initFall_)*(SDL_GetTicks() - initFall_)))>>1) ;
    if (!collide(map, posx_, posy) && posy > height_ + 60){ //saut
        posy_ = (int)(SCREEN_HEIGHT - posy);
        speedy_ = initFallSpeedy_ + GRAVITY * (SDL_GetTicks() - initFall_);
        //printf("dans fall cas !collide()\n");
    }else{
        //TODO check presence or not of map under player
        if(posy < height_){ // fin du saut
           // printf("posy = %d\n", posy_);
            posy_ = SCREEN_HEIGHT - height_ - 61;;
            
            isJumping_ = 0;
            speedy_ = 0; 
            
        }else{
            speedy_ = 0;
        }
    }
    printf("posy_ = %d, posy = %f\n", posy_, posy);
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
bool Perso::collide(Map map, int posx, int posy){
    //printf("posy = %d\n", posy);
    bool collide = false;
    bool temp = false;
    collide = collide || (posx <=0 || posx >= (1080 - width_));
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){
            if(map.map_[i][j] != 0){
                temp = temp || (posx >= j * 60 && posx <= j* 60 + 60);
                temp = temp && posy >= 60 * i - 100 && posy <= 60 * i + 60 - 100;
                collide = collide || temp;
               // printf("collide = %d, temp = %d \n", collide, temp);
            }
        }
    }
   // printf("collide = %d, posy = %d\n", collide, posy);
    return collide;
}


            


