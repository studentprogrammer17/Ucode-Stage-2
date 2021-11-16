#include "pathfinder.h"

void mx_dup_bridges_err(char *file) {
    // duplicate bridges
    char *file5 = mx_file_to_str(file);
    char **arr5 = mx_strsplit(file5, '\n');
    int size_str = -1;

    for(int i = 1; arr5[i] != NULL; i++) {
        size_str++;
    }
    char *duplicate[size_str * 2][1];
    for(int i = 1; arr5[i] != NULL; i++) {
        char **tmp = mx_strsplit(arr5[i], ',');
        duplicate[i][0] = mx_strdup(tmp[0]);
    }

    for(int i = 1; i < size_str + 2; i++) {
        char* rev_bridj = duplicate[i][0];
        mx_str_reverse(rev_bridj);
        for(int j = 1; j < size_str + 2; j++) {
            if((mx_strcmp(duplicate[i][0],duplicate[j][0]) == 0 || mx_strcmp(rev_bridj, duplicate[j][0]) == 0) && i != j) {
                mx_printerr("error: duplicate bridges\n");
                exit(-1);
            }
        }
    }
}

