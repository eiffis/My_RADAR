/*
** EPITECH PROJECT, 2024
** flags.c
** File description:
** file that contains all the functions for the printf flags
*/

#include "my.h"
#include <stdlib.h>

char *flag_plus(char *str)
{
    char *a;

    if (str[0] == '-')
        return str;
    else {
        a = malloc(sizeof(char) * (my_strlen(str) + 1));
        a[0] = '+';
        a[1] = '\0';
        my_strcat(a, str);
        return a;
    }
}

char *flag_space(char *str)
{
    char *a = malloc(sizeof(char) * (my_strlen(str) + 1));

    a[0] = ' ';
    a[1] = '\0';
    my_strcat(a, str);
    return a;
}

char *space_for_width(char *str, int w)
{
    char *copy = malloc(sizeof(char) * (my_strlen(str) + w));
    char *space = malloc(sizeof(char) * w + 1);
    int i = 0;

    my_strcpy(copy, str);
    for (; i < w; i++)
        space[i] = ' ';
    space[i] = '\0';
    my_strcat(copy, space);
    return copy;
}

char *flag_minus(char *str, int w)
{
    char *space = malloc(sizeof(char) * (my_strlen(str) + w + 1));
    int i = 0;

    for (; i < w; i++)
        space[i] = ' ';
    space[i] = '\0';
    my_strcat(space, str);
    return space;
}

char *flag_zero(char *str, int w)
{
    char *space = malloc(sizeof(char) * (my_strlen(str) + w + 1));
    int i = 0;

    for (; i < w; i++)
        space[i] = '0';
    space[i] = '\0';
    my_strcat(space, str);
    return space;
}
