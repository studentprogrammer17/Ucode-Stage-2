#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t size = mx_strlen(s1);

    if (n < size) {
        size = n;
    }

    char *return_str = mx_strnew(size);
    mx_strncpy(return_str, s1, size);
    
    return return_str;
}

