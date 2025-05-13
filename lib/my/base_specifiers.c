/*
** EPITECH PROJECT, 2024
** base_flags.c
** File description:
** function that contains the flags of the mini printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

char *specifier_c(va_list list)
{
    char *return_value = malloc(sizeof(char) * 2);

    return_value[0] = va_arg(list, int);
    return_value[1] = '\0';
    return return_value;
}

char *specifier_s(va_list list)
{
    char *str = va_arg(list, char *);

    return str;
}

char *specifier_percent(va_list list)
{
    char *return_value = malloc(sizeof(char) * 2);

    return_value[0] = '%';
    return_value[1] = '\0';
    return return_value;
}

char *specifier_d(va_list list)
{
    int nbr = va_arg(list, int);
    char *str;

    if (nbr == -0)
        return "0";
    if (nbr == - 2147483648)
        return "-2147483648";
    str = my_int_to_str(nbr);
    return str;
}

char *specifier_f(va_list list)
{
    char *str = my_get_double(va_arg(list, double), 6);

    return str;
}
