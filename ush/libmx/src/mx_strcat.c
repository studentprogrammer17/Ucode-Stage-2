#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int size_s1 = mx_strlen(s1);
    int size_s2 = mx_strlen(s2);
    
    int temp = size_s1;
    
    for(int i = 0; i < size_s1 + size_s2; i++,temp++) {
        s1[temp] = s2[i];
    }

    s1[size_s1 + size_s2] = '\0';

    return s1;
}

