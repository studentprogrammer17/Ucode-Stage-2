#include "uls.h"

int main(int argc, char *argv[]) {
    // если просто вводим ./uls - нам выводит все файлы и папки в текующей директории
    bool a_flag = false;
    if(argc == 1) {
        mx_sort_names(argv);
        ls_output(a_flag,argc);
    }
    else {
        for(int i = 0; i < argc; i++) {
            // Если у нас флаг -a, то...
            if(argv[i][0] == '-' && argv[i][1] == 'a') {
                mx_sort_names(argv);
                a_flag = true;
                if(argc == 2) ls_output(a_flag,argc);
                else output_files_and_dirs("-a",a_flag,argc,argv);
                exit(0);
            }
            // Если у нас флаг -l, то....
            if(argv[i][0] == '-' && argv[i][1] == 'l') {
                bool check_argc = false;
                if(argc == 2) check_argc = true;
                l_flag(check_argc,argc,argv);

                exit(0);
            }
            // Проверка на неизвестный флаг
            if((argv[i][0] == '-') && (argv[1][i] != 'a' || argv[1][i] != 'l')) {
                mx_printerr("uls: illegal option -- ");
                mx_printerr(&argv[1][i]);
                mx_printerr("\nusage: uls [-lRa] [file ... ]\n");
                exit(1);
            }
        }
        // Если флагов нет, а просто мы ввели в качестве аргументов - директории или файлы то...
        a_flag = false;
        mx_sort_names(argv);
        output_files_and_dirs("prostoperedaiucudakakoitotrashhuh4815162342",a_flag,argc,argv);

        
    }


    // else {
    //     // если у нас 1 арг - флаг
    //     if(argv[1][0] == '-') {
    //         // если флаг - l
    //         if(argv[1][1] == 'l') {
    //             mx_printstr("-l flag");
    //         }
    //         // если флаг - R
    //         else if(argv[1][1] == 'R') { // для начала просто выводим все наши файлы и директории
    //             int count_of_files= 0;
    //             DIR *d;
    //             struct dirent *dir;
    //             d = opendir(".");
    //             if (d) {
    //                 while ((dir = readdir(d)) != NULL) {
    //                     if(dir->d_name[0] == '.') continue;
    //                     mx_printstr(dir->d_name);
    //                     mx_printchar(' ');
    //                     count_of_files++;
    //                 }
    //                 mx_printchar('\n');
    //                 //closedir(d);
    //             }
    //             // после выводим какие файлы хранятся в каждой директории
    //             for(int i = 0; i < count_of_files; i++) {
    //                 mx_printstr(&dir->d_name[i]);
    //             }

    //         }
    //         // если у нас флаг не l or R, то ошибка
    //         else {
    //             mx_printerr("uls: illegal option -- z\n");
    //             mx_printerr("usage: uls [-lR] [file ... ]\n");
    //             exit(1);
    //         }
    //     }


    //     // ./uls | cat -e
    //     // else if(argv[-1][0] == 'e') {
    //     //     mx_printstr("CAT -E\n");
    //     //     DIR *d;
    //     //     struct dirent *dir;
    //     //     d = opendir(".");
    //     //     if (d) {
    //     //         while ((dir = readdir(d)) != NULL) {
    //     //             if(dir->d_name[0] == '.') continue;
    //     //             mx_printstr(dir->d_name);
    //     //             mx_printchar('\n');
    //     //         }
    //     //         closedir(d);
    //     //     }
    //     // }

    //     //если 1 арг - файл или папка
    //     else {
    //         bool flag_was_error = false;
    //         bool flag_file_was_output = false;
    //         bool flag_was_empty_dir = false;
    //         bool flag_was_file = false;
    //         bool not_exist_file_output = false;
    //         for(int i = 1; i < argc; i++) {
    //             if(not_exist_file_output == false) {
    //                 for(int j = 1; j < argc; j++) {
    //                     int file = open(argv[j],O_RDONLY);
    //                     if(file == -1) { // проврка существует ли файл/директоиря
    //                         errno = ENOENT;
    //                         mx_printerr("uls: ");
    //                         mx_printerr(argv[j]);
    //                         mx_printerr(": No such file or directory\n");
    //                         close(file);
    //                         flag_was_error = true; // это делаем чтобы при echo $? - выводилось 1
    //                         not_exist_file_output = true;
    //                         if(argc == 2) exit(1);
    //                     }
    //                 }
    //             }
    //             // если файл или папка существует то....
    //             if(flag_file_was_output == false) {
    //                 for(int j = 1; j < argc; j++) {
    //                     int file = open(argv[j],O_RDONLY);
    //                     if(mx_isFile(argv[j]) && file != -1) { // Проверяем файл ли у нас, если да, то выводим
    //                         flag_was_file = true;
    //                         mx_printstr(argv[j]);
    //                         mx_printstr(" ");
    //                         close(file);
    //                         flag_file_was_output = true;
    //                     }
    //                     else {
    //                         continue;
    //                         close(file);
    //                     }
    //                     close(file);
    //                 }
    //                 mx_printchar('\n');
    //                 //mx_printchar('\n');
    //             }

    //             if(argc >= 3) { // если у нас болье 2-ух аргументов, тоесть файлов, то у нас будет выводитсья в формате   inc: 1.txt 2.txt src: 1.txt 2.txt
    //                 DIR *d;
    //                 struct dirent *dir;
    //                 d = opendir(argv[i]);
    //                 if (d) {
    //                     bool fmn = true;
    //                     if(flag_file_was_output &&  fmn == true) mx_printchar('\n');
    //                     fmn = false;
    //                     // Если у нас директория пуста, то выводит от это
    //                     if(mx_isDirEmpty(argv[i]) == 1) {
    //                         mx_printstr(argv[i]);
    //                         mx_printstr(":  # empty directory\n");
    //                         if(i != argc - 1) mx_printchar('\n');
    //                         flag_was_empty_dir = true;
    //                         continue;
    //                     }
    //                     mx_printstr(argv[i]);
    //                     mx_printstr(":\n");
    //                     while ((dir = readdir(d)) != NULL) {
    //                         if(dir->d_name[0] == '.') continue;
    //                         mx_printstr(dir->d_name);
    //                         mx_printchar(' ');
    //                     }
    //                     mx_printchar('\n');
    //                     if(i != argc) mx_printchar('\n');
    //                     closedir(d);

    //                 }
    //             }
    //             else { // если у нас 1 файл в аргументах то просто выводим его содержимое
    //                 DIR *d;
    //                 struct dirent *dir;
    //                 d = opendir(argv[i]);
    //                 if (d) {
    //                     while ((dir = readdir(d)) != NULL) {
    //                         if(mx_isDirEmpty(argv[i]) == 1) {
    //                             mx_printstr(argv[i]);
    //                             mx_printstr(":  # empty directory\n");
    //                             flag_was_empty_dir = true;
    //                             break;
    //                         }
    //                         if(dir->d_name[0] == '.') continue;
    //                         mx_printstr(dir->d_name);
    //                         mx_printchar(' ');
    //                     }
    //                     mx_printchar('\n');
    //                     closedir(d);
    //                 }
    //             }
    //     }
    //     if(flag_was_error) exit(1);
    //     }
    // }
}

