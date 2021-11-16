#include "pathfinder.h"

void mx_inval_num_of_isls(int count_of_islands, char *file) {
     // error: invalid num of isls
    char *file3 = mx_file_to_str(file);
    char **arr3 = mx_strsplit(file3, '\n');
    int amount_of_string = 0;

    for(int i = 1; arr3[i] != NULL; i++) {
        amount_of_string++;
    }

    char *fin_str[amount_of_string * 2][4];
    for (int i = 1; i < amount_of_string + 1; i++) {
        char **tmp_1 = mx_strsplit(arr3[i], '-');
        char **tmp_2 = mx_strsplit(tmp_1[1], ',');

        fin_str[i][0] = mx_strdup(tmp_1[0]);

        if (i != 0) {
            fin_str[i][1] = mx_strdup(tmp_2[0]);
            fin_str[i][2] = mx_strdup(tmp_2[1]);
            fin_str[i][3] = NULL;
        }
    }

    int buf_size = amount_of_string * 2;
    char *islands_buf[buf_size];

    for (int i = 0, iter = 1; i < amount_of_string; i++, iter++) {
        islands_buf[i] = fin_str[iter][0];
    }

    for (int i = amount_of_string, iter = 1; i < buf_size; i++, iter++) {
        islands_buf[i] = fin_str[iter][1];
    }


    for(int i = 0; i < buf_size; i++) { // delete duplicates strings
        for(int j = i + 1;j < buf_size;) {
            if(mx_strcmp(islands_buf[i],islands_buf[j])==0) {
                for(int k = j + 1; k < buf_size; k++) {
                    mx_strcpy(islands_buf[k - 1], islands_buf[k]);
                }
                buf_size--;
            }
            else{
                j++;
            }
        }
    }
    if(count_of_islands != buf_size) { // check if first str == num of isls
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }
}

