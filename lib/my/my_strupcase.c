/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** Puts every letter in upper case
*/
#include <stdio.h>

char *my_strupcase(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }
    return str;
}
