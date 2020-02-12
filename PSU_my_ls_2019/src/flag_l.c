/*
** EPITECH PROJECT, 2019
** main
** File description:
** Dumesny.J
*/

#include "../include/ls.h"

char *my_strcat2(char *dest, char const *src)
{
    int a = 0;
    int b = 0;
    for (; dest[a] != '\0';)
        a++;
    while (src[b] != '\0') {
        dest[a + b] = src[b];
        b++;
    }
    dest[a + b] = '\0';
    return (dest);
}

char f_right(head_t *l_a, struct stat st, node_t *temp)
{
    switch (st.st_mode & __S_IFMT)
    {
    case __S_IFCHR:
        return 'c';
    case __S_IFSOCK:
        return 's';
    case __S_IFDIR:
        return 'd';
    case __S_IFREG:
        return '-';
    case __S_IFIFO:
        return 'p';
    case __S_IFLNK:
        return 'l';
    case __S_IFBLK:
        return 'b';
    default:
        break;
    }
}

char *right(head_t *l_a, struct stat st, node_t *temp)
{
    char *rght = malloc(sizeof(char*) * (13));
    rght[0] = f_right(l_a, st, temp);
    rght[1] = ((st.st_mode & S_IRUSR) ? 'r' : '-');
    rght[2] = ((st.st_mode & S_IWUSR) ? 'w' : '-');
    rght[3] = ((st.st_mode & S_IXUSR) ? 'x' : '-');
    rght[4] = ((st.st_mode & S_IRGRP) ? 'r' : '-');
    rght[5] = ((st.st_mode & S_IWGRP) ? 'w' : '-');
    rght[6] = ((st.st_mode & S_IXGRP) ? 'x' : '-');
    rght[7] = ((st.st_mode & S_IROTH) ? 'r' : '-');
    rght[8] = ((st.st_mode & S_IWOTH) ? 'w' : '-');
    rght[9] = ((st.st_mode & S_IXOTH) ? 'x' : '-');
    rght[10] = ('.');
    rght[11] = (' ');
    rght[12] = '\0';
    my_printf("%s", rght);
    my_printf("%d ", st.st_nlink);
    get_name(l_a, st, temp);
}

void set_right(head_t *l_a, node_t *temp, struct stat st)
{
    while (temp != NULL ) {
        char* tempo = malloc(sizeof(char) * 1000);
        my_strcpy2(tempo, l_a->begin->data);
        my_strcat2(tempo, temp->data);
        stat(tempo, &st);
        right(l_a, st, temp);
        my_printf(" %s\n", temp->data);
        temp = temp->next;
    }
}

void flag_l(head_t *l_a, int nbr_doc, DIR *dir, struct dirent *lecture)
{
    for (node_t *test = l_a->begin; test != NULL; test = test->next) {
        int total = 0;
        struct stat st;
        head_t *l_b = NULL;
        printf("%s:\n", test->data);
        dir = opendir(test->data);
        while ((lecture = readdir(dir))) {
            if (lecture->d_name[0] != '.')
                l_b = get_n_node(my_strcpy(lecture->d_name), l_b); }
        node_t *temp = l_b->begin;
        while (temp != NULL) {
            char* tempo = malloc(sizeof(char) * 1000);
            my_strcpy2(tempo, test->data);
            my_strcat2(tempo, temp->data);
            stat(tempo, &st);
            total += st.st_blocks;
            temp = temp->next;
        }
        total = total / 2;
        my_printf("total %d\n", total);
        temp = l_b->begin;
        set_right(l_a, temp, st);
        if (test->next != NULL)
            my_printf("\n");
    }
}