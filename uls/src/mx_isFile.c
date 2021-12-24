#include "uls.h"

int mx_isFile(const char* name)
{
    DIR* directory = opendir(name);

    if(directory != NULL){
        closedir(directory);
        return 0;
    }

    if(errno == ENOTDIR) return 1;
       
    return -1;
}

