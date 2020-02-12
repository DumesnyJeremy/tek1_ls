/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/ls.h"

void f_flags(flag_t *flg, int i, char **av)
{
    for (int a = 1; av[i][a]; a++) {
        if (av[i][a] == 'l')
            flg->l_list = 1;
        if (av[i][a] == 'R')
            flg->recurs = 1;
        if (av[i][a] == 'd')
            flg->dired = 1;
        if (av[i][a] == 'r')
            flg->rev_ord = 1;
        if (av[i][a] == 't')
            flg->modi_te = 1;
        if (av[i][a] != 'l' && av[i][a] != 'R' && av[i][a] != 'd'
        && av[i][a] != 'r' && av[i][a] != 't') {
            my_printf("ls: invalid option\n");
            exit (84);
        }
    }
}