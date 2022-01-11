#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);

    if(fd == -1) {
        return NULL;
    }
    
    char buf;
    int size = 0; 

    while (read(fd, &buf, 1)) {
        size++;
    }

    if (close(fd) < 0) {
        return NULL;
    }

    if (size == 0) {
        return NULL;
    }

    fd = open(file, O_RDONLY);

    char *string = mx_strnew(size);

    read(fd, string, size);

    return string;
}

