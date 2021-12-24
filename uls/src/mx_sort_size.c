#include "uls.h"

void mx_sort_size(char *argv[]) {
    DIR *dp = NULL;
    //struct dirent *entry;
    dp = opendir(".");

    struct stat statbuf_1;
    struct stat statbuf_2;

    int count = 0; 
    char *temp;

    for(int i = 1; argv[i] != NULL; i++) {
        if(argv[i][0] == '-' && argv[i][1] == 'l') {
            continue;
        }
        count++;
    }

    for (int i = 1;i <= count; i++) {
        for (int j = i + 1;j <= count; j++) {
            lstat(argv[i],&statbuf_1);
            lstat(argv[j],&statbuf_2);
            if (statbuf_1.st_size > statbuf_2.st_size) {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }
}

