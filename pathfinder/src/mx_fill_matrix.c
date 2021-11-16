#include "pathfinder.h"

int **mx_fill_matrix(const int width, char **strmatrix, t_isls **islands) {
    t_ways *ways = mx_create_ways_alg(strmatrix, islands);
    int **matrix = NULL;

    matrix = (int **)malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++) {
        matrix[i] = (int *)malloc(sizeof(int ) * width);
        for (int j = 0; j < width; j++) {
            matrix[i][j] = 2147483647;
        }
    }

    t_ways *p = NULL;

    for (p = ways; p != NULL; p = p->next) {
        if ((matrix)[p->top1][p->top2] > p->distance) {
            (matrix)[p->top1][p->top2] = p->distance;
        }


        if ((matrix)[p->top2][p->top1] > p->distance) {
            (matrix)[p->top2][p->top1] = p->distance;
        }

    }

    while (ways != NULL) {
        t_ways **head = &ways;
        if (*head != NULL) {
            t_ways *pl = (*head)->next;
            free(*head);
            *head = pl;
        }

    }
    return matrix;
}

