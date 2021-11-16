#include "pathfinder.h"

void mx_max_int_err(char *file) {
    // find MAX INT
    char buf;
    int check = 0;
    int file4 = open(file, O_RDONLY);
    int flag_comma = 0;
    char sum_of_bridjes[100];
    int c_f = 0;
    while (read(file4, &buf, 1)) {
        if(buf == ',') {
            flag_comma = 1;
            continue;
        }
        if(flag_comma == 1) {
            sum_of_bridjes[c_f] = buf;
            c_f++;
            if(buf == '\n') {
                int temp_check = 0;
                check += mx_atoi(sum_of_bridjes);
                temp_check += mx_atoi(sum_of_bridjes);
                if(temp_check >= 2147483647 || temp_check <= 0) {
                    mx_printerr("error: sum of bridges lengths is too big\n");
                    exit(0);
                }
                for(int i = 0; sum_of_bridjes[i] != '\0'; i++) sum_of_bridjes[i] = '\0';
                c_f = 0;
                flag_comma = 0;
                temp_check = 0;
                continue;
            }
        }
    }
    if(check >= 2147483647 || check <= 0) {
         mx_printerr("error: sum of bridges lengths is too big\n");
         exit(0);
    }
    close(file4);
}

