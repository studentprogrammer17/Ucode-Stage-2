#include "pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    else {
        char *file = argv[1];

        mx_err_pack(file);

        t_consts *consts = mx_create_consts();
        t_pointers *point= mx_create_pnode();

        point->strmatrix = mx_file_to_arr(file);

        int width = 0;

        for (int i = 0; i < mx_strlen(point->strmatrix[0]); i++) {
            width = width * 10 + (point->strmatrix[0][i] - 48);
        }

        t_isls *islands = mx_create_top_alg(point->strmatrix);
        point->link = consts;
        point->link->matrix = mx_fill_matrix(width, point->strmatrix, &islands);
        mx_algorithm(point, width);
    }
}

