#include "../inc/libmx.h"

void mx_del_uararr(unsigned int ****arr, int size) {
    unsigned int ***parr = &(**arr);

    for (int i = 0; i < size; i++) {
        mx_del_uarr(&parr[i], 3);

    }
    free(*arr);
    *arr = NULL;
}

