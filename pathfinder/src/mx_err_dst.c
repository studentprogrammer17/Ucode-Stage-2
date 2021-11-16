#include "pathfinder.h"

void mx_err_dst(char **array) {
    char **arr = array;
    bool flag = false;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            if (arr[i][j] == ',') {
                flag = true;
                j++;
            }
            if ((flag == true) && (mx_isdigit(arr[i][j]) == false)) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
            flag = false;
        }
    }
}

