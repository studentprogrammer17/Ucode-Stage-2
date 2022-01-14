#include "ush.h"

void mx_setenv_src(char *envp[], char *dir, char *command){
    for (int k = 1; envp[k]; k++)
    {   
        char *zhopa = *mx_strsplit(envp[k], '=');

        if (mx_strcmp(zhopa, command) == 0){
            for(int i = 0; envp[k][i]; i++) {
                if(envp[k][i] == '=') {
                    i++;
                    envp[k][i] = *dir;                    
                }

            }
        }
    }
}

