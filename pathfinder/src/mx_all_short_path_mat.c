#include "pathfinder.h"

void mx_pop_front_mat(t_minways **head) {
    t_minways *pl = NULL;

    if (*head != NULL) {
        pl = (*head)->next;
        mx_del_uarr(&((*head)->minwaymat), 2);
        free((*head)->minwaymat);
        (*head)->minwaymat = NULL;
        free(*head);
        *head = pl;
    }
}

unsigned int ***matrix_creat_all(t_minways **list, int island_index, int *size, const int wid) {
    t_minways *p_list = *list;
    unsigned int ***allmat = NULL;

    while (p_list) {
        if (p_list->minwaymat[0][island_index] == 0 && (int)p_list->minwaymat[1][island_index] == island_index)
            (*size)++;
        p_list = p_list -> next;
    }
    allmat = (unsigned int ***)malloc(sizeof(unsigned int **) * (*size));
    for (int i = 0; i < (*size); i++) {
        allmat[i] = (unsigned int **)malloc(sizeof(unsigned int *) * 3);
        for (int j = 0; j < 3; j++) {
            allmat[i][j] = (unsigned int *)malloc(sizeof(unsigned int) * wid);
            for (int k = 0; k < wid; k++)
                allmat[i][j][k] = k;
        }
    }
    return allmat;
}

unsigned int **mx_get_top_ways(int **matrix, int index, const int width) {
    unsigned int **waymatrix = NULL;

    waymatrix = (unsigned int **)malloc(sizeof(unsigned int *) * 3);
    for (int i = 0; i < 3; i++) {
        waymatrix[i] = (unsigned int *)malloc(sizeof(unsigned int) * width);
        for (int j = 0; j < width; j++) {
            if (i == 0)
                waymatrix[i][j] = matrix[index][j];
            if (i == 1 && matrix[index][j] != 2147483647)
                waymatrix[i][j] = index;
            if (i == 2)
                waymatrix[i][j] = 2147483647;
        }
    }
    return waymatrix;
}

t_minways *mx_all_short_path_creat(int **matrix, const int width) {
    t_consts *n = mx_create_consts();
    unsigned int **waymatrix = NULL;
    t_minways *list = NULL;

    n->width = width;
     for (; n->index < width - 1; n->index++) {
        waymatrix = mx_get_top_ways(matrix, n->index, width);
        mx_all_short_path(matrix, waymatrix, n, &list);
        mx_del_uarr(&waymatrix, 3);
    }
    free(n);
    n = NULL;
    return list;
}

unsigned int ***mx_all_short_path_mat(int **matrix, int island_index, int *size, const int width) {
    t_minways *list = mx_all_short_path_creat(matrix, width);
    unsigned int ***allmatrix = matrix_creat_all(&list, island_index, size, width);
    int i = 0;

    while(list) {
        if (list->minwaymat[0][island_index] == 0 && (int)list->minwaymat[1][island_index] == island_index) {
            for (int k = 0; k < width; k++) {
                allmatrix[i][0][k] = list->minwaymat[0][k];
                allmatrix[i][1][k] = list->minwaymat[1][k];
            }
            i++;
        }
        mx_pop_front_mat(&list);
    }
    return allmatrix;
}

