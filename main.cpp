#include "game.h"
#include <SDL/SDL.h>
#include <string>

int main(){
 Game game;
 char str1[] = "Player1";
 char str2[] = "Player2";
 game.initSDL("jeu", 1080, 720, 3);
 game.perso1.setX(50);
 game.perso2.setX(SCREEN_WIDTH - 50 - PERSO_SIZE);
 printf("Player1 : %s \n", str1);
 game.perso1.setNom(str1);
 game.perso2.setNom(str2);
 
 int n = 0;
 int i,j;
 int frame = 0;
 for(i =0; i< MAP_SIZE_Y; i++){
        for(j = 0; j< MAP_SIZE_X; j++){
            printf("%d,", game.map.map_[i][j]);
        }
        printf("\n");
    }
 while(game.running()){
    game.handleEvents();
    game.draw();
    n++;
   // printf("time = %d\n", SDL_GetTicks());
    /* fps */
    frame += 1;
    
    if(SDL_GetTicks() % 1000 < 10){
        printf("                                                fps = %d\n", frame);
        frame = 0;
    }

 }
 game.clean();
 return 0;
}
