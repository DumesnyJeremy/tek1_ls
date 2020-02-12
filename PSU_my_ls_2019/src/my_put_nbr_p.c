/*
** EPITECH PROJECT, 2019
** put nbr
** File description:
** hexa
*/

#include "../include/ls.h"

void my_put_p(long long int nb)
{
    my_putstr("0");
    my_putstr("x");
    my_put_nbr_p(nb);
}

void my_put_nbr_p(long long int nb)
{
    long long int a;

    if (nb > 0)
    {
        a = (nb % 16);
        nb = ((nb - a) / 16);
        my_put_nbr_p(nb);
        if (a <= 9)
            my_putchar(a + 48);
        else {
            my_putchar(a + 87);
        }
    }
}
