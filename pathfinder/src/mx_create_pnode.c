#include "pathfinder.h"

t_pointers  *mx_create_pnode() {
    t_pointers *point = (t_pointers*)malloc(sizeof(t_pointers));

    point->strmatrix = NULL;
    point->link = NULL;
    point->list = NULL;
    return point;
}

