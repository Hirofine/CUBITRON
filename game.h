#ifndef _GAME_H_
#define _GAME_H_

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720
#include <SDL/SDL.h>
#include "perso.h"
 
class Game{
public:
  Game();
  bool running();
  bool initSDL(const char* title, int width, int height, int bpp);
  void clean();
  void draw();
  void handleEvents();
  Perso perso;
  void drawObject();
  void movePerso(Perso *perso);
  
private:
  void putpixel(int x, int y, Uint32 pixel);
  Uint32 getpixel(int itex, int x, int y);
  
  bool game_running_;
  SDL_Surface * sdl_screen_;
  SDL_Surface * textures_;
  int ntextures;
  int textsize;
  
  int bpp_;
  int width_;
  int height_;
};

#endif
