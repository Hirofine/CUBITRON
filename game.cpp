#include "game.h"
#include <iostream>

Game::Game():game_running_(false), sdl_screen_(NULL){
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

SDL_ShowCursor(SDL_DISABLE);
  
return true;
}

void Game::handleEvents(){
  SDL_Event event;
  if(SDL_PollEvent(&event)){
    game_running_ = !(SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym));
  }
}

void Game::draw(){
  
}

bool Game::running(){
  return game_running_;
}

void Game::clean(){
}