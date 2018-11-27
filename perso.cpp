#include "game.h"
#include <SDL/SDL.h>
#include <cmath>
#include <iostream>
#include "perso.h"




/* init */
Perso::Perso():posx_(490), posy_(310),width_(PERSO_SIZE), height_(PERSO_SIZE), speedx_(3), speedy_(1.), dirx_(0), diry_(1), orientation_(1), initJump_(0), initFall_(SDL_GetTicks()), initFallPosy_(SCREEN_HEIGHT - posy_), initFallSpeedy_(0), isJumping_(0), hasJustLanded_(false){
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
   int yolo = map.map_[0][0];
   yolo ++;
    
}

void Perso::fall(Map map){
    int ground = 60;
    
    //int screen_heigth = SCREEN_HEIGHT;
    double posy = (initFallPosy_) + (initFallSpeedy_ * (SDL_GetTicks() - initFall_)) +  ((int)(GRAVITY * ((SDL_GetTicks() - initFall_)*(SDL_GetTicks() - initFall_)))>>1) ;
    //ground = 1 + posy / 60;
    posy = posy > 0 ? posy : 0;
    bool coll = collideX(map, posx_ ,(int)posy);
    bool imup = isMapUnderPlayer(map, posx_, posy);
    
    
    if (!coll){ //saut
       // printf("imup = %d\n", imup);
        posy_ = (int)(SCREEN_HEIGHT - posy);
        speedy_ = initFallSpeedy_ + GRAVITY * (SDL_GetTicks() - initFall_);
        initJump_ = SDL_GetTicks();
        hasJustLanded_ = true;
        //printf("dans fall cas !collide()\n");
    }else{
        if(!imup){
            initFall_ = SDL_GetTicks();
            initFallPosy_ = (SCREEN_HEIGHT - posy_);
            initFallSpeedy_ = speedy_;
            hasJustLanded_ = true;
            //printf("not map under player\n");
        }else{
            if(hasJustLanded_){
                posy_ = SCREEN_HEIGHT - (posy - ((int)posy % PERSO_SIZE)) - PERSO_SIZE - ground;
                //printf("Corrige la position du joueur\n");
                hasJustLanded_ = false;
            }
            
            isJumping_ = 0;
            speedy_ = 0; 
        }
    }
    //printf("posy_ = %d\n", posy_);
    //printf("posy_ = %d, posy = %f, ground = %d\n", posy_, posy, ground);
}

bool Perso::isMapUnderPlayer(Map map, int posx, int posy){
    int indx, indy;
    indx = (posx ) / SQUARE_SIZE;
    indy = 11 - (posy / SQUARE_SIZE);
    bool coll = false;
    coll = coll || (indy > 11 ? map.map_[11][indx] : map.map_[indy][indx]) != 0;
    indx=(posx + width_) / SQUARE_SIZE;
    coll = coll || map.map_[indy][indx] != 0;
    //printf("imup[%d][%d] = %d\n", indy, indx, coll);
    return coll;
}



bool Perso::collideX(Map map, int posx, int posy){
        printf("Test des collisions, nouvelle boucle\n");
        bool coll = false;
        for(int i = 0; i< 18; i++){
            for (int j = 0; j< 12; j++){
                if(map.map_[j][i] !=0){
                    coll = coll || collideY(posx, posy, i, j);
                    coll = coll || collideY(posx + PERSO_SIZE, posy, i, j);
                    coll = coll || collideY(posx + PERSO_SIZE, posy + PERSO_SIZE, i, j);
                    coll = coll || collideY(posx, posy + PERSO_SIZE, i, j);
                    printf("apres tour i = %d, j = %d, coll = %d\n",i,j,coll);
                    if(coll == 1){
                        printf("map[%d][%d] = %d\n", j, i, coll);
                        printf("indx = %d, indy = %d\n", (posx / SQUARE_SIZE), (11 - (posy / SQUARE_SIZE))); 
                    }
                }
            }
        }
        coll = coll || posy - PERSO_SIZE < 0 ;
        coll = coll || posx < 0 ;
        coll = coll || posx + PERSO_SIZE > SCREEN_WIDTH;
        printf("posx = %d, posy = %d, coll = %d\n", posx, posy, coll);
        return coll;
}


bool Perso::collideY(int x, int y, int i, int j){
    bool collx = false;
    bool colly = false;
    collx = (x >= SQUARE_SIZE * j && x <= SQUARE_SIZE * (j + 1));
    colly = y >= SQUARE_SIZE * i && y <= SQUARE_SIZE * (i + 1);
    return (collx && colly);
   
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



            


