#include "pathfinder.h"

t_parsing  *mx_farr_node(unsigned int *i_w_a, const int width) {
    t_parsing *node = (t_parsing*)malloc(sizeof(t_parsing));

    if (node == NULL)
        return NULL;
    node->final_arr = (unsigned int *)malloc(sizeof(unsigned int) * width + 1);
    node->final_arr[width] = 4294967295;
    for (int i = 0; i < width; i++) {
        node->final_arr[i] = i_w_a[i];
    }

    node->next = NULL;
    return node;
}

void mx_pushback_far(t_parsing **list, unsigned int *i_w_a, const int width) {
    t_parsing *node = mx_farr_node(i_w_a, width);
    t_parsing *pl = *list;

    if (pl == NULL) {
        *list = node;
        return;
    }

    while (pl->next != NULL) {
        pl = pl->next;
    }
    pl->next = node;
}

unsigned int *create_way_arr(const int width) {
    unsigned int *arr = NULL;

    arr = (unsigned int *)malloc(sizeof(unsigned int) * width + 1);
    arr[width] = 4294967295;
    for (int i = 0; i < width; i++) {
        arr[i] = 2147483647;
    }
    return arr;
}

void mx_allway(t_pointers *p, int island_index, int ild_dstn, int arr_index) {
    int new_destination= 0;

    p->link->i_w_a[arr_index] = p->link->mat[2][ild_dstn];
    arr_index++;
    if (p->link->mat[1][ild_dstn] == p->link->mat[2][island_index]) {
        p->link->i_w_a[arr_index] = p->link->mat[2][island_index];
        mx_pushback_far(&p->list, p->link->i_w_a, p->link->width);
    }
    else {
        new_destination = mx_get_int_index(p->link->mat, p->link->mat[1][ild_dstn]);
        while ((int)p->link->mat[2][new_destination] == (int)p->link->mat[1][ild_dstn]) {
            mx_allway(p, island_index, new_destination, arr_index);
            new_destination++;
        }
    }
}

t_parsing *mx_parse_list(t_pointers *pnt, int is_index, int *size, const int width) {
    int arr_index = 0;

    pnt->link->width = width;
    pnt->link->i_w_a = create_way_arr(width);
    pnt->link->i_w_a[width] = 4294967295;
    for (; (int)pnt->link->mat[2][pnt->link->island_index] != is_index; pnt->link->island_index++);
    pnt->link->k = pnt->link->island_index + 1;

    for (; ((pnt->link->k < width * (*size))
        && pnt->link->mat[0][pnt->link->k] != 2147483647); pnt->link->k++) {
        for (pnt->link->i = 0; pnt->link->i < width; pnt->link->i++)
            pnt->link->i_w_a[pnt->link->i] = 2147483647;
        mx_allway(pnt, pnt->link->island_index, pnt->link->k, arr_index);
    }
    mx_del_u(&pnt->link->i_w_a);
    return pnt->list;
}

