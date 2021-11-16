#include "pathfinder.h"

t_consts *mx_create_consts() {
    t_consts *node = (t_consts *)malloc(sizeof(t_consts));
    if (node) {
        node->index = 0;
        node->pivot = 0;
        node->width = 0;
        node->count = 0;
        node->y = node->x = 0;
        node->i = 0;
        node->j = 0;
        node->k = 0;
        node->island_index = 0;
        node->new_island_index = 0;
        node->island_destination = 0;
        node->new_matrix_index = 0;
        node->matrix = NULL;
        node->mat = NULL;
        node->i_w_a = NULL;
    }
    return node;
}

