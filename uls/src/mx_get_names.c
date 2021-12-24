#include "uls.h"

char** mx_get_names(struct dirent *dir,DIR *d, bool a_flag) {
    char **names = NULL;
    names = (char**)malloc(256);
    int i = 0;
    while ((dir = readdir(d)) != NULL) {
        if(dir->d_name[0] == '.' && a_flag == false) continue;
        names[i] = malloc(mx_strlen(dir->d_name)+1);
        mx_strcpy(names[i],dir->d_name);
        i++;
    }
    
    closedir(d);

    return names;
}

