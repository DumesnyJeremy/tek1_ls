/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/ls.h"

int n_arg_rmaj(int compt, DIR *dir, struct dirent *lecture, int space)
{
    while ((lecture = readdir(dir)))
        if (lecture->d_name[0] != '.')
            my_printf("%s\n", lecture->d_name);
        closedir(dir);
        compt++;
        if (space != compt) {
            my_printf("\n");
        }
    return compt;
}

void rmaj(head_t *l_b, int space, DIR *dir, struct dirent *lecture)
{
    node_t *temp = l_b->begin;
        int compt = 0;
        while (temp != NULL) {
            dir = opendir(temp->data);
            if (dir == NULL)
                compt++;
        if (dir != NULL) {
            my_printf("./%s:\n", temp->data);
            compt = n_arg_rmaj(compt, dir, lecture, space);
        }
        temp = temp->next;
        }
}

void flag_rmaj(head_t *l_a, int nbr_doc, DIR *dir, struct dirent *lecture)
{
    int space = 0;
    head_t *l_b = NULL;
    if (nbr_doc == 0) {
        dir = opendir(".");
        while ((lecture = readdir(dir))) {
                if (lecture->d_name[0] != '.') {
                    l_b = get_n_node(my_strcpy(lecture->d_name), l_b);
                    space++;
                }
        }
        closedir(dir);
        node_t *temp = l_b->begin;
        my_printf(".:\n");
        while (temp != NULL) {
            my_printf("%s\n", temp->data);
            temp = temp->next;
        }
        my_printf("\n");
        rmaj(l_b, space, dir, lecture);
    }
}