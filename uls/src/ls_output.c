#include "uls.h"

    // if ((((args->info.st_mode) & S_IFMT) == S_IFDIR))
    // {
    //     mx_printstr("\033[34m");
    // }
    // else if ((((args->info.st_mode) & S_IFMT) == S_IFLNK))
    // {
    //     mx_printstr("\033[35m");
    // }
    // else if (args->info.st_mode & S_IXOTH)
    // {
    //     mx_printstr(RED);
    // }
    // else
    // {
    //     return 0;
    // }
    // print_name(args); 
    // return 1;

void ls_output(bool a_flag, int argc) {
    //struct stat statbuf;
    struct winsize ws;
    DIR *d;
    d = opendir(".");
    if (d) {
        argc = 1;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        if(!isatty(1)) {
            DIR *d3;
            struct dirent *dir3 = NULL;
            d3 = opendir(".");
            char **names = mx_get_names(dir3,d3,a_flag);
            mx_sort_names(names);
            for(int i = 0; names[i] != NULL; i++) {
                mx_printstr(names[i]);
                mx_printchar('\n');
            }
            return;
        }


        DIR *d2;
        struct dirent *dir2 = NULL;
        d2 = opendir(".");
        int max_size_name =  mx_get_max_names_size(dir2,d2, a_flag);
        
        DIR *d;
        struct dirent *dir = NULL;
        d = opendir(".");
        char **names = mx_get_names(dir,d,a_flag);
        mx_fort_files_first(names);

        int num = 0;
        int rows;
        int term_cols;
        int cols;

        ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
        if(isatty(1)) term_cols = ws.ws_col;
        else term_cols = 80;
        
        if((term_cols / max_size_name) != 0) {
            cols = term_cols / max_size_name;
        }
        else {
            cols = 1;
        }
        if(!isatty(1)) cols = 1;

        while(names[num]) { 
            num++;
        }

        if (max_size_name * cols > term_cols && cols != 1) {
            cols--;
        }

        if (num * max_size_name > term_cols) {
            rows = num / cols;
            if (rows == 0 || num % cols != 0) {
                rows++;
            }
            
            for (int i = 0; i < rows; i++) {
                for (int j = 0; i + j < num; j += rows) {
                    mx_printstr(names[i + j]);
                    if (names[i + j + 1] && (i + j + rows < num)) {
                        int content = max_size_name - mx_strlen(names[i + j]);
                        int c;

                        if(content % 8 != 0) c = (content / 8) + 1;
                        else c = content / 8;
                            
                        for (int i = 0; i < c; i++) {
                            mx_printchar('\t');
                        }
                    }
                }
                if (i != rows - 1) {
                    mx_printchar('\n');
                }
            }
    } 

    else {
        for (int i = 0; names[i] != NULL; i++)  {
            mx_printstr(names[i]);
            if (names[i + 1])  {
                int content = max_size_name - mx_strlen(names[i]);
                int c;

                if(content % 8 != 0) c = (content / 8) + 1;
                else c = content / 8;

                for (int i = 0; i < c; i++) {
                    mx_printchar('\t');
                }
            }
        }
    }
    mx_printchar('\n');
    }
}

