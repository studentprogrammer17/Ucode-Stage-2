#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if(str == NULL) {
        return -1;
    }
    
    int words = 0;

    int flag = 1;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == c) {
            flag = 1;
        }

        else if(flag == 1) {
            flag = 0;
            words++;
        }
    }
    
    return words;
}

