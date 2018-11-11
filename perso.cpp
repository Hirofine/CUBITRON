#include "game.h"
#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "perso.h"




/* init */
Perso::Perso():posx_(490), posy_(310),width_(PERSO_SIZE), height_(PERSO_SIZE), speedx_(3), speedy_(1.), dirx_(0), diry_(1), orientation_(1), initJump_(0), initFall_(SDL_GetTicks()), initFallPosy_(SCREEN_HEIGHT - posy_), initFallSpeedy_(0), isJumping_(0){
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
    
}

void Perso::fall(Map map){
    int ground = 0;
    int screen_heigth = SCREEN_HEIGHT;
    double posy = (initFallPosy_) + (initFallSpeedy_ * (SDL_GetTicks() - initFall_)) +  ((int)(GRAVITY * ((SDL_GetTicks() - initFall_)*(SDL_GetTicks() - initFall_)))>>1) ;
    //ground = 1 + posy / 60;
    posy = posy > 0 ? posy : 0;
    bool coll = collideY(posy);
    bool imup = isMapUnderPlayer(map, posx_, posy);
    
    
    if (!coll && !imup){ //saut
       // printf("imup = %d\n", imup);
        posy_ = (int)(SCREEN_HEIGHT - posy);
        speedy_ = initFallSpeedy_ + GRAVITY * (SDL_GetTicks() - initFall_);
        //printf("dans fall cas !collide()\n");
    }else{
        
        //TODO check presence or not of map under player
            // fin du saut
            if(imup){
                
                ground = 1 + (posy) / 60;
                printf("ground = %d\n", ground);
                screen_heigth = SCREEN_HEIGHT - 60;
                //printf("imup = 1, ground = %d, posy = %d, posy_ = %d\n",ground, posy, posy_);
            }else{
                ground = 0;
            }
      //      printf("dans fall cas collide\n");
            posy_ = SCREEN_HEIGHT - width_ -  60 * ground;
            
            isJumping_ = 0;
            speedy_ = 0; 
    }
    //printf("posy_ = %d\n", posy_);
    //printf("posy_ = %d, posy = %f, ground = %d\n", posy_, posy, ground);
}

bool Perso::isMapUnderPlayer(Map map, int posx, int posy){
    int indx, indy;
   // printf("in imup, posx = %d\n", posx);
    indx = (posx ) / SQUARE_SIZE;
    indy = 11 - (posy / SQUARE_SIZE);
   // printf("imup indy = %d\n", indy);
    //printf("indx = %d, indy = %d\n", indx, indy);
    bool coll = false;
    coll = coll || (indy > 11 ? map.map_[11][indx] : map.map_[indy][indx]) != 0;
   // printf("map[%d][%d] = %d\n",indy ,indx,map.map_[indy][indx]);
    indx=(posx + width_) / SQUARE_SIZE;
    coll = coll || map.map_[indy][indx] != 0;
    //printf("map[%d][%d] = %d\n",indy,indx,map.map_[indy][indx]);
   // printf("coll = %d\n", coll);
//     printf("coll map = %d\n", coll);
    return coll;
}

bool Perso::collideY(int posy){
    bool coll = false;
    if(posy - width_ < 0){
        coll = true;
    }
    return coll;
   
}

bool Perso::collideX(Map map, int posx){
        bool coll = false;
        if(posx < 0 || posx > SCREEN_WIDTH - width_){
            coll = true;
        }
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

void Perso::setOrientation(int orientation){
    orientation_ = orientation;
}

/* other */



            


