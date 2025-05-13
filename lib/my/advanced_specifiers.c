/*
** EPITECH PROJECT, 2024
** advanced_flags.c
** File description:
** function that contains more advanced flags
*/
#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

char *specifier_o(va_list list)
{
    return my_base(va_arg(list, unsigned int));
}

char *specifier_x(va_list list)
{
    return my_hexa(va_arg(list, unsigned long));
}

char *specifier_xup(va_list list)
{
    char *lower = my_hexa(va_arg(list, unsigned long));

    return my_strupcase(lower);
}

char *specifier_p(va_list list)
{
    return my_adressptr(va_arg(list, void *));
}

char *specifier_u(va_list list)
{
    return my_int_to_str(va_arg(list, unsigned int));
}
