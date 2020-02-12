/*
** EPITECH PROJECT, 2019
** Printf
** File description:
** Dictio
*/

#include <stdio.h>
#include <stdarg.h>
#include "../include/ls.h"

void my_printf(char const *str, ...)
{
    char const *flags[] = {"%c", "%s", "%d", "%i", "ld", "%o",
    "%x", "%X", "%b", "%u", "%li", "lx", NULL};
    p_fonct put[12] = {&my_putchar, &my_putstr, &my_put_nbr, &my_put_nbr,
    &my_put_nbr_l, &my_put_nbr_o, &my_put_nbr_x, &my_put_nbr_xmaj,
    &my_put_nbr_b, &my_put_nbr_u, &my_put_nbr_l, &my_put_nbr_lx};
    va_list ap;
    int i = 0;
    va_start(ap, str);
    for (; str[i] != '\0'; i++) {
        for (int a = 0; flags[a] != NULL; a++) {
            if (my_strncmp(flags[a], &str[i], 2) == 0) {
                put[a](va_arg(ap, char *));
                i += 2;
                break;
            }
        }
        if (str[i] == '\0')
            break;
        write(1, &str[i], 1);
    }
}