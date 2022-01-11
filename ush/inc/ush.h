#pragma once

#ifndef USH_H
#define USH_H

#include <crt_externs.h>
#include "../inc/libmx.h"
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <assert.h>
#include <curses.h>
#include <fcntl.h>
#include <limits.h>
#include <malloc/malloc.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <termios.h>
#include <term.h>
#include <sys/mman.h>

#include <ctype.h>

#define BUFFER_LEN 1024

char **ENVP;

int num_of_errors;

// realisation of fg:
void mx_fg_src(int argc, char** argv);
void mx_echo_src(int argc, char *argv[], char *envp[]);
void mx_cd_src(char *argv[], char *envp[]);
void mx_setenv_src(char *envp[], char *dir, char *command);
void mx_pwd_src(char **args, bool was_echo_pwd);
void mx_export_src(char **help,char *envp[]);
void mx_env_src();
void mx_unset_src(char **args,char *envp[]);
bool mx_which_src(char **help);
void smesh(int m, int size, char *road);

#endif

