/*
** EPITECH PROJECT, 2024
** my_adress_ptr.c
** File description:
** display the adress of a ptr.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stddef.h>

char *my_adressptr(void *ptr)
{
    char *adressptr;
    char *str;
    unsigned long adress;

    if (ptr == 0) {
        str = my_strdup("(nil)");
        return str;
    }
    adress = (unsigned long) ptr;
    adressptr = my_strdup(my_hexa(adress));
    str = malloc(sizeof(char) * my_strlen(adressptr) + 3);
    str[0] = '\0';
    str = my_strcat(str, "0x");
    str = my_strcat(str, adressptr);
    return str;
}
