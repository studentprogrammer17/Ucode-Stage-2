#include "ush.h"

bool mx_which_src(char **help) {
    int return_value = 1;
\

    for (int i = 0; help[i] != NULL; i++) {
        if(mx_strcmp(help[i], "-a") == 0) {
            i++;
            if (strcmp(help[i], "echo") == 0) {
                mx_printstr("echo: ush built-in command\n");
                mx_printstr("/bin/echo\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "echo;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "echo;echo") == 0) {
                mx_printstr("echo: ush built-in command\n");
                mx_printstr("/bin/echo\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }



            if (strcmp(help[i], "fg") == 0) {
                mx_printstr("fg: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "fg;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "fg;echo") == 0) {
                mx_printstr("fg: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if(strcmp(help[i], "which") == 0) {
                mx_printstr("which: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "which;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "which;echo") == 0) {
                mx_printstr("which: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "cd") == 0) {
                mx_printstr("cd: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "cd;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "cd;echo") == 0) {
                mx_printstr("cd: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "pwd") == 0) {
                mx_printstr("pwd: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "pwd;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "pwd;echo") == 0) {
                mx_printstr("pwd: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "exit") == 0) {
                mx_printstr("exit: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "exit;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "exit;echo") == 0) {
                mx_printstr("exit: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }

            else {
                if((help[i][strlen(help[i]) - 1] == ';') || strcmp(help[i + 1], "$?") == 0) {
                    mx_printerr(*mx_strsplit(help[i], ';'));
                    mx_printerr(" not found\n");
                    mx_printint(1);
                    mx_printchar('\n');
                    break;
                }
                mx_printerr(help[i]);
                mx_printerr(" not found\n");
                return_value = 1;
                break;
            }
        }
        else if(mx_strcmp(help[i], "-s") == 0) {
            i++;
            if (strcmp(help[i], "echo") == 0) {
                mx_printstr("echo: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "echo;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "echo;echo") == 0) {
                mx_printstr("echo: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }



            if (strcmp(help[i], "fg") == 0) {
                mx_printstr("fg: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "fg;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "fg;echo") == 0) {
                mx_printstr("fg: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if(strcmp(help[i], "which") == 0) {
                mx_printstr("which: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "which;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "which;echo") == 0) {
                mx_printstr("which: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "cd") == 0) {
                mx_printstr("cd: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "cd;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "cd;echo") == 0) {
                mx_printstr("cd: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "pwd") == 0) {
                mx_printstr("pwd: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "pwd;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "pwd;echo") == 0) {
                mx_printstr("pwd: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "exit") == 0) {
                mx_printstr("exit: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "exit;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "exit;echo") == 0) {
                mx_printstr("exit: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }

            else {
                if((help[i][strlen(help[i]) - 1] == ';') || strcmp(help[i + 1], "$?") == 0) {
                    mx_printerr(*mx_strsplit(help[i], ';'));
                    mx_printerr(" not found\n");
                    mx_printint(1);
                    mx_printchar('\n');
                    break;
                }
                mx_printerr(help[i]);
                mx_printerr(" not found\n");
                return_value = 1;
                break;
            }
        }

        else {
            if (strcmp(help[i], "echo") == 0) {
                mx_printstr("echo: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "echo;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "echo;echo") == 0) {
                mx_printstr("echo: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }



            if (strcmp(help[i], "fg") == 0) {
                mx_printstr("fg: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "fg;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "fg;echo") == 0) {
                mx_printstr("fg: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if(strcmp(help[i], "which") == 0) {
                mx_printstr("which: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "which;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "which;echo") == 0) {
                mx_printstr("which: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "cd") == 0) {
                mx_printstr("cd: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "cd;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "cd;echo") == 0) {
                mx_printstr("cd: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "pwd") == 0) {
                mx_printstr("pwd: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "pwd;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "pwd;echo") == 0) {
                mx_printstr("pwd: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }


            if (strcmp(help[i], "exit") == 0) {
                mx_printstr("exit: ush built-in command\n");
                return_value = 0;
                break;
            }
            if((strcmp(help[i], "exit;") == 0 && strcmp(help[i + 2], "$?") == 0) || strcmp(help[i], "exit;echo") == 0) {
                mx_printstr("exit: ush built-in command\n");
                mx_printint(0);
                mx_printchar('\n');
                break;
            }

            else {
                if((help[i][strlen(help[i]) - 1] == ';') || strcmp(help[i + 1], "$?") == 0) {
                    mx_printerr(*mx_strsplit(help[i], ';'));
                    mx_printerr(" not found\n");
                    mx_printint(1);
                    mx_printchar('\n');
                    break;
                }
                mx_printerr(help[i]);
                mx_printerr(" not found\n");
                return_value = 1;
                break;
            }
        }

    }
        return return_value;
}

