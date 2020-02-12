/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/ls.h"

void get_time(head_t *l_a, struct stat st, node_t *temp)
{
    int a = 4;
    int b = 0;
    int compt = 0;
    char *time = ctime(&st.st_mtime);
    char *r_time = malloc(sizeof(char *) * my_strlen(time));
    for(; a < 16; a++, b++) {
        r_time[b] = time[a];
        compt++;
    }
    r_time[b] = '\0';
    my_printf("%s", r_time);
}

void get_size(head_t *l_a, struct stat st, node_t *temp)
{
    my_printf(" ");
    my_printf("%d ", st.st_size);

    get_time(l_a, st, temp);
}

void get_name(head_t *l_a, struct stat st, node_t *temp)
{
    struct passwd *ps = getpwuid(st.st_uid);
    struct group *gr = getgrgid(st.st_gid);

    my_printf("%s", ps->pw_name);
    my_printf(" ");
    my_printf("%s", gr->gr_name);

    get_size(l_a, st, temp);
}