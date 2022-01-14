#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *ptr_dst = (char *)dst;
    const char *ptr_src =( const char*)src;

    char *tmp  = (char *)malloc(sizeof(char ) * len);
    if(tmp == NULL) {
        return NULL;
    }

    else {
        unsigned int i = 0;

        for(i =0; i < len ; ++i) {
            *(tmp + i) = *(ptr_src + i);
        }

        for(i =0 ; i < len ; ++i) {
            *(ptr_dst + i) = *(tmp + i);
        }
        free(tmp); 
    }
    return dst;
}

