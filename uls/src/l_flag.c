#include "uls.h"

// void mx_sort_names_l(DIR *d,char *arg,bool a_flag){
//     int count = 0;
//     char *temp;
//     mx_get_names(dir,d,a_flag);

//     DIR *d;
//     struct dirent *dir = NULL;
//     d = opendir(argv[i]);
//     char **names = mx_get_names(dir,d,a_flag);
// }

void l_flag(bool check_argc, int argc, char *argv[]) {
    bool flag_file = false;
    DIR *dp = NULL;

    DIR *dp2 = NULL;
    struct dirent *entry2 = NULL;

    if(check_argc == true) {
        char **names = NULL;
        dp = opendir(".");
        l_flag_src(dp,".",flag_file,names);
        exit(0);
    }
    else {
        for(int i = 1; i < argc; i++) {

            int file = open(argv[i],O_RDONLY);
            char *file_str = argv[i];
            if(file == -1 && mx_strcmp(file_str,"-l") != 0) { // проврка существует ли файл/директоиря
                //errno = ENOENT;
                if(errno == EACCES) {
                    mx_printerr("uls: ");
                    mx_printerr(argv[i]);
                    mx_printerr(": Permission denied\n");
                    close(file);
                }
                else {
                    mx_printerr("uls: ");
                    mx_printerr(argv[i]);
                    mx_printerr(": No such file or directory\n");
                    close(file);
                }
                //flag_was_error = true; // это делаем чтобы при echo $? - выводилось 1
                if(argc == 3) exit(1);
                else continue;
            }



            if(argv[i][0] == '-' && argv[i][1] == 'l') {
                continue;
            }
            else {
                dp = opendir(argv[i]);
                if(argc == 3) {
                    if(mx_isFile(argv[i])) {
                        char **names = NULL;
                        flag_file = true;
                        l_flag_src(dp,argv[i],flag_file,names);
                    }
                    else {
                        dp2 = opendir(argv[i]);
                        char **names = mx_get_names(entry2,dp2, false);
			            mx_fort_files_first(names);

                        l_flag_src(dp,argv[i],flag_file,names);
                        closedir(dp2);
                        free(names);
                    }
                    exit(0);
                }
                else {
                    if(mx_isFile(argv[i])) {
                        char **names = NULL;
                        flag_file = true;
                        l_flag_src(dp,argv[i],flag_file,names);
                    }
                    else {
                        dp2 = opendir(argv[i]);
                        char **names = mx_get_names(entry2,dp2, false);
			            mx_fort_files_first(names);

                        flag_file = false;
                        mx_printstr(argv[i]);
                        mx_printstr(":\n");
                        l_flag_src(dp,argv[i],flag_file,names);
                        if(i != argc - 1) mx_printchar('\n');
                    }
                }
            }
        }
    }
}

