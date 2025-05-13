/*
** EPITECH PROJECT, 2024
** my_int_to_str.c
** File description:
** convert an int to and char *
*/
#include <stdlib.h>
#include "my.h"

char *put_inside_str(char *str, int nb)
{
    int i = 0;
    int res;

    for (; nb > 0; i++) {
        res = nb % 10;
        str[i] = res + '0';
        nb /= 10;
    }
    return str;
}

char *my_int_to_str(int nb)
{
    unsigned long long int res = 0;
    int copy = nb;
    int j = 0;
    char *str;

    if (nb < 0) {
        nb *= -1;
    }
    res = nb;
    for (; res > 0; j++)
        res /= 10;
    str = malloc(sizeof(char) * (j + 2));
    str = put_inside_str(str, nb);
    if (copy < 0) {
        str[j] = '-';
        j++;
    }
    str[j] = '\0';
    my_revstr(str);
    return str;
}
