#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if (str == NULL) {
        return NULL;
    }
    
    char *temp_str = NULL;
    char *return_str = NULL;
    int i = 0;
    int j = 0;

    temp_str = mx_strnew(mx_strlen(str));
    while (str[i]) {
        if (!(mx_isspace(str[i]))) {
            temp_str[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            temp_str[j] = ' ';
            j++;
        }
        i++;
    }
    return_str = mx_strtrim(temp_str);
    mx_strdel(&temp_str);
    return return_str;

}

