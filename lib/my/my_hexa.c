/*
** EPITECH PROJECT, 2024
** hexa.c
** File description:
** hexadecimal function for printf project
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_hexa(unsigned long nb)
{
    int i = 0;
    unsigned long res = 0;
    char *str;

    if (nb == 0)
        return "0";
    str = malloc(sizeof(char) * 16 + 1);
    for (; nb != 0; i++){
        res = nb % 16;
        str[i] = res + '0';
        if (str[i] < '0' || str[i] > '9')
            str[i] += 39;
        nb = nb / 16;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}
