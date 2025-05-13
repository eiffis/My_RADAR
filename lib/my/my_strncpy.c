/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** Copies n char from a string to another
*/
#include <stdio.h>

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
