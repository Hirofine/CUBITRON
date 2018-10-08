#include "game.h"
#include <SDL/SDL.h>

int main(){
 Game game;
 game.initSDL("jeu", 1080, 720, 3);
 while(game.running()){
   game.handleEvents();
   game.draw();
 }
 game.clean();
 return 0;
}
