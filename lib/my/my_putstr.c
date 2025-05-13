/*
** EPITECH PROJECT, 2024
** my_put_str
** File description:
** Displays, one by one the char of a string
*/
#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
    }
    return 1;
}
