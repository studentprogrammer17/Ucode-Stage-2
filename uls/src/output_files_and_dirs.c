#include "uls.h"

void output_files_and_dirs(char *a,bool a_flag, int argc, char* argv[]) {
    struct winsize ws;
    
    bool flag_was_error = false;
    bool flag_perm_denied_err = false;
    bool flag_file_was_output = false;
    bool flag_was_empty_dir = false;
    bool flag_was_file = false;
    bool not_exist_file_output = false;
    bool permission_denied = false;
    bool lmn = true;
    bool smn = true;
    bool file_nline = false;
    int bb = 1;
    for(int i = 1; i < argc; i++) {
        if(permission_denied == false) {
            for(int j = 1; j < argc; j++) {
                int file = open(argv[j],O_RDONLY);
                if(file == -1 && mx_strcmp(argv[j],a) != 0) { // проврка существует ли файл/директоиря
                    if(errno == 13) {
                        mx_printerr("uls: ");
                        mx_printerr(argv[j]);
                        mx_printerr(": Permission denied\n");
                        close(file);
                        flag_perm_denied_err = true; // это делаем чтобы при echo $? - выводилось 1
                        permission_denied = true;
                        if(argc == 2) exit(1);
                    }
                    else continue;
                }
            }
        }

        if(not_exist_file_output == false) {
            for(int j = 1; j < argc; j++) {
                int file = open(argv[j],O_RDONLY);
                if(file == -1 && mx_strcmp(argv[j],a) != 0) { // проврка существует ли файл/директоиря
                    errno = ENOENT;
                    mx_printerr("uls: ");
                    mx_printerr(argv[j]);
                    mx_printerr(": No such file or directory\n");
                    close(file);
                    flag_was_error = true; // это делаем чтобы при echo $? - выводилось 1
                    not_exist_file_output = true;
                    if(argc == 2) exit(1);
                }
            }
        }
        // если файл или папка существует то....
        if(flag_file_was_output == false) {
            for(int j = 1; j < argc; j++) {
                int file = open(argv[j],O_RDONLY);
                if(mx_isFile(argv[j]) && file != -1) { // Проверяем файл ли у нас, если да, то выводим
                    flag_was_file = true;
                    mx_printstr(argv[j]);
                    if(!isatty(1) && (j != argc - 1)) mx_printchar('\n');
                    else {
                        if(argc != 2 && (j != argc - 1)) {
                            mx_printchar('\t');
                        }
                    }
                    close(file);
                    if(argc == 2) {
                        mx_printchar('\n');
                        exit(0);
                    }
                    flag_file_was_output = true;
                    file_nline = true;
                }
                else {
                    file_nline = false;
                    continue;
                    close(file);
                }
                close(file);
            }
        }
        if(argc >= 3) { // если у нас болье 2-ух аргументов, тоесть файлов, то у нас будет выводитсья в формате   inc: 1.txt 2.txt src: 1.txt 2.txt
            DIR *d;
            d = opendir(argv[i]);
            if (d) {
                bool fmn = true;
                if(flag_file_was_output == true &&  fmn == true) mx_printchar('\n');

                // Если у нас директория пуста, то выводит от это
                if(mx_isDirEmpty(argv[i]) == 1) {
                    //if(flag_file_was_output == true && smn == true)
                    mx_printchar('\n');
                    smn = false;
                    mx_printstr(argv[i]);
                    mx_printstr(":\n");
                    //if(i != argc) mx_printchar('\n');
                    flag_was_empty_dir = true;
                    continue;
                }

                //   char *empty_dir = NULL;
                //     if(mx_isDirEmpty(argv[i]) == 1) {
                //     empty_dir = (char*)malloc(mx_strlen(argv[i]) + 1);
                //     mx_strcpy(empty_dir,argv[i]);
                //     }
                //     was_empty_dir = true;
                //     if(i == argc - 1) {
                //         mx_printstr(empty_dir);
                //         mx_printstr(":  # empty directory\n");
                //         //if(i != argc) mx_printchar('\n');
                //         flag_was_empty_dir = true;
                //         continue;
                //     }
                //     else continue;


                if(flag_file_was_output == true &&  lmn == true && flag_was_empty_dir == false) mx_printchar('\n');
                
                lmn = false;
                mx_printstr(argv[i]);
                mx_printstr(":\n");
                
                ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
                DIR *d2;
                struct dirent *dir2 = NULL;
                d2 = opendir(argv[i]);
                int max_size_name =  mx_get_max_names_size(dir2,d2, a_flag);
                
                DIR *d;
                struct dirent *dir = NULL;
                d = opendir(argv[i]);
                char **names = mx_get_names(dir,d,a_flag);
                mx_fort_files_first(names);

                struct winsize ws;
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
                ++bb;
                mx_printchar('\n');
                if(bb != argc) mx_printchar('\n');
                //closedir(d);
            }
        }
        else { // если у нас 1 файл в аргументах то просто выводим его содержимое
            if(permission_denied == false) {
            for(int j = 1; j < argc; j++) {
                int file = open(argv[j],O_RDONLY);
                if(file == -1 && mx_strcmp(argv[j],a) != 0) { // проврка существует ли файл/директоиря
                    if(errno == 13) {
                        mx_printerr("uls: ");
                        mx_printerr(argv[j]);
                        mx_printerr(": Permission denied\n");
                        close(file);
                        flag_perm_denied_err = true; // это делаем чтобы при echo $? - выводилось 1
                        permission_denied = true;
                        if(argc == 2) exit(1);
                    }
                    else continue;
                }
            }
        }
          if(mx_isDirEmpty(argv[i]) == 1 && argc == 2) {
              return;
          }
          if(mx_isDirEmpty(argv[i]) == 1) {
                mx_printstr(argv[i]);
                mx_printstr(":\n");
                //if(i != argc) mx_printchar('\n');
                flag_was_empty_dir = true;
                continue;
            }
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
            DIR *d2;
            struct dirent *dir2 = NULL;
            d2 = opendir(argv[i]);
            int max_size_name =  mx_get_max_names_size(dir2,d2,a_flag);
            
            DIR *d;
            struct dirent *dir = NULL;
            d = opendir(argv[i]);
            char **names = mx_get_names(dir,d, a_flag);
            mx_fort_files_first(names);
           
            struct winsize ws;
            int num = 0;
            int rows;
            int term_cols;
            int cols;

            ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
            if(isatty(1)) term_cols = ws.ws_col;
            else term_cols = 80;
            
            if((term_cols / max_size_name) != 0) 
                cols = term_cols / max_size_name;
            else cols = 1;
                

            if(!isatty(1)) cols = 1;

            while(names[num])  num++;
                
            if (max_size_name * cols > term_cols && cols != 1) cols--;
            
            if (num * max_size_name > term_cols) {
                rows = num / cols;
                if (rows == 0 || num % cols != 0) rows++;
                    
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; i + j < num; j += rows) {
                        mx_printstr(names[i + j]);

                        if (names[i + j + 1] && (i + j + rows < num)) {
                            int content = max_size_name - mx_strlen(names[i + j]);
                            int c;

                            if(content % 8 != 0) c = (content / 8) + 1;
                            else c = content / 8;

                            for (int i = 0; i < c; i++) 
                                mx_printchar('\t');
                            
                        }
                    }
                    if (i != rows - 1) 
                        mx_printchar('\n');
                    
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

                        for (int i = 0; i < c; i++) 
                            mx_printchar('\t');
                        
                    }
                }
            }
            //mx_printchar('\n');
        }
                
    }
    if(file_nline == true) mx_printchar('\n');
    if(flag_was_error) exit(1);
}

