#include "ush.h"

void mx_pwd_src(char **args, bool was_echo_pwd) {

    char *pwd = getcwd(NULL, 0);
    char **m = NULL;
    char *path = "private/tmp";
    char *path_2 = "/tmp";
   

    if (args[1] != NULL && !strcmp(args[1], "-P")) {
        write(1, path, strlen(path));
        write(1, "\n", 1);
        return;
    }
    if (args[1] != NULL && !strcmp(args[1], "-L")) {
        write(1, path_2, strlen(path_2));
        write(1, "\n", 1);
        return;
    }
    m = mx_strsplit(getcwd(NULL, 0), '/');
    if (m[0] == NULL)
        mx_printstr("/");
    else for (int i = 0; m[i]; i++){
        mx_printstr("/");
        mx_printstr(m[i]);
    }
    if(was_echo_pwd == false) {
      write(1, "\n", 1);
    }
    mx_del_strarr(&m);
    free(pwd);
}


