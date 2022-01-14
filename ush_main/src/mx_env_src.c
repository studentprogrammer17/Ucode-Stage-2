#include "ush.h"

#include "ush.h"

static char **env_copy(char **environ) {
    char **tyu = NULL;
    int size = 0;

    while(environ[size])
        size++;
    tyu = (char **)malloc(sizeof(char *) * (size + 1));
    tyu[size] = NULL;
    for (int i = 0; environ[i]; i++) {
        tyu[i] = strdup(environ[i]);
    }
    return tyu;
}

static int check_args(char ***args, char **n,int flag_i,int flag_u,char *clear[1], char ***environ) {
    n = env_copy(*environ);
    
    if ((*args)++ && mx_get_char_index(**args, '-') == 0) {
        if (mx_get_char_index(**args, 'i') > 0) {
            flag_i = 1;
            *environ = clear;
            clear[0] = NULL;
            (*args)++;
        }
        else if (mx_get_char_index(**args, 'u') > 0) {
            flag_u = 1;
            (*args)++;
        }
        else if (mx_get_char_index(**args, 'P') > 0) {
            (*args)++;
            setenv("PATH", *(*args)++, 1);
        }
    }
    return 0;
}

void mx_env_src(char *envp[], char **args) {
    char **n = NULL;
    int flag_i = 0;
    int flag_u = 0;
    char *clear[1];

    envp = NULL;
    extern char **environ;

    if (check_args(&args, n, flag_i, flag_u, clear, &environ) > 0) {
        mx_del_strarr(&n);
        return;
    }
    if (flag_i != 1 && flag_u == 1) {
        unsetenv(*args);
        args++;
    }
    else for ( ; *args && mx_get_char_index(*args, '=') > -1; args++)
        putenv(*args);
    for (int i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);
}







// void mx_env_src(char *envp[], char **args) {
//     if(mx_strcmp(args[1],"-u") == 0) {
//         for(int i = 2; args[i]; i++) {
//             unsetenv(args[i]);
//         }
//     }
//     if(mx_strcmp(args[1],"-i") == 0) {
//          for(int i = 2; args[i]; i++) {
//             mx_printstr(args[i]);
//             if(args[i + 1]) mx_printchar('\n');
//         }
//         exit(0);
//     }
//     extern char **environ;
//     envp = NULL;

//     for (int i = 0; environ[i] != 0; i++) {
//         mx_printstr(environ[i]);
//         mx_printchar('\n');
//     }
// }

