#pragma once

#ifndef ULS_H

#define ULS_H

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


// ./uls
void ls_output(bool a_flag, int argc);

// ./uls dir1 dir2 file1  e.t.c.
void output_files_and_dirs(char *a,bool a_flag, int argc, char* argv[]);

// ./uls -l
void l_flag(bool check_argc,int argc, char *argv[]);

// -l flag source code
void l_flag_src(DIR *dp,char *arg, bool flag_file,char **names);

// total block count ( when we run flag -l, returns total)
int mx_get_total(char* directory);

// название функции говорит за себя 
int mx_get_max_names_size(struct dirent *dir,DIR *d,bool a_flag);
 
// get names from dir
char** mx_get_names(struct dirent *dir,DIR *d, bool a_flag);

void mx_sort_files(char **names);
int mx_isFile(const char* name);
int mx_isDirEmpty(char *dirname);
void mx_sort_names(char **names);

// sort dirs by alph
char** mx_sort_dirs_by_alph(char *arr[],int argc);

void mx_sort_size(char *argv[]);

void mx_fort_files_first(char **names);

#endif

