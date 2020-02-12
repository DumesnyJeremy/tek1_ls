/*
** EPITECH PROJECT, 2019
** put nbr
** File description:
** oui
*/

#include "../include/ls.h"

void my_put_nbr_u(unsigned int nb)
{
    int a;
    int res;

    for (; nb < 0;)
    {
        res = 4294967295 - nb;
        my_put_nbr_l(res);
    }
    if (nb >= 0)
    {
        if (nb >= 10)
        {
            a = (nb % 10);
            nb = ((nb - a) / 10);
            my_put_nbr_u(nb);
            my_putchar(a + 48);
        }
        else
            my_putchar(48 + nb % 10);
    }
}
