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
        if('a' == event.key.keysym.sym){
            hit(&perso1, &perso2, 1);
        }
        if(SDLK_KP0 == event.key.keysym.sym){
            perso2.jump();
            perso2.incIsJumping();
        }
        if(SDLK_KP2 == event.key.keysym.sym){
            hit(&perso2, &perso1, 1);
        }
        if(SDLK_RIGHT == event.key.keysym.sym){
            perso2.setDirX(1);
            perso2.setOrientation(1);
        }
        if(SDLK_LEFT == event.key.keysym.sym){
            perso2.setDirX(-1);
            perso2.setOrientation(-1);
        }
        if(SDLK_KP1 == event.key.keysym.sym){
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
    drawHealth();
    drawObject();
    SDL_Flip(sdl_screen_);
    if(perso1.getHealth() == 0){
        win(perso2);
    }else if(perso2.getHealth() == 0){
        win(perso1);
    }
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

void Game::drawHealth(){
    for(int i = 0; i < perso1.getHealth(); i++){
        for(int k = 30; k< 50; k++){
            for(int l = 20 * i; l< 20 * i + 20; l++){
                putpixel(l + 70, k, SDL_MapRGB(sdl_screen_->format, 255,0,0));
            }
        }
    }
    
    for(int i = perso2.getHealth(); i > 0; i--){
       for(int l = 20 * (20 - i) + 610; l < 1010; l++){
            for(int k = 30; k< 50; k++){
                putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 255,0,0));
            }
        }
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
    for(int i = 0; i < MAP_SIZE_Y; i++){
        for(int j = 0; j < MAP_SIZE_X; j++){
            switch(map.map_[i][j]){
                case 1:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 200,200,200));
                        }
                    }
                    break;
                case 2:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 20,20,20));
                        }
                    }
                    break;
                case 3:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 45,45,45));
                        }
                    }
                    break;
                case 4:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 70,70,70));
                        }
                    }
                    break;
                case 5:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 100,100,100));
                        }
                    }
                    break;
                case 6:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 125,125,125));
                        }
                    }
                    break;
                case 7:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 150,150,150));
                        }
                    }
                    break;
                case 8:
                    for(int k = SQUARE_SIZE * i; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
                            putpixel(l, k, SDL_MapRGB(sdl_screen_->format, 175,175,175));
                        }
                    }
                    break;
                case 9:
                    for(int k = SQUARE_SIZE * i + 30; k< SQUARE_SIZE * i + SQUARE_SIZE; k++){
                        for(int l = SQUARE_SIZE * j; l< SQUARE_SIZE * j + SQUARE_SIZE; l++){
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
    perso->fall();
}

void Game::hit(Perso *p1, Perso *p2, int damage){
    int distx = p1->getX() - p2->getX();
    distx *= distx;
    int disty = p1->getY() - p2->getY();
    disty *= disty;
    int dist = distx + disty;
    if(dist < 10000){
        p2->hit(damage);
        p1->animHit();
    }
    printf("%s %d hp || %s %d hp\n", p1->getNom(), p1->getHealth(), p2->getNom(), p2->getHealth());
}

void Game::win(Perso winner){
    printf("%s gagne!!\n", winner.getNom());
    SDL_Delay(1000);
    game_running_ = false;
}
