/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** Copies a string into another
*/
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
