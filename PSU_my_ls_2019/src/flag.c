/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/ls.h"

int n_arg_r(int compt, DIR *dir, struct dirent *lecture, int nbr_doc)
{
    head_t *l_b = NULL;
    while ((lecture = readdir(dir)))
        if (lecture->d_name[0] != '.')
            l_b = get_n_node(my_strcpy(lecture->d_name), l_b);
        closedir(dir);
        node_t *temp = l_b->end;
        while (temp != NULL) {
            my_printf("%s\n", temp->data);
            temp = temp->prev;
        }
        if (compt != nbr_doc) {
            my_printf("\n");
            compt++;
        }
    return compt;
}

void flag_r_arg(DIR *dir, struct dirent *lecture, int nbr_doc, head_t *l_a)
{
    int compt = 1;
    node_t *temp = l_a->end;
    while (temp != NULL) {
        dir = opendir(temp->data);
        if (dir == NULL) {
            my_printf("%s\n", temp->data);
            if (compt != nbr_doc) {
                my_printf("\n");
                compt++;
            }
        }
        if (dir != NULL) {
            if (nbr_doc != 1)
                my_printf("%s:\n", temp->data);
            compt = n_arg_r(compt, dir, lecture, nbr_doc);
        }
        temp = temp->prev;
    }
}

void flag_r(head_t *l_a, int nbr_doc, DIR *dir, struct dirent *lecture)
{
    head_t *l_b = NULL;
    if (nbr_doc == 0) {
        dir = opendir(".");
        while ((lecture = readdir(dir))) {
                if (lecture->d_name[0] != '.')
                    l_b = get_n_node(my_strcpy(lecture->d_name), l_b);
        }
        closedir(dir);
        node_t *temp = l_b->end;
        while (temp != NULL) {
            my_printf("%s\n", temp->data);
            temp = temp->prev;
        }
    }
    if (nbr_doc != 0) {
        flag_r_arg(dir, lecture, nbr_doc, l_a);
    }
}

void flag_d(head_t *l_a, int nbr_doc)
{
    if (nbr_doc == 0)
        my_printf("%c\n", '.');
    if (nbr_doc > 0) {
        node_t *temp = l_a->begin;
        while (temp != NULL) {
            my_printf("%s\n", temp->data);
            temp = temp->next;
        }
    }
}