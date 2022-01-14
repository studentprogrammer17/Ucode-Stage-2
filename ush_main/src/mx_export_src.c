#include "ush.h"

void mx_export_src(char **args,char *envp[]) {
    // setenv("UNIT","location",1);
    // setenv("UFK","p2p",1);
    // setenv("UCODE","cbl",1);
    if(args[2] == NULL) {
        mx_env_src(envp,args);
        return;
    }
    for(int i = 1; args[i]; i++) {
        putenv(args[i]);
    }
}

