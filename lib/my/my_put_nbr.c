/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** Displays the number given in parameter.
*/
#include "my.h"
#include <unistd.h>
int my_put_nbr(int nb)
{
    int n;
    char c;

    if (nb < 0){
        write(1, "-", 1);
        n = - nb;
    } else {
            n = nb;
    }
    if (n > 9){
        my_put_nbr(n / 10);
        n = n % 10;
    }
    c = n + '0';
    write(1, &c, 1);
    return 1;
}
