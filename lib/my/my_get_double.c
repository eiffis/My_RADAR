/*
** EPITECH PROJECT, 2024
** my_put_double_str.c
** File description:
** a function that put a double into a string
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *zero_before(double nb, int coma, int c_zero)
{
    char *zero = malloc(sizeof(char) * c_zero + 1);
    int i = 0;

    while (c_zero > 0) {
        zero[i] = '0';
        c_zero--;
        i++;
    }
    zero[i] = '\0';
    return zero;
}

char *zero_on_int(unsigned long long int left)
{
    char *r_value;

    if (left == 0) {
        r_value = malloc(sizeof(char) * 3);
        r_value = "0.";
    } else {
        r_value = malloc(sizeof(char) * 2);
        r_value = ".";
    }
    return r_value;
}

char *left_side(double nb, int coma)
{
    unsigned long long int left;
    char *str;
    unsigned long long int res;
    int len = 0;
    int i = 0;

    left = (unsigned long long int) nb;
    res = left;
    for (; res != 0; len++)
        res /= 10;
    str = malloc(sizeof(char) * (len + 2));
    for (; left != 0; i++) {
        res = left % 10;
        str[i] = res + '0';
        left /= 10;
    }
    str[i] = '\0';
    my_revstr(str);
    my_strcat(str, zero_on_int((int) nb));
    return str;
}

char *right_side(double nb, int coma, int c_zero)
{
    unsigned long long int right;
    char *str;
    unsigned long long int res;
    int len = 0;
    int i = 0;

    right = (unsigned long long int) nb;
    res = right;
    for (; res != 0; len++)
        res /= 10;
    str = malloc(sizeof(char) * (len + 2));
    for (; right != 0; i++) {
        res = right % 10;
        str[i] = res + '0';
        right /= 10;
    }
    str[i] = '\0';
    my_strcat(str, zero_before(nb, coma, c_zero));
    my_revstr(str);
    return str;
}

static char *check_neg(double nb, char *r_value)
{
    if (nb < 0) {
        r_value[0] = '-';
        r_value[1] = '\0';
    } else
        r_value[0] = '\0';
    return r_value;
}

char *my_get_double(double nb, int coma)
{
    char *r_value = malloc(sizeof(char) * (20 + coma));
    double rounding = 1;
    int c_zero = 0;

    r_value = check_neg(nb, r_value);
    if (nb < 0)
        nb *= -1;
    for (int i = 0; i < coma; i++)
        rounding *= 0.1;
    nb += 0.5f * rounding;
    my_strcat(r_value, left_side(nb, coma));
    nb -= (int) nb;
    for (int j = 0; j < coma; j++) {
        nb *= 10;
        if (c_zero == j && (int) nb == 0)
            c_zero++;
    }
    my_strcat(r_value, right_side(nb, coma, c_zero));
    return r_value;
}
