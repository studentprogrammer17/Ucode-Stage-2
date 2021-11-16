#include "pathfinder.h"

void mx_err_endline(char *array) {
    int delim = 1;

    for (int i = 0; array[i]; i++) {
        if (array[i] == '\n') {
            delim++;
            if (array[i] == array[i + 1]) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        }
    }
    if (array[0] == '\n') {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(1));
        mx_printerr(" is not valid\n");
        exit(-1);
    }
}

