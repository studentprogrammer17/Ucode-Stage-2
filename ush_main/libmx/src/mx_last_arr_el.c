#include "libmx.h"

int mx_arrlen(unsigned int *arr) {
    int size = 1;

    while (arr[size] != 4294967295)
        size++;
    return size;
}

int mx_last_arr_el(unsigned int *arr) {
    int width = mx_arrlen(arr);
    int last_index = 0;

    while(arr[last_index] != 2147483647 && last_index < width)
        last_index++;
    return --last_index;
}

