#include <stdlib.h>

char *mx_strdup(const char *str);

char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);

char *mx_strnew(const int size);

char *mx_strdup(const char *str) {

    char *return_str = mx_strnew(mx_strlen(str));
    
    mx_strcpy(return_str, str);

    return return_str;
}

