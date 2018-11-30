#include "map.h"
#include <stdio.h>
#include <iostream>


Map::Map(): map_(), width_(1080), height_(720){
     charge();
}

void Map::charge(){
    
    FILE* texte = fopen(MAP, "r");
    int temp = 0;
    while(temp != '#'){
        temp = fgetc(texte);
    }
    int i = 0 , j = 0;
    while(i < MAP_SIZE_Y){
        if(temp == '#' || temp == 10){
            temp = fgetc(texte);
        }else{
            map_[i][j] = temp - 48;
            temp = fgetc(texte);
            j = j + 1;
            if(j == MAP_SIZE_X){
                j = 0;
                i = i + 1;
            }
        }
    }
   
    fclose(texte);
    
}
