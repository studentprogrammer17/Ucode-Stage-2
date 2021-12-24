#include "uls.h"

char** mx_sort_dirs_by_alph(char *arr[],int argc) {
    char **n_arr = (char**)malloc(256);
    int n = 0;
    for(int i = 1; arr[i] != NULL; i++) {
        if(mx_isFile(arr[i])) continue;
        else {
            mx_strcpy(n_arr[n],arr[i]);
            n++;
        }
    }


    for(int i = 0; i < 3; i++) {
        mx_printstr(n_arr[i]);
        mx_printstr("\n");
    }
    mx_printstr("\n");

    for(int i = 1; arr[i] != NULL; i++){
        for(int j = 1; j < argc - 1 - i; j++){
        if(mx_isFile(arr[i])) continue;
        if(mx_strcmp(arr[j], arr[j+1]) > 0){
            char temp[256];
            mx_strcpy(temp, arr[j]);
            mx_strcpy(arr[j], arr[j+1]);
            mx_strcpy(arr[j+1], temp);
        }
        }
    }
    return arr;
}

