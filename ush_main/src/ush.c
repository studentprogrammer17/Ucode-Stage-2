#include "ush.h"

void mx_toupper(char *name) {
    char *s = name;
    while (*s){
        *s = toupper((unsigned char) *s);
        s++;
    }

}

void squeeze (char s[], int c) {
    int i, j;
 
    for (i = j = 0; s[i] != '\0'; i++){
        if (s[i] != c){
            s[j++] = s[i];
        }
        s[j] = '\0';
    }

}

void squeeze_str (char s[], char s2[]) {
  int k, i, j;
 
  for (k = 0; s2[k] != '\0'; k++) { 
    for (i = j = 0; s[i] != '\0'; i++)
      if (s[i] != s2[k])
        s[j++] = s[i];
    s[j] = '\0';
  }
}

void written (char s[100]) {
    int i, c;
 
    i = 0;
    while ((c = getchar()) != '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}
 


int main(int argc, char* argv[], char *envp[]) {
    bool was_echo_pwd = false;
    bool was_unset = false;
    ENVP = envp;
    char user_input[BUFFER_LEN]; 
    extern char **environ;
    int return_value = 0;
    char *cwd = NULL;
    cwd = getcwd(cwd, sizeof(BUFFER_LEN));
    setenv("PWD", cwd, 1);
    mx_setenv_src(environ, cwd, "PWD");

    while(1) {
        char dir[PATH_MAX+1];

        if (getcwd(dir, PATH_MAX+1) == NULL) {
            exit(0);
        }
   
        if(!fgets(user_input, BUFFER_LEN, stdin)){
            break;  //break if the command length exceed the defined BUFFER_LEN
        }
        
        int length = strlen(user_input);

        if(length == 0){
            exit(1);
        }

        if (user_input[length - 1] == '\n'){
            user_input[length - 1] = '\0'; // replace last char by '\0' if it is new line char
        }
 
        char **commands_arr = mx_strsplit(user_input, ' ');
        if(commands_arr == NULL){
            exit(1);
        }
  
        for(int i = 0; commands_arr[i]; i++) {
            char *rntmp = commands_arr[i];
            if(strcmp(rntmp, "cd") == 0) {
                char **help = (char **)malloc(BUFFER_LEN);
                for (int e = i, h = 0; commands_arr[e] && (strcmp(commands_arr[e], "unset") != 0 || strcmp(commands_arr[e], "export") != 0 || strcmp(commands_arr[e], "pwd") != 0 || strcmp(commands_arr[e], "echo") != 0 || strcmp(commands_arr[e], "env") != 0 || strcmp(commands_arr[e], "fg") != 0 || strcmp(commands_arr[e], "which") != 0 || strcmp(commands_arr[e], "exit") != 0); e++, h++) {
                    if (strcmp(commands_arr[e], ";") == 0)  {
                        break;
                    }
                    help[h] = commands_arr[e];
                    i = e;
                    help[h + 1] = "\0";
                }
                mx_cd_src(help, environ);
                continue;
            }
            if(strcmp(rntmp, "pwd") == 0) {
                char **help = (char **)malloc(BUFFER_LEN);
                for (int e = i, h = 0; commands_arr[e] && (strcmp(commands_arr[e], "unset") != 0 || strcmp(commands_arr[e], "export") != 0 || strcmp(commands_arr[e], "pwd") != 0 || strcmp(commands_arr[e], "echo") != 0 || strcmp(commands_arr[e], "env") != 0 || strcmp(commands_arr[e], "fg") != 0 || strcmp(commands_arr[e], "which") != 0 || strcmp(commands_arr[e], "exit") != 0); e++, h++) {
                    if (strcmp(commands_arr[e], ";") == 0)  {
                        break;
                    }
                    help[h] = commands_arr[e];
                    i = e;
                    help[h + 1] = "\0";
                }
                was_echo_pwd = false;
                mx_pwd_src(help, was_echo_pwd);
                continue;
            }
            if(strcmp(rntmp, "echo") == 0) {
                char **help = (char **)malloc(BUFFER_LEN);
                int count = 0;
                for (int e = i, h = 0; commands_arr[e] && (strcmp(commands_arr[e], "unset") != 0 || strcmp(commands_arr[e], "export") != 0 || strcmp(commands_arr[e], "cd") != 0  || strcmp(commands_arr[e], "pwd") != 0 || strcmp(commands_arr[e], "env") != 0 || strcmp(commands_arr[e], "fg") != 0 || strcmp(commands_arr[e], "which") != 0 || strcmp(commands_arr[e], "exit") != 0); e++, h++) {
                    if (strcmp(commands_arr[e], ";") == 0)  {
                        break;
                    }
                    help[h] = commands_arr[e];
                    i = e;
                    count++;

                    

                    help[h + 1] = "\0";
                    
                }
                mx_echo_src(count, help, environ);
                continue;
            }
           if(strcmp(rntmp, "env") == 0) {
                char **help = (char **)malloc(BUFFER_LEN);
                for (int e = i, h = 0; commands_arr[e] && (strcmp(commands_arr[e], "unset") != 0 || strcmp(commands_arr[e], "export") != 0 || strcmp(commands_arr[e], "cd") != 0 || strcmp(commands_arr[e], "pwd") != 0 || strcmp(commands_arr[e], "echo") != 0 || strcmp(commands_arr[e], "fg") != 0 || strcmp(commands_arr[e], "which") != 0 || strcmp(commands_arr[e], "exit") != 0); e++, h++) {
                    if (strcmp(commands_arr[e], ";") == 0)  {
                        break;
                    }
                    help[h] = commands_arr[e];
                    i = e;
                    help[h + 1] = "\0";
                }
                mx_env_src(ENVP, help);
                continue;
            }
            if(mx_strcmp(rntmp, "fg") == 0) {
                mx_fg_src(argc, argv);
                continue;
            }
            if(mx_strcmp(rntmp, "which") == 0) {
                char **help = (char **)malloc(BUFFER_LEN);
                for (int e = i + 1, h = 0; commands_arr[e] && (strcmp(commands_arr[e], "unset") != 0 || strcmp(commands_arr[e], "export") != 0 || strcmp(commands_arr[e], "cd") != 0  || strcmp(commands_arr[e], "pwd") != 0 || strcmp(commands_arr[e], "env") != 0 || strcmp(commands_arr[e], "fg") != 0 || strcmp(commands_arr[e], "echo") != 0 || strcmp(commands_arr[e], "exit") != 0); e++, h++) {
                    if (strcmp(commands_arr[e], ";") == 0)  {
                        break;
                    }
                    help[h] = commands_arr[e];
                    i = e;
                    help[h + 1] = "\0";
                }
                return_value = mx_which_src(help);
                continue;
            } 
            if(mx_strcmp(rntmp, "export") == 0) {
                char **help = (char **)malloc(BUFFER_LEN);
                for (int e = i, h = 0; commands_arr[e] && (strcmp(commands_arr[e], "unset") != 0 || strcmp(commands_arr[e], "cd") != 0 || strcmp(commands_arr[e], "pwd") != 0 || strcmp(commands_arr[e], "echo") != 0 || strcmp(commands_arr[e], "env") != 0 || strcmp(commands_arr[e], "fg") != 0 || strcmp(commands_arr[e], "which") != 0 || strcmp(commands_arr[e], "exit") != 0); e++, h++) {
                    if (strcmp(commands_arr[e], ";") == 0)  {
                        break;
                    }
                    help[h] = commands_arr[e];
                    i = e;
                    help[h + 1] = "\0";
                }
                mx_export_src(help,ENVP);
                continue;
            }
            if(mx_strcmp(rntmp, "unset") == 0) {
                was_unset = true;
                char **help = (char **)malloc(BUFFER_LEN);
                for (int e = i, h = 0; commands_arr[e] && (strcmp(commands_arr[e], "export") != 0 || strcmp(commands_arr[e], "cd") != 0 || strcmp(commands_arr[e], "pwd") != 0 || strcmp(commands_arr[e], "echo") != 0 || strcmp(commands_arr[e], "env") != 0 || strcmp(commands_arr[e], "fg") != 0 || strcmp(commands_arr[e], "which") != 0 || strcmp(commands_arr[e], "exit") != 0); e++, h++) {
                    if (strcmp(commands_arr[e], ";") == 0)  {
                        break;
                    }
                    help[h] = commands_arr[e];
                    i = e;
                    help[h + 1] = "\0";
                }
                mx_unset_src(help,ENVP);
                continue;
            }
            if(mx_strcmp(rntmp,"exit") == 0) {
                break;
                return 0;
            }
            if (mx_strcmp(rntmp, ";") == 0)
            {
                continue;
            }
        }

    
        
    }
    exit(return_value);
}


