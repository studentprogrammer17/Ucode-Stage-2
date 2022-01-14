#include "ush.h"

void smesh(int m, int size, char *road){
    for (int i = 0; i < m; i++){ 
        char temp = *road; 
        for (int j = 0; j < size - 1; j++){
            road[j] = road[j+1]; 
        }    
        road[size - 1] = temp; 
    }
}

