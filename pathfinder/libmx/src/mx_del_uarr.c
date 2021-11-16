#include "../inc/libmx.h"

void mx_del_uarr(unsigned int ***arr, int size) {
    unsigned int **parr = (*arr);

    for (int i = 0; i < size; i++)
        free(parr[i]);
    free(*arr);
    *arr = NULL;
}

