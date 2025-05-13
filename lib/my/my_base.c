/*
** EPITECH PROJECT, 2024
** base8.c
** File description:
** base 8 function for printf project
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_base(unsigned int nb)
{
    int i = 0;
    unsigned int res = 0;
    char *str;

    if (nb == 0)
        return "0";
    str = malloc(sizeof(char) * 11 + 1);
    for (; nb != 0; i++){
        res = nb % 8;
        str[i] = res + '0';
        nb = nb / 8;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}
