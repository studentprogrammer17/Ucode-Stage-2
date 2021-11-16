#include "pathfinder.h"

void mx_file_err(char *file) {
    int file1 = open(file,O_RDONLY); // open file

    if(file1 < 0) { // check is file exist
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        exit(-1);
    }

    char buf;
    int file_size = 0;

    while (read(file1 , &buf, 1)) { // get file size
        file_size++;
    }

    close(file1);
    if (file_size == 0) { // if size == 0 means in file is empty
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        exit(-1);
    }
}

