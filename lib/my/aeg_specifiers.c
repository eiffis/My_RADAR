/*
** EPITECH PROJECT, 2024
** aeg_specifier.c
** File description:
** File for return of the specifier function
*/
#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

char *specifier_e(va_list list)
{
    return my_putscience(va_arg(list, double), 6);
}

char *specifier_upe(va_list list)
{
    return my_strupcase(my_putscience(va_arg(list, double), 6));
}

char *specifier_g(va_list list)
{
    return my_shorter(va_arg(list, double));
}

char *specifier_upg(va_list list)
{
    return my_strupcase(my_shorter(va_arg(list, double)));
}
