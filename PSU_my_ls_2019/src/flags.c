/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/ls.h"

void nothing(DIR *dir, struct dirent *lecture)
{
    dir = opendir(".");
        while ((lecture = readdir(dir))) {
                if (lecture->d_name[0] != '.')
                    my_printf("%s\n", lecture->d_name);
        }
        closedir(dir);
}

int n_arg(int compt, DIR *dir, struct dirent *lecture, int nbr_doc)
{
    while ((lecture = readdir(dir)))
        if (lecture->d_name[0] != '.')
            my_printf("%s\n", lecture->d_name);
        closedir(dir);
        if (compt != nbr_doc) {
            my_printf("\n");
            compt++;
        }
    return compt;
}

void nothing_arg(DIR *dir, struct dirent *lecture, int nbr_doc, head_t *l_a)
{
    int compt = 1;
    node_t *temp = l_a->begin;
    while (temp != NULL) {
        dir = opendir(temp->data);
        if (dir == NULL) {
            my_printf("==%s\n", temp->data);
            if (compt != nbr_doc) {
                my_printf("\n");
                compt++;
            }
        }
        if (dir != NULL) {
            if (nbr_doc != 1)
                my_printf("%s:\n", temp->data);
            compt = n_arg(compt, dir, lecture, nbr_doc);
        }
        temp = temp->next;
    }
}

void prt_nf(flag_t *flg, head_t *l_a, int nbr_doc, int nbr_flag)
{
    DIR *dir;
    struct dirent *lecture;
    if (nbr_doc == 0 && nbr_flag == 0 && flg->dired != 1 && flg->l_list != 1
    && flg->recurs != 1 && flg->rev_ord != 1 && flg->modi_te != 1)
        nothing(dir, lecture);
    if (nbr_doc != 0 && nbr_flag == 0 && flg->dired != 1 && flg->l_list != 1
    && flg->recurs != 1 && flg->rev_ord != 1 && flg->modi_te != 1)
        nothing_arg(dir, lecture, nbr_doc, l_a);
    if (flg->dired == 1 && flg->l_list != 1
    && flg->recurs != 1 && flg->rev_ord != 1 && flg->modi_te != 1)
        flag_d(l_a, nbr_doc);
    if (flg->dired != 1 && flg->l_list != 1
    && flg->recurs != 1 && flg->rev_ord == 1 && flg->modi_te != 1)
        flag_r(l_a, nbr_doc, dir, lecture);
    if (flg->dired != 1 && flg->l_list != 1
    && flg->recurs == 1 && flg->rev_ord != 1 && flg->modi_te != 1)
        flag_rmaj(l_a, nbr_doc, dir, lecture);
    if (flg->dired != 1 && flg->l_list == 1
    && flg->recurs != 1 && flg->rev_ord != 1 && flg->modi_te != 1)
        flag_l(l_a, nbr_doc, dir, lecture);
}