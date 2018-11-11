#include "game.h"
#include <SDL/SDL.h>

int main(){
 Game game;
 game.perso.setY(360);
 game.initSDL("jeu", 1080, 720, 3);
 game.perso.setY(360);

 int n = 0;
 int i,j;
 int fps = 0;
 for(i =0; i< 12; i++){
        for(j = 0; j< 18; j++){
            printf("%d, ", game.map.map_[i][j]);
        }
        printf("\n");
    }
 while(game.running()){
    game.handleEvents();
    game.draw();
    n++;
   // printf("time = %d\n", SDL_GetTicks());
    /* fps */
    fps = fps +1;
    if(SDL_GetTicks() % 1000 < 15){
        printf("                                                fps = %d\n", fps);
        fps = 0;
    }

 }
 game.clean();
 return 0;
}
