/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** Allocates mem and cpy the string given in arg
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int var = my_strlen(src);
    char *pol = malloc(sizeof(char) * (var + 1));
    int i = 0;

    for (; src[i] != '\0'; i++)
        pol[i] = src[i];
    pol[i] = '\0';
    return pol;
}
