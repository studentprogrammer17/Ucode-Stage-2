#include "pathfinder.h"

bool mx_stop_way(unsigned int **minwaymat, const int width) {
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < width; j++) {
            if (minwaymat[2][j] != 1)
                count++;
        }
    }
    if(count == 0) return true;
    else return false;
}

unsigned int **cop_mar(unsigned int **matrix, const int width) {
    unsigned int **newm = NULL;

    newm = (unsigned int **)malloc(sizeof(unsigned int *) * 3);
    for (int i = 0; i < 3; i++) {
        newm[i] = (unsigned int *)malloc(sizeof(unsigned int) * width);
        for (int j = 0; j < width; j++) {
            newm[i][j] = matrix[i][j];
        }
    }
    return newm;
}

void mx_min_cyc_way(int **matrx, unsigned int **minwaymat, t_consts *n) {

    for (int i = 0; i < n->width; i++) {
        if (minwaymat[2][i] != 1 && matrx[(n->pivot)][i] != 2147483647 && (matrx[(n->pivot)][i] + minwaymat[0][(n->pivot)] < minwaymat[0][i])) {
            minwaymat[0][i] = matrx[(n->pivot)][i] + minwaymat[0][(n->pivot)];
            minwaymat[1][i] = (n->pivot);
        }
    }
}

void mx_par_cyc_way(int **matrix, unsigned int **minwaymat, t_consts *n, t_minways **list) {
    unsigned int **copy = NULL;

    for (int i = 0; i < n->width; i++) {
        if (minwaymat[2][i] != 1 && matrix[(n->pivot)][i] != 2147483647 && (matrix[(n->pivot)][i] + minwaymat[0][(n->pivot)] == minwaymat[0][i]) && (int)minwaymat[1][i] != n->pivot) {
            copy = cop_mar(minwaymat, n->width);
            copy[1][i] = (n->pivot);
            mx_all_short_path(matrix, copy, n, list);
            mx_del_uarr(&copy, 3);
        }
    }
}

void mx_min_ways(unsigned int **minwaymat, int index, int *pivot, const int width) {
    unsigned int min_value = 2147483647;

    for (int i = 0; i < width; i++) {
        if (i == index && minwaymat[2][i] != 1) {
            minwaymat[0][i] = 0;
            minwaymat[1][i] = i;
            minwaymat[2][i] = 1;
        }
        if (minwaymat[2][i] != 1 && minwaymat[0][i] < min_value) {
            min_value = minwaymat[0][i];
            (*pivot) = i;
        }
    }
}

t_minways  *mx_min_node_way_creat(unsigned int **minwaymat, const int width) {
    t_minways *node = (t_minways*)malloc(sizeof(t_minways));

    if (node == NULL)
        return NULL;
    node->minwaymat = (unsigned int **)malloc(sizeof(unsigned int *) * 2);
    for (int i = 0; i < 2; i++) {
        node->minwaymat[i] = (unsigned int *)malloc(sizeof(unsigned int) * width);
        for (int j = 0; j < width; j++)
            node->minwaymat[i][j] = minwaymat[i][j];
    }
    node->next = NULL;
    return node;
}

void mx_minway_psuhback(t_minways **list, unsigned int **minwaym, const int width) {
    t_minways *node = mx_min_node_way_creat(minwaym, width);
    t_minways *pl = *list;

    if (pl == NULL) {
        *list = node;
        return;
    }
    while (pl->next != NULL) {
        pl = pl->next;
    }
    pl->next = node;
}

void mx_all_short_path(int **matrix, unsigned int **minwaymat, t_consts *n, t_minways **list) {

    while (!(mx_stop_way(minwaymat, n->width))) {
        mx_min_cyc_way(matrix, minwaymat, n);
        mx_par_cyc_way(matrix, minwaymat, n, list);
        mx_min_ways(minwaymat, n->index, &n->pivot, n->width);
        minwaymat[2][(n->pivot)] = 1;
    }
    mx_minway_psuhback(list, minwaymat, n->width);
}

