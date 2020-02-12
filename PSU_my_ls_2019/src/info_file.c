/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/ls.h"

head_t *get_n_node(char *x, head_t *l_a)
{
    node_t *n_node = malloc(sizeof(node_t) + 1);
    if (n_node == 0)
        return NULL;
    n_node->data = x;
    n_node->prev = NULL;
    n_node->next = NULL;
    if (l_a == 0) {
        l_a = malloc(sizeof(head_t) + 1);
        if (l_a == 0)
            return NULL;
        l_a->begin = n_node;
        l_a->end = n_node;
        l_a->f_op = 0;
    }
    else {
        l_a->end->next = n_node;
        n_node->prev = l_a->end;
        l_a->end = n_node;
    }
    return l_a;
}

void check_arg_file(flag_t *flg, head_t *l_a, int nbr_doc, int nbr_flag)
{
    struct stat st;
    DIR *dir;
    node_t *temp = l_a->begin;
    if (temp == NULL)
        return;
    int compt = 0;
    while (temp != NULL) {
        dir = opendir(temp->data);
        if (dir == NULL) {
            if (stat(temp->data, &st) == -1)
                compt = 1;
        }
        temp = temp->next;
    }
}

int main(int ac, char **av)
{
    char *list = NULL;
    int nbr_doc = 0;
    int nbr_flag = 0;
    flag_t *flg = malloc(sizeof(flag_t));
    head_t *l_a = NULL;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            f_flags(flg, i, av);
            nbr_flag++;
        }
        if (av[i][0] != '-') {
            l_a = get_n_node(my_strcpy(av[i]), l_a);
            nbr_doc++;
        }
    }
    prt_nf(flg, l_a, nbr_doc, nbr_flag);
}