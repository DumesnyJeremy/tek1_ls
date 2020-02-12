/*
** EPITECH PROJECT, 2019
** getnum
** File description:
** oui
*/

#include "../include/ls.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int a = 0;
    int i = 0;
    for (;str[a] == '-' || str[a] == '+';) {
        if (str[a] == '-')
            i++;
        a++;
    }
    for (a; str[a] != '\0';) {
        if (str[a] < 48 || str[a] > 57)
            return ( nb / 10);
        nb += (str[a] - 48);
        nb = nb * 10;
        a++;
    }
    nb = nb / 10;
    if ((i % 2) == 0)
        return (nb);
    else if ((i % 2) != 0)
        return (-nb);
}
