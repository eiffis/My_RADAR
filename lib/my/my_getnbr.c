/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** Returns a number sent to a function as a string
*/
#include <stdio.h>

int verif(char const *str, int count, int res, int i)
{
    while ((str[i] >= '0') && (str[i] <= '9')){
        if (count % 2 != 0)
            res = (res * 10) - (str[i] - 48);
        else
        res = (res * 10 + str[i] - 48);
        if ((res > 0) && (count % 2 != 0))
            return 0;
        if ((res < 0) && (count % 2 == 0))
            return 0;
        i++;
    }
    return res;
}

int my_getnbr(char const *str)
{
    int res = 0;
    int count = 0;
    int i = 0;

    while ((str[i] < '0') || (str[i] > '9')){
        if (str[i] == '-'){
            count++;
            i++;
            continue;
        }
        if (str[i] != '+'){
            return 0;
        }
        i++;
    }
    return verif(str, count, res, i);
}
