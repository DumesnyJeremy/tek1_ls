/*
** EPITECH PROJECT, 2019
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <time.h>

typedef struct flag_s
{
    int l_list;
    int recurs;
    int dired;
    int rev_ord;
    int modi_te;
} flag_t;

typedef struct node_s
{
    char *data;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct head_s
{
    int f_op;
    node_t *begin;
    node_t *end;
} head_t;

head_t *get_n_node(char *x, head_t *l_a);
char *my_strcpy(char const *src);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);

int info(const char *pathname);
void f_flags(flag_t *flg, int i, char **av);
void get_time(head_t *l_a, struct stat st, node_t *temp);
void get_size(head_t *l_a, struct stat st, node_t *temp);
void get_name(head_t *l_a, struct stat st, node_t *temp);
char f_right(head_t *l_a, struct stat st, node_t *temp);
char *right(head_t *l_a, struct stat st, node_t *temp);
void set_right(head_t *l_a, node_t *temp, struct stat st);
char *my_strcpy2(char *dest, char const *src);

void flag_r(head_t *l_a, int nbr_doc, DIR *dir, struct dirent *lecture);
void flag_r_arg(DIR *dir, struct dirent *lecture,int nbr_doc, head_t *l_a);
int n_arg_r(int compt, DIR *dir, struct dirent *lecture, int nbr_doc);
void flag_d(head_t *l_a, int nbr_doc);
void flag_l(head_t *l_a, int nbr_doc, DIR *dir, struct dirent *lecture);
void flag_rmaj(head_t *l_a, int nbr_doc, DIR *dir, struct dirent *lecture);

void nothing(DIR *dir, struct dirent *lecture);
void nothing_arg(DIR *dir, struct dirent *lecture,int nbr_doc, head_t *l_a);
void nothing_arg(DIR *dir, struct dirent *lecture,int nbr_doc, head_t *l_a);
void prt_nf(flag_t *flg, head_t *l_a, int nbr_doc, int nbr_flag);
int n_arg(int compt, DIR *dir, struct dirent *lecture, int nbr_doc);
int n_arg_rmaj(int compt, DIR *dir, struct dirent *lecture, int space);

typedef void (*p_fonct)();

char *my_revstr(char *str);
void my_printf(char const *str, ...);
int my_strncmp(char const *s1, char const *s2, int n);
void my_put_nbr_l(long nb);
void my_put_nbr(int);
void my_put_nbr_o(int);
void my_put_nbr_x(int);
void my_put_nbr_xmaj(int);
void my_put_nbr_b(int nb);
void my_put_nbr_u(unsigned int nb);
void my_put_nbr_lx(long nb);
void my_put_nbr_lxmaj(long nb);
void my_put_nbr_p(long long int nb);
void my_put_p(long long int nb);

#endif