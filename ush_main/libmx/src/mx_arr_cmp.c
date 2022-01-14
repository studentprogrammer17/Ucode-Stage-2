#include "../inc/libmx.h"

int mx_arr_cmp(unsigned int *arr, unsigned int *arr2, int last_i, int last_j) {
    int i = last_i - 1;
    int j = last_j - 1;

    while (arr[i] == arr2[j]) {
        i--;
        j--;
    }
    return arr[i] - arr2[j];
}

