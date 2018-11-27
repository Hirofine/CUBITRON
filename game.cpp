#include "game.h"
#include <iostream>


Game::Game():perso1(), perso2(), map(), game_running_(false), sdl_screen_(NULL), textures_(NULL), ntextures(0), textsize(0), bpp_(0), width_(0), height_(0){
   
}

bool Game::initSDL(const char* title, int width, int height, int bpp){
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cerr << "SDL_Init failed, SDL_GetError()=" << SDL_GetError() ;
        return false;
    }
    SDL_WM_SetCaption(title, NULL);
    sdl_screen_ = SDL_SetVideoMode(width, height, 8*bpp, 0);
    if (!sdl_screen_) {
        std::cerr << "SDL_SetVideoMode failed, SDL_GetError()=" << SDL_GetError() ;
        return false;
    }
    game_running_ = true;
    bpp_ = bpp;
    width_ = width;
    height_ = height;
SDL_ShowCursor(SDL_DISABLE);
  
return true;
}

void Game::handleEvents(){
  SDL_Event event;
  if(SDL_PollEvent(&event)){
    game_running_ = !(SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym));
    if(SDL_KEYDOWN == event.type){
        if('q' == event.key.keysym.sym){
            perso1.setDirX(-1);
            perso1.setOrientation(-1);
        }
        if('d' == event.key.keysym.sym){
            perso1.setDirX(1);
            perso1.setOrientation(1);
        }
        if(' ' == event.key.keysym.sym){
             perso1.jump();
             perso1.incIsJumping();
        }
        if('e' == event.key.keysym.sym){
            perso1.dash(map);
        }
        if(SDLK_KP0 == event.key.keysym.sym){
            perso2.jump();
            perso2.incIsJumping();
        }
        if(SDLK_RIGHT == event.key.keysym.sym){
            perso2.setDirX(1);
            perso2.setOrientation(1);
        }
        if(SDLK_LEFT == event.key.keysym.sym){
            perso2.setDirX(-1);
            perso2.setOrientation(-1);
        }
        if('1' == event.key.keysym.sym){
            perso1.dash(map);
        }
        
    }
    if(SDL_KEYUP == event.type){
        if('q' == event.key.keysym.sym && perso1.getDirX() == -1){
            perso1.setDirX(0);
        }
        if('d' == event.key.keysym.sym && perso1.getDirX() == 1){
            perso1.setDirX(0);
        }
        if(SDLK_LEFT == event.key.keysym.sym && perso2.getDirX() == -1){
            perso2.setDirX(0);
        }
        if(SDLK_RIGHT == event.key.keysym.sym && perso2.getDirX() == 1){
            perso2.setDirX(0);
        }
    }
  }
}

void Game::draw(){
    SDL_FillRect(sdl_screen_, NULL, SDL_MapRGB(sdl_screen_->format, 0, 0, 0));
    movePerso(&perso1);
    movePerso(&perso2);
    drawMap();
    
    drawObject();
    SDL_Flip(sdl_screen_);
}

bool Game::running(){
  return game_running_;
}

void Game::clean(){
}

void Game::putpixel(int x, int y, Uint32 pixel){
    if(x < 0 || y < 0 || x >= sdl_screen_->w || y >= sdl_screen_->h){
        
        return;
    }
    Uint8 *p = (Uint8 *)sdl_screen_->pixels + y*sdl_screen_->pitch + x*bpp_;
    for(int i=0; i<bpp_; i++){
        p[i] = ((Uint8*)&pixel)[i];
    }
}
void Game::drawObject(){
    //int random = rand();
    for(int i = 0; i < perso1.getWidth(); i++){
        for(int j = 0; j < perso1.getHeight(); j++){
            putpixel(perso1.getX() + i, perso1.getY() + j, SDL_MapRGB(sdl_screen_->format, 255,0,255));
        }
    }
    for(int i = 0; i < perso2.getWidth(); i++){
        for(int j = 0; j < perso2.getHeight(); j++){
            putpixel(perso2.getX() + i, perso2.getY() + j, SDL_MapRGB(sdl_screen_->format, 255,255,0));
        }
    }
    /*
    for(int i = 0; i < perso.getWidth() + 40; i++){
        for(int j = 0; j < perso.getHeight() + 40; j++){
            if(i < 20 || i > perso.getWidth() || j < 20 || j > perso.getHeight()){
                if(random%30 == 0 ){
                    putpixel(perso.getX() - 20 + i, perso.getY() - 20 + j, SDL_MapRGB(sdl_screen_->format, 255,255,0));
                }
                random = rand();
            }
        }
    }*/
    
}

void Game::drawMap(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){
            switch(map.map_[i][j]){
                case 1:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 200,200,200));
                        }
                    }
                    break;
                case 2:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 20,20,20));
                        }
                    }
                    break;
                case 3:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 45,45,45));
                        }
                    }
                    break;
                case 4:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 70,70,70));
                        }
                    }
                    break;
                case 5:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 100,100,100));
                        }
                    }
                    break;
                case 6:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 125,125,125));
                        }
                    }
                    break;
                case 7:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 150,150,150));
                        }
                    }
                    break;
                case 8:
                    for(int k = 60 * i; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 175,175,175));
                        }
                    }
                    break;
                case 9:
                    for(int k = 60 * i + 30; k< 60 * i + 60; k++){
                        for(int l = 60 * j; l< 60 * j + 60; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 255,0,0));
                        }
                    }
                    break;
            }
        }
    }
}

void Game::movePerso(Perso *perso){
    int posx = perso->getX() + (perso->getSpeedx() * perso->getDirX());
    if (posx > 0 && posx < SCREEN_WIDTH - perso->getWidth()){
        perso->setX(posx);
    }
    perso->fall(map);
}
/*
bool Game::collide(){
    int posx = perso.getX() + (perso.getSpeedx() * perso.getDirX());
    int posy = perso.getY();
    //printf("posy = %d\n", posy);
    bool collide = false;
    bool temp = false;
    collide = collide || (posx <=0 || posx >= (width_ - perso.getWidth()));
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
    return collide;
}*/
