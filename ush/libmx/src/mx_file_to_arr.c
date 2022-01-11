#include "../inc/libmx.h"

char **mx_file_to_arr(const char *file) {
    char *str = mx_file_to_str(file);
    char **dblstr = NULL;

    dblstr = mx_strsplit(str, '\n');
    mx_strdel(&str);
    return dblstr;
}

