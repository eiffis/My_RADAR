/*
** EPITECH PROJECT, 2024
** my_putscience.c
** File description:
** Take a double arg and return it with the scientific notation
*/
#include "my.h"
#include <stdlib.h>

char *my_putsciencemin(double number, int aftercomma)
{
    int count = 0;
    char *str = malloc(sizeof(char)
        * my_strlen(my_get_double(number, 0) + 1));

    if (number < 0){
        str[0] = '-';
        number = - number;
    }
    for (int i = 0; number < 1; i++) {
        number *= 10;
        count++;
    }
    str = my_strcat(str, my_get_double(number, aftercomma));
    if (count < 10)
        str = my_strcat(str, "e-0");
    else
        str = my_strcat(str, "e-");
    str = my_strcat(str, my_int_to_str(count));
    return str;
}

char *my_putsciencesup(double number, int aftercomma)
{
    int count = 0;
    char *str = malloc(sizeof(char)
        * my_strlen(my_get_double(number, 0) + 1));

    if (number < 0){
        str[0] = '-';
        number = - number;
    }
    for (int i = 0; number > 10; i++) {
        number /= 10;
        count++;
    }
    str = my_strcat(str, my_get_double(number, aftercomma));
    if (count < 10)
        str = my_strcat(str, "e+0");
    else
        str = my_strcat(str, "e+");
    str = my_strcat(str, my_int_to_str(count));
    return str;
}

char *my_putscience(double number, int aftercomma)
{
    if (number > 10 || number < -10)
        return my_putsciencesup(number, aftercomma);
    else
        return my_putsciencemin(number, aftercomma);
}
