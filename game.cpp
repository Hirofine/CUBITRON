#include "game.h"
#include <iostream>

Game::Game():perso(), game_running_(false), sdl_screen_(NULL), textures_(NULL), ntextures(0), textsize(0), bpp_(0), width_(0), height_(0){
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
            perso.setDirX(-1);
            perso.setOrientation(-1);
        }
        if('d' == event.key.keysym.sym){
            perso.setDirX(1);
            perso.setOrientation(1);
        }
        if(' ' == event.key.keysym.sym){
             perso.jump();
             perso.setIsJumping(1);
        }
        if('e' == event.key.keysym.sym){
            perso.dash();
        }
    }
    if(SDL_KEYUP == event.type){
        if('q' == event.key.keysym.sym && perso.getDirX() == -1){
            perso.setDirX(0);
        }
        if('d' == event.key.keysym.sym && perso.getDirX() == 1){
            perso.setDirX(0);
        }
    }
  }
}

void Game::draw(){
    SDL_FillRect(sdl_screen_, NULL, SDL_MapRGB(sdl_screen_->format, 0, 0, 0));
    movePerso(&perso);
    perso.fall();
    
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
    
    for(int i = 0; i < perso.getWidth(); i++){
        for(int j = 0; j < perso.getHeight(); j++){
            putpixel(perso.getX() + i, perso.getY() + j, SDL_MapRGB(sdl_screen_->format, 255,255,255));
        }
    }
}

void Game::movePerso(Perso *perso){
    int posx = perso->getX() + (perso->getSpeedx() * perso->getDirX());
    if (posx >=0 && posx <= (width_ - perso->getWidth())){
        perso->setX(posx);
    }
}
