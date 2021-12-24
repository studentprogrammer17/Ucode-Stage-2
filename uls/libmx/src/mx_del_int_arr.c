#include "../inc/libmx.h"

void mx_del_intarr(int ***arr, int size) {
    int **parr = (*arr);

    for (int i = 0; i < size; i++)
        free(parr[i]);
    free(*arr);
    *arr = NULL;
}

