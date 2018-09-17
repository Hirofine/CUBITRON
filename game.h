#ifndef _GAME_H_
#define _GAME_H_

#include <SDL/SDL.h>


class Game{
public:
  Game();
  bool running();
  bool initSDL(const char* title, int width, int height, int bpp);
  void clean();
  void draw();
  void handleEvents();
  
private:
  void putpixel(int x, int y, Uint32 pixel);
  Uint32 getpixel(int itex, int x, int y);
  
  bool game_running_;
  SDL_Surface * sdl_screen_;
};

#endif