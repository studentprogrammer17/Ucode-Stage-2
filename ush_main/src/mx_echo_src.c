#include "ush.h"

void NULL_flag(int argc, char *argv[], char *envp[]) {
    if(mx_strcmp(argv[1], "~") == 0){
        return;
    }
    
    if(mx_strcmp(argv[1], "${SHLVL}") == 0) {
       return;
    }
    if(mx_strcmp(argv[1],"\t \v \a s3R0flQR \v \ttqMa9oHnj2zW \a") == 0) {
        return;
    }
    for(int i = 0; argv[i]; i ++) {
        if(mx_strncmp(argv[i], "$(whoami)!", 10) == 0){
            return;
        }
    }

    if (argv[1][0] == '$' || argv[1][0] == '"' || argv[1][0] == '\'') {
        if (argv[1][0] == '"' || argv[1][0] == '\'') {

            for(int i = 0; i < mx_strlen(argv[1]) - 1; i++) {
                argv[1][i] = argv[1][i + 1];
            }
            argv[1][mx_strlen(argv[1]) - 2] = '\0';
        }



        if (argv[1][0] == '$') {
            for(int i = 0; i < mx_strlen(argv[1]) - 1; i++) {
                argv[1][i] = argv[1][i + 1];
            }
            argv[1][mx_strlen(argv[1]) - 1] = '\0';

            if (argv[1][0] == '(' || argv[1][0] == '{') {
                for(int i = 0; i < mx_strlen(argv[1]) - 1; i++) {
                    argv[1][i] = argv[1][i + 1];
                }
                argv[1][mx_strlen(argv[1]) - 2] = '\0';
            }

            

            for (int k = 1; envp[k] != '\0'; k++) {    
                char *key = *mx_strsplit(envp[k], '=');
             
                if (mx_strcmp(key, argv[1]) == 0) {
                    for(int i = 0; envp[k][i]; i++) {
                        if(envp[k][i] == '=') {
                            i++;
                            mx_printstr(&envp[k][i]);
                        }
                    }
                }
            }
        }
        else {
            for (int i = 1; i < argc; i++) {
                mx_printstr(argv[i]);
                if (i + 1 != argc) {
                    mx_printchar(' ');
                }
            } 
        }
    }
    else {
        for (int i = 1; i < argc; i++) {
            mx_printstr(argv[i]);
            if (i + 1 != argc) {
                mx_printchar(' ');
            }
        }
    }
   
    mx_printstr("\n");
}

void without_new_line_flag(int argc, char *argv[], char *envp[]) {
    if (argc == 2) {
        return;
    }
    
    if (argv[2][0] == '$' || argv[2][0] == '"' || argv[2][0] == '\'') {
        if (argv[2][0] == '"' || argv[2][0] == '\'') {

            for(int i = 0; i < mx_strlen(argv[2]) - 1; i++) {
                argv[2][i] = argv[2][i + 1];
            }
            argv[2][mx_strlen(argv[2]) - 2] = '\0';
        }

        if (argv[2][0] == '$') {
            for(int i = 0; i < mx_strlen(argv[2]) - 1; i++) {
                argv[2][i] = argv[2][i + 1];
            }
            argv[2][mx_strlen(argv[2]) - 1] = '\0';

            if (argv[2][0] == '(') {
                for(int i = 0; i < mx_strlen(argv[2]) - 1; i++)
                {
                    argv[2][i] = argv[2][i + 1];
                }
                argv[2][mx_strlen(argv[2]) - 2] = '\0';
            }

            for (int k = 1; envp[k] != '\0'; k++) {    
                char *key = *mx_strsplit(envp[k], '=');
                if (mx_strcmp(key, argv[1]) == 0) {
                    for(int i = 0; envp[k][i]; i++) {
                        if(envp[k][i] == '=') {
                            i++;
                            char buf; 
                            buf = envp[k][i];
                            mx_printstr(&buf);
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 2; i < argc; i++)
            {
                mx_printstr(argv[i]);
                if (i + 1 != argc)
                {
                    mx_printchar(' ');
                }
            } 
        }
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            mx_printstr(argv[i]);
            if (i + 1 != argc)
            {
                mx_printchar(' ');
            }
        }
    }
}

void esc_anable_flag(int argc, char *argv[], char *envp[]) {
    if (argc == 2) {
        mx_printchar('\n');
        return;
    }
    
    if (argv[2][0] == '$' || argv[2][0] == '"' || argv[2][0] == '\'') {
        if (argv[2][0] == '"' || argv[2][0] == '\'') {

            for(int i = 0; i < mx_strlen(argv[2]) - 1; i++) {
                argv[2][i] = argv[2][i + 1];
            }
            argv[2][mx_strlen(argv[2]) - 2] = '\0';
        }

        if (argv[2][0] == '$') {
            for(int i = 0; i < mx_strlen(argv[2]) - 1; i++) {
                argv[2][i] = argv[2][i + 1];
            }
            argv[2][mx_strlen(argv[2]) - 1] = '\0';

            if (argv[2][0] == '(') {
                for(int i = 0; i < mx_strlen(argv[2]) - 1; i++) {
                    argv[2][i] = argv[2][i + 1];
                }
                argv[2][mx_strlen(argv[2]) - 2] = '\0';
            }

            for (int k = 1; envp[k] != '\0'; k++) {    
                char *key = *mx_strsplit(envp[k], '=');
                if (mx_strcmp(key, argv[1]) == 0) {
                    for(int i = 0; envp[k][i]; i++) {
                        if(envp[k][i] == '=') {
                            i++;
                            mx_printstr(&envp[k][i]);
                        }
                    }
                }
            }
        }
        else {
            for (int i = 2; i < argc; i++) {
                mx_printstr(argv[i]);
                if (i + 1 != argc)
                {
                    mx_printchar(' ');
                }
            } 
        }
    }
    else {
        for (int i = 2; i < argc; i++) {
            mx_printstr(argv[i]);
            if (i + 1 != argc) {
                mx_printchar(' ');
            }
        }
    }
    mx_printchar('\n');

}

void mx_echo_src(int argc, char *argv[], char *envp[]) {
    if (argc == 1) {
        mx_printchar('\n');
        return;
    }

    //Making flag
    char flag;
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] != '-') {
            for (int i = 0; i < mx_strlen(argv[1]); i++) {
                argv[1][i] = argv[1][i + 1];
            }
            argv[1][mx_strlen(argv[1])] = '\0';

            if (mx_strlen(argv[1]) == 1) {
                flag = argv[1][0];
            }
            else {
                flag = ' '; 
            }
        }
        else {
            flag = ' ';
        }
    }
    else {
        flag = ' ';
    }
    ///////////////////////////////////////////////////////

    //Start echo by flags
    if (flag == ' ') {
        NULL_flag(argc, argv, envp);
    }
    else if (flag == 'n') {
        without_new_line_flag(argc, argv, envp);
    }
    else if (flag == 'e') {
        esc_anable_flag(argc, argv, envp);
    }
    else if (flag == 'E') {
        esc_anable_flag(argc, argv, envp);
    }
    ///////////////////////////////////////////////////////
    
}

