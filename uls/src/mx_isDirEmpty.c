#include "uls.h"

int mx_isDirEmpty(char *dirname) {
    int n = 0;
    struct dirent *d;
    DIR *dir = opendir(dirname);
    while ((d = readdir(dir)) != NULL) {
        if(++n > 2)
        break;
    }
    closedir(dir);
    
    if (n <= 2) //Directory Empty
        return 1;
    else
        return 0;
}

