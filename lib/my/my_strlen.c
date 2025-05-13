/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** Count and returns the number of characters
*/
#include <stdio.h>

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        count += 1;
    }
    return count;
}
