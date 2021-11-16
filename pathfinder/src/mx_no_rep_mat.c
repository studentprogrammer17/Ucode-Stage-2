#include "pathfinder.h"

unsigned int **no_rep_mat_creat(int *size, const int width) {
    unsigned int **norepmat = NULL;

    norepmat = (unsigned int **)malloc(sizeof(unsigned int *) * (3));
    for (int i = 0; i < 3; i++) {
        norepmat[i] = (unsigned int *)malloc(sizeof(unsigned int) * ((*size) * width) + 1);
        norepmat[i][(*size) * width] = 4294967295;
        for (int j = 0; j < ((*size) * width); j++)
            norepmat[i][j] = 2147483647;
    }
    return norepmat;
}

void no_rep_cond(unsigned int **norepmat, unsigned int ***allmatrix, t_consts *n, int *k) {
    int count = 0;

    for (int i = (n->y); i > 0; i--) {
        if (allmatrix[n->y][1][n->x] == allmatrix[i - 1][1][n->x])
            count++;
    }
    if (count == 0) {
        for (int j = 0; j < 3; j++)
            norepmat[j][(*k)] = allmatrix[n->y][j][n->x];
        (*k)++;
    }
}

static unsigned int **no_rep_mat_fill(int **matrix, int island_index, int *size, const int width) {
    unsigned int ***allmatrix = mx_all_short_path_mat(matrix, island_index, size, width);
    unsigned int **norepmat = no_rep_mat_creat(size, width);
    t_consts *n = mx_create_consts();

    for (; n->x < width; n->x++) {
        for (n->y = 0; n->y < (*size); n->y++) {
            if (n->y == 0) {
                for (n->i = 0; n->i < 3; n->i++)
                    norepmat[n->i][n->k] = allmatrix[n->y][n->i][n->x];
                n->k++;
            }
            else if (n->y > 0)
                no_rep_cond(norepmat, allmatrix, n, &n->k);
        }
    }
    free(n);
    n = NULL;
    mx_del_uararr(&allmatrix, (*size));
    return norepmat;
}

unsigned int **mx_no_rep_mat(int **matrix, int island_index, int *size, const int width) {
    unsigned int **norepmat = no_rep_mat_fill(matrix, island_index, size, width);
    int buf;

    for (int j = 0; j < (*size) * width; j++){
        if (norepmat[0][j] == 2147483647)
            break;
        else if (norepmat[2][j] == norepmat[2][j+1] && norepmat[1][j] > norepmat[1][j + 1]) {
                buf = norepmat[1][j];
                norepmat[1][j] = norepmat[1][j + 1];
                norepmat[1][j + 1] = buf;
        }
    }
    return norepmat;
}

