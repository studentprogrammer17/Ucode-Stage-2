#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    int size_src = 0;

    for(int i = 0; src[i] != '\0'; i++) size_src++;

    for(int i = 0; i < size_src; i++) {
        dst[i] = src[i];
    }
    dst[size_src] = '\0';
    return dst;
}

