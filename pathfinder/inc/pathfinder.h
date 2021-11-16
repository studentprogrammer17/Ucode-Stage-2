#pragma once

#ifndef PATHFINDER_H

#define PATHFINDER_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

//just funcs
bool mx_isdigit(int c);
bool mx_isalpha(int c);
int mx_strlen(char *s);
int mx_atoi(const char *str);
bool mx_isnumber(char *s);
char *mx_strnew(const int size);
char *mx_file_to_str(const char *filename);
char **mx_strsplit(char *s, char c);
void mx_strdel(char **str);
char *mx_itoa(int number);
void mx_del_strarr(char ***arr);
int mx_strcmp(const char *s1, const char *s2);
void mx_printint(int n);
void mx_str_reverse(char *s);

char **mx_file_to_arr(const char *file);
int mx_last_arr_el(unsigned int *arr);
void mx_del_intarr(int ***arr, int size);
void mx_del_u(unsigned int **arr);
void mx_del_uarr(unsigned int ***arr, int size);
void mx_del_uararr(unsigned int ****arr, int size);
int mx_count_dbl_words(const char *str, char first, char second);
char **mx_str_dbl_split(const char *s, char c, char b);
int mx_get_int_index(unsigned int **arr, int island);
int mx_arr_cmp(unsigned int *arr, unsigned int *arr2, int last_i, int last_j);

char *mx_strdup( char *s1);
char *mx_strndup( char *s1, size_t n);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strcpy(char *dst, const char *src);
int mx_strncmp( const char * s1, const char * s2, size_t n );
void mx_printstr(const char *s);


typedef struct  s_isls {
    int index;
    char *name;
    struct s_isls *next;
} t_isls;



typedef struct  s_ways {
    int top1;
    int top2;
    int distance;
    struct s_ways *next;
} t_ways;



typedef struct  s_minways {
    unsigned int **minwaymat;
    struct s_minways *next;
} t_minways;



typedef struct  s_parsing {
    unsigned int *final_arr;
    struct s_parsing *next;
} t_parsing;

typedef struct  s_consts {
    int index;
    int pivot;
    int width;
    int count;
    int y;
    int x;
    int i;
    int j;
    int k;
    int island_index;
    int new_island_index;
    int island_destination;
    int new_matrix_index;
    int **matrix;
    unsigned int **mat;
    unsigned int *i_w_a;
} t_consts;

typedef struct  s_pointers {
    char **strmatrix;
    t_consts *link;
    t_parsing *list;
} t_pointers;

t_consts  *mx_create_consts();
t_parsing *mx_parse_list(t_pointers *pnt, int is_index, int *size, const int width);
t_pointers  *mx_create_pnode();
t_isls *mx_create_top_alg(char **strmatrix);
t_ways *mx_create_ways_alg(char **strmatrix, t_isls **islands);

void mx_algorithm(t_pointers *point, int width);
void mx_parse_matrix(t_pointers *pnt, int island_index, int *size, const int width);
int **mx_fill_matrix(const int width, char **strmatrix, t_isls **islands);
unsigned int ***mx_all_short_path_mat(int **matrix, int island_index, int *size, const int width);
unsigned int **mx_no_rep_mat(int **matrix, int island_index, int *size, const int width);
void mx_all_short_path(int **matrix, unsigned int **minwaymat, t_consts *n, t_minways **list);


void mx_printerr(char *s);

void mx_file_err(char *file);
void mx_err_endline(char *array);
int mx_line1_err(char *file);
void mx_delim_err(char *file);
void mx_samedst_err(char *file);
void mx_inval_num_of_isls(int count_of_islands, char *file);
void mx_dup_bridges_err(char *file);
void mx_max_int_err(char *file);
void mx_err_pack(char *file);
void mx_check_lines_a(char **array);
void mx_check_lines_b(char **array);
void mx_err_dst(char **array);


#endif

