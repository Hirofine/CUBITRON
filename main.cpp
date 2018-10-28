#include "game.h"
#include <SDL/SDL.h>

int main(){
 Game game;
 game.perso.setY(360);
 game.initSDL("jeu", 1080, 720, 3);
 game.perso.setY(360);
 int n = 0;
 while(game.running()){
    game.handleEvents();
    game.draw();
    //printf("boucle %d finie\n", n);
    n++;
 }
 game.clean();
 return 0;
}
