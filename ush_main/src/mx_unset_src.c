#include "ush.h"

void mx_unset_src(char **args,char *envp[]) {
    envp = NULL;
    if(args[2] == NULL) {
        mx_printerr("unset: not enough arguments\n");
        exit(1);
    }
    
    for(int i = 1; args[i]; i++) {
        unsetenv(args[i]);
    }
}

