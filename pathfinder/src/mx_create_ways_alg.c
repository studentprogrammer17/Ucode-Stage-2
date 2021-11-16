#include "pathfinder.h"

t_ways  *mx_node_creation(char **str, t_isls **list) {
    t_ways *node = (t_ways*)malloc(sizeof(t_ways));
    t_isls *pl = *list;

    if (node == NULL)
        return NULL;
    while (pl != NULL) {
        if (mx_strcmp(str[0], pl->name) == 0)
            node->top1 = pl->index;
        if (mx_strcmp(str[1], pl->name) == 0)
            node->top2 = pl->index;
        pl = pl->next;
    }
    int res = 0;
    for (int i = 0; i < mx_strlen(str[2]); i++) {
        res = res * 10 + (str[2][i] - 48);
    }
    node->distance = res;
    node->next = NULL;
    return node;
}

void mx_push_back_ways(t_ways **list, t_isls ** list2, char **str) {
    t_ways *node = mx_node_creation(str, list2);
    t_ways *pl = *list;

    if (pl == NULL) {
        *list = node;
        return;
    }
    while (pl->next != NULL) {
        pl = pl->next;
    }
    pl->next = node;
}

t_ways *mx_create_ways_alg(char **strmatrix, t_isls **islands) {
    t_ways *ways = NULL;
    char **substr = NULL;

    for (int i = 1; strmatrix[i]; i++) {
        substr = mx_str_dbl_split(strmatrix[i], '-', ',');
        mx_push_back_ways(&ways, islands, substr);
        mx_del_strarr(&substr);
    }
    return ways;
}

