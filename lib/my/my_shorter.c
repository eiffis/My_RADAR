/*
** EPITECH PROJECT, 2024
** my_shorter.c
** File description:
** Represents the %g specifier from printf
*/
#include <stdlib.h>
#include "my.h"

char *my_shorter(double number)
{
    int i = 0;
    int len_int = my_len_int(number);
    char *strref = malloc(sizeof(char) * my_len_int(number) + 1);
    char *str = malloc(sizeof(char) * my_len_int(number) + 1);

    strref = my_get_double(number, 0);
    if (len_int > 6)
        return my_putscience(number, 5);
    for (; strref[i] != '.'; i++)
        str[i] = strref[i];
    str[i] = '\0';
    return str;
}
