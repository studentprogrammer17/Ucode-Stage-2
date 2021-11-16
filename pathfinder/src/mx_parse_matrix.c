#include "pathfinder.h"

char *mx_get_name_isl(char **strmatrix, char **island_name, int index) {
    t_isls *islands = mx_create_top_alg(strmatrix);

    mx_strdel(island_name);
    while (islands) {
        if (islands->index == index) {
            (*island_name) = mx_strdup(islands->name);
        }

        t_isls *pl = NULL;

        if (islands != NULL) {
            pl = (islands)->next;
            mx_strdel(&((islands)->name));
            free(islands);
            islands = pl;
        }
    }
    return (*island_name);
}

void path_route_output(char **strmatrix, unsigned int *i_way_arr) {
    char *name_isl = NULL;
    int last_arrel = mx_last_arr_el(i_way_arr);

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(mx_get_name_isl(strmatrix, &name_isl, i_way_arr[last_arrel]));
    mx_printstr(" -> ");
    mx_printstr(mx_get_name_isl(strmatrix, &name_isl, i_way_arr[0]));
    mx_printstr("\nRoute: ");
    mx_printstr(mx_get_name_isl(strmatrix, &name_isl, i_way_arr[last_arrel]));
    if (last_arrel > 1) {
        for (int i = last_arrel - 1; i >= 0; i--) {
            mx_printstr(" -> ");
            mx_printstr(mx_get_name_isl(strmatrix, &name_isl, i_way_arr[i]));
        }
    }
    else {
        mx_printstr(" -> ");
        mx_printstr(mx_get_name_isl(strmatrix, &name_isl, i_way_arr[0]));
    }
    mx_strdel(&name_isl);
}

void dst_output(unsigned int *i_w_a, unsigned int **mat) {
    int last_arrel = mx_last_arr_el(i_w_a);

    mx_printstr("\nDistance: ");
    for (int i = 0; mat[2][i] != 2147483647 && mat[2][i] != 4294967295; i++) {
        if(i_w_a[last_arrel - 1] == mat[2][i]) {
            mx_printint(mat[0][i]);
            break;
        }
    }
    if (last_arrel > 1) {
        int p = last_arrel - 2;
        for (; p >= 0; p--) {
            for (int j = 0; mat[2][j] != 2147483647 && mat[2][j] != 4294967295; j++) {
                if(i_w_a[p] == mat[2][j] && i_w_a[p + 1] == mat[1][j]) {
                    mx_printstr(" + ");
                    unsigned int **matrix = mat;
                    unsigned int first_island = mat[1][j];
                    unsigned int second_island = mat[2][j];
                    for (int i = 0; matrix[2][i] != 2147483647 && matrix[2][i] != 4294967295; i++) {
                        if(first_island == matrix[2][i]) {
                            first_island = matrix[0][i];
                            break;
                        }
                    }

                    for (int i = 0; matrix[2][i] != 2147483647 && matrix[2][i] != 4294967295; i++) {
                        if(second_island == matrix[2][i]) {
                            second_island = matrix[0][i];
                            break;
                        }
                    }
                    int length = second_island - first_island;
                    mx_printint(length);
                }
            }
        }
    }
}

void sum_bridj(char **strmatrix, unsigned int *i_way_arr, unsigned int **mat) {
    int last_arrel = mx_last_arr_el(i_way_arr);

    path_route_output(strmatrix, i_way_arr);
    dst_output(i_way_arr, mat);
    if (last_arrel > 1) {
            mx_printstr(" = ");
        for (int k = 0; mat[2][k] != 2147483647 && mat[2][k] != 4294967295; k++) {
            if(i_way_arr[0] == mat[2][k]) {
                mx_printint(mat[0][k]);
                break;
            }
        }
    }
    mx_printstr("\n========================================\n");
}

void mx_parse_matrix(t_pointers *pnt, int island_index, int *size, const int width) {

    pnt->link->width = width;
    pnt->list = mx_parse_list(pnt, island_index, size, width);

    t_parsing *pl = pnt->list;
    int last_arrel;
    int last_arrel_2;
    int count = 1;

    while (count != 0) {
        count = 0;
        for (; pl->next; pl = pl->next) {
            if (pl->final_arr[0] == pl->next->final_arr[0]) {
                last_arrel = mx_last_arr_el(pl->final_arr);
                last_arrel_2 = mx_last_arr_el(pl->next->final_arr);
                if (mx_arr_cmp(pl->final_arr, pl->next->final_arr, last_arrel, last_arrel_2) > 0) {
                    t_parsing *temp_pl = pl;
                    unsigned int *buf;
                    buf = temp_pl->final_arr;
                    temp_pl->final_arr = temp_pl->next->final_arr;
                    temp_pl->next->final_arr = buf;
                    count++;
                }
            }
        }
        pl = pnt->list;
    }

    while (pnt->list) {
        sum_bridj(pnt->strmatrix, pnt->list->final_arr, pnt->link->mat);
        t_parsing  *pl = NULL;
        if (pnt->list != NULL) {
            pl = (pnt->list)->next;
            mx_del_u(&(pnt->list)->final_arr);
            free(pnt->list);
            pnt->list = pl;
        }
    }
}

