#include "pathfinder.h"

bool for_cycle(char **myarr, int *count_one, int *count_two, int i) {
	for (int j = 0; myarr[i][j] != '\0'; j++) {
		if (myarr[i][j] == '-') {
			(*count_one)++;
			if ((*count_two) > 0) {
				mx_printerr("error: line ");
	            mx_printerr(mx_itoa(i + 1));
	            mx_printerr(" is not valid\n");
				exit(-1);
			}
		}
		if (myarr[i][j] == ',')
			(*count_two)++;
		}
	return true;

}

void mx_delim_err(char *file) {
    char *file1 = mx_file_to_str(file);	// convert file to str
    char **myarr = mx_strsplit(file1, '\n'); // split vevery line

    int count_one = 0;
	int count_two = 0;

	for(int i = 1; myarr[i] != NULL; i++) { // find if deim or , is excess
		count_one = 0;
		count_two = 0;
		if (!for_cycle(myarr, &count_one, &count_two, i)) {
			mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
			exit(-1);
		}
		if (count_one != 1 || count_two != 1) {
			mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
			exit(-1);
            continue;
		}
	}
}

