#include "pathfinder.h"

bool reflect_alpha(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
			return false;
	}
	return true;
}

bool reflect_buff(char **bufarr2, char **bufarr, char **myarr, int i) {
    myarr = NULL;
    if (mx_strcmp(bufarr[0], bufarr2[0]) == 0) {
        mx_del_strarr(&bufarr);
        mx_del_strarr(&bufarr2);
	    mx_printerr("error: line ");
        mx_printerr(mx_itoa(i + 1));
        mx_printerr(" is not valid\n");
        exit(-1);
    }
return true;
}

void mx_samedst_err(char *file) {
    char *file2 = mx_file_to_str(file);
    char **arr2 = mx_strsplit(file2, '\n');

    char **buf_same_isl = NULL;
    char **buf_same_isl_2 = NULL;

    for (int i = 1; arr2[i] != NULL; i++) { // check same dest in one str
        buf_same_isl = mx_strsplit(arr2[i], '-');
            if (buf_same_isl[1] == NULL || reflect_alpha(buf_same_isl[0]) == 0) {
                mx_del_strarr(&buf_same_isl);
            	mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
            buf_same_isl_2 = mx_strsplit(buf_same_isl[1], ',');
            if (!reflect_buff(buf_same_isl_2, buf_same_isl, arr2, i)) {
            	mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
            mx_del_strarr(&buf_same_isl);
            mx_del_strarr(&buf_same_isl_2);
    }
}

