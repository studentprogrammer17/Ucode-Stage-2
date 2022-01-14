#include "../inc/libmx.h"

char *mx_strdup(const char *str) {

    char *return_str = mx_strnew(mx_strlen(str));
    
    mx_strcpy(return_str, str);

    return return_str;
}

