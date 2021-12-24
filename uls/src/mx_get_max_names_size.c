#include "uls.h"

int mx_get_max_names_size(struct dirent *dir,DIR *d, bool a_flag) {
    char **names = mx_get_names(dir,d, a_flag);
    int max_size_name = 0;

    for (int i = 0; names[i] != NULL; i++) {
        int ch = mx_strlen(names[i]);
        if (ch > max_size_name) {
            max_size_name = ch;
        }
    }
    if(max_size_name % 8 == 0) 
        max_size_name += 8;
    else 
        max_size_name = 8 - (max_size_name % 8) + max_size_name;
    
    //free(names);
    return max_size_name;
}

