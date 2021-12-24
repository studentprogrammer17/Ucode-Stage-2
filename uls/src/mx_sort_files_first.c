#include "uls.h"

void mx_fort_files_first(char **names) {
    int count = 0;
    char *temp;

    for(int i = 1; names[i] != NULL; i++) {
        count++;
    }

      for(int i = 0; i <= count; i++){
        for(int j = i + 1; j <= count; j++){
            if(mx_strcmp(names[i], names[j]) > 0){
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }

    //   for(int i = 1; i <= count; i++){
    //     for(int j = i + 1; j <= count; j++){
    //         if(mx_isFile(names[i])){
    //             temp = names[i];
    //             names[i] = names[j];
    //             names[j] = temp;
    //         }
    //     }
    // }

    //      for(int i = 1; i <= count; i++){
    //     for(int j = i + 1; j <= count; j++){
    //         if(!mx_isFile(names[j]) && mx_strcmp(names[i], names[j]) > 0){
    //             temp = names[i];
    //             names[i] = names[j];
    //             names[j] = temp;
    //         }
    //     }
    // }
}

