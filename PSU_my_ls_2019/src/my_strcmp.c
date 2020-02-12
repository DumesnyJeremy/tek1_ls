/*
** EPITECH PROJECT, 2019
** task06
** File description:
** oui
*/

#include "../include/ls.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;

    for (; s1[a] == s2[a] && a < n - 1 && s1[a] != '\0'; a++);
    return (s1[a] - s2[a]);
}
