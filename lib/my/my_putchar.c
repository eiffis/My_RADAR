/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** Function putchar
*/
#include "my.h"
#include <unistd.h>
char my_putchar(char c)
{
    write(1, &c, 1);
    return c;
}
