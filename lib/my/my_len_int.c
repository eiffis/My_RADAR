/*
** EPITECH PROJECT, 2024
** my_len_int.c
** File description:
** function that return the length of a number.
*/

#include <stdlib.h>
#include "my.h"

int my_len_int(int nb)
{
    int count = 0;

    while (nb != 0) {
        count++;
        nb = nb / 10;
    }
    return count;
}
