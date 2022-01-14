#include "../inc/libmx.h"

void mx_del_u(unsigned int **arr) {

    free(*arr);
    *arr = NULL;
}

