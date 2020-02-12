/*
** EPITECH PROJECT, 2019
** getnum
** File description:
** oui
*/

#include <stdio.h>
#include "../include/ls.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
    {
        count++;
    }
    return (count);
}

char *my_strcpy(char const *src)
{
    char *dest = malloc(sizeof(char*) * (my_strlen(src) + 1));
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
        }
    dest[i] = '\0';
    return (dest);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_strcpy2(char *dest, char const *src)
{
    int i = 0;
    while (src[i]  != '\0') {
        dest[i] = src[i];
        i++;
            }
    dest[i] = '\0';
    return (dest);
}