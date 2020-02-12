/*
** EPITECH PROJECT, 2019
** nbr
** File description:
** long
*/

#include "../include/ls.h"

void my_put_nbr_l(long nb)
{
    long a;

    for (; nb < 0;)
    {
        write(1, "-", 1);
        nb = nb * (-1);
    }
    if (nb >= 0)
    {
        if (nb >= 10)
        {
            a = (nb % 10);
            nb = ((nb - a) / 10);
            my_put_nbr_l(nb);
            my_putchar(a + 48);
        }
        else
            my_putchar(48 + nb % 10);
    }
}