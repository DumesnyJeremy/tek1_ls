/*
** EPITECH PROJECT, 2019
** put nbr
** File description:
** octale
*/

#include "../include/ls.h"

void my_put_nbr_o(int nb)
{
    int a;

    for (; nb < 0;)
    {
        write(1, "-", 1);
        nb = nb * (-1);
    }
    if (nb >= 0)
    {
        if (nb >= 8)
        {
            a = (nb % 8);
            nb = ((nb - a) / 8);
            my_put_nbr_o(nb);
            my_putchar(a + 48);
        }
        else
            my_putchar(48 + nb % 8);
    }
}
