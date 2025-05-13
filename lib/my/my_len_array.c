/*
** EPITECH PROJECT, 2024
** my_len_array.c
** File description:
** return the length of the array
*/
#include <stdio.h>

int my_len_array(char **str)
{
    int count = 0;

    for (int i = 0; str[i] != NULL; i++)
        count++;
    return count;
}
