/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** a copy of the printf function
*/

#include "my.h"
#include "../../include/struct/struct.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static const arr_t ARRAY[] = {
    {'c', specifier_c},
    {'d', specifier_d},
    {'i', specifier_d},
    {'s', specifier_s},
    {'%', specifier_percent},
    {'o', specifier_o},
    {'x', specifier_x},
    {'X', specifier_xup},
    {'e', specifier_e},
    {'E', specifier_upe},
    {'u', specifier_u},
    {'p', specifier_p},
    {'f', specifier_f},
    {'F', specifier_f},
    {'g', specifier_g},
    {'G', specifier_upg},
};

char *check_array(int i, va_list list, const char *fmt)
{
    char *return_value;

    for (int l = 0; ARRAY[l].specifier != '\0'; l++) {
        if (fmt[i] == ARRAY[l].specifier) {
            return_value = ARRAY[l].f_specifier(list);
            return return_value;
        }
    }
    return_value = malloc(sizeof(char) * 3);
    return_value[0] = fmt[i - 1];
    return_value[1] = fmt[i];
    return_value[2] = '\0';
    return return_value;
}

int print_other(va_list list, int i, const char *fmt)
{
    my_putchar(fmt[i]);
    return 1;
}

int my_printf(const char *fmt, ...)
{
    va_list list;
    char *return_value;
    int len_to_handle = 0;
    int count = 0;

    for (int j = 0; fmt[j] != '\0'; j++)
        len_to_handle++;
    return_value = malloc(sizeof(char *) * len_to_handle);
    va_start(list, fmt);
    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%') {
            i++;
            return_value = check_array(i, list, fmt);
            my_putstr(return_value);
        } else {
            count += print_other(list, i, fmt);
        }
    }
    va_end(list);
    return my_strlen(return_value) + count;
}
