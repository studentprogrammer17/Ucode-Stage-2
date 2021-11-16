#include "pathfinder.h"

t_isls  *mx_create_topnode(char *str, int i) {
    t_isls *node = (t_isls*)malloc(sizeof(t_isls));

    if (node == NULL)
        return NULL;
    node->name = mx_strdup(str);
    node->index = i;
    node->next = NULL;

    return node;
}

static bool notrepeat(char *str, t_isls **list) {
    t_isls *p = *list;

    while (p) {
        if (mx_strcmp(str, p->name) == 0)
            return false;
    p = p->next;
    }
    return true;
}

void mx_push_back_tops(t_isls **list, char *str, int i) {
    t_isls *node = mx_create_topnode(str, i);
    t_isls *pl = *list;

    if (pl == NULL) {
        *list = node;
        return;
    }
    while (pl->next != NULL) {
        pl = pl->next;
    }
    pl->next = node;
}

t_isls *mx_create_top_alg(char **strmatrix) {
    t_isls *islands = NULL;
    char **substr = NULL;
    int count = 0;
    for (int i = 1; strmatrix[i]; i++) {
        substr = mx_str_dbl_split(strmatrix[i], '-', ',');
        for (int j = 0; j < 2; j++) {
            if (notrepeat(substr[j], &islands)) {
                mx_push_back_tops(&islands, substr[j], count);
                count++;
            }
        }
        mx_del_strarr(&substr);
    }
    return islands;
}

