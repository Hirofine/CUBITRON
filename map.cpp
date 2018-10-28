#include "map.h"
#include <stdio.h>
#include <iostream>

#define MAP "map.txt"
#define SQUARE_SIZE 60
Map::Map():width_(1080), height_(720), map_(){
     charge();
}

int Map::charge(){
    
    FILE* texte = fopen(MAP, "r");
    int temp = 0;
    while(temp != '#'){
        temp = fgetc(texte);
    }
    int i = 0 , j = 0;
    while(i < 12){
        if(temp == '#' || temp == 10){
            temp = fgetc(texte);
        }else{
            map_[i][j] = temp - 48;
            temp = fgetc(texte);
            j = j + 1;
            if(j == 18){
                j = 0;
                i = i + 1;
            }
        }
    }
   
    fclose(texte);
    
}
