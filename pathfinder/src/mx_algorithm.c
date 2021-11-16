#include "pathfinder.h"

void mx_algorithm(t_pointers *point, int width) {
    for (int index = 0; index < width - 1; index++) {
        int size = 0;
        point->link->mat = mx_no_rep_mat(point->link->matrix, index, &size, width);
        mx_parse_matrix(point, index, &size, width);
        mx_del_uarr(&point->link->mat, 3);
    }
}

