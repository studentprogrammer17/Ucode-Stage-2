#include "pathfinder.h"

void mx_check_lines_a(char **array) {
    char **arr = array;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '-'; j++) {
            if (mx_isalpha(arr[i][j]) == false) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        }
        if (mx_isalpha(arr[i][0]) == false) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }
    }
}

