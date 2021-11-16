#include "pathfinder.h"

void mx_err_pack(char *file) {
    char *array = mx_file_to_str(file);
    char **array2 = mx_file_to_arr(file);

    mx_file_err(file);

    mx_err_endline(array);
    int count_of_islands = mx_line1_err(file);

    mx_samedst_err(file);
    mx_delim_err(file);
    mx_check_lines_a(array2);
    mx_check_lines_b(array2);
    mx_err_dst(array2);

    mx_inval_num_of_isls(count_of_islands, file);

    mx_dup_bridges_err(file);

    mx_max_int_err(file);
}

