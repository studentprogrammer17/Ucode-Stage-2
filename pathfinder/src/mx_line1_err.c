#include "pathfinder.h"

int mx_line1_err(char *file) {
    int file1 = open(file,O_RDONLY); // again open file
    char buf;
    int first_str_size = 0;

    while (read(file1, &buf, 1)) { // get 1st string size
        if(buf == '\n') {
            break;
        }
        first_str_size++;
    }
    close(file1);
    file1 = open(file,O_RDONLY); // again open file

    while (read(file1, &buf, 1)) { // get 1st string
        if(buf == '\n') {
            break;
        }
    }

    close(file1);
    int file2 = open(file, O_RDONLY);

    char *first_str = mx_strnew(first_str_size); // malloc memory for 1str str
    read(file2,first_str,first_str_size); // read 1st str from file

    if(!mx_isnumber(first_str)) {
        mx_printerr("error: line 1 is not valid\n"); // if in 1str not a number
        exit(-1);
    }


    int count_of_islands = mx_atoi(first_str); // convert str to int

    return count_of_islands;
}

