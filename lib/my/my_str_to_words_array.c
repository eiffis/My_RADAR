/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** Splits a string into words
*/
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int static char_isalpha(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
    || (c >= 48 && c <= 57))
        return 1;
    return 0;
}

int count_words(char const *str)
{
    int count = 0;
    int i = 0;

    for (; str[i] != '\0';){
        while (char_isalpha(str[i]) && str[i]){
            i++;
            continue;
        }
        count++;
        while (!char_isalpha(str[i]) && str[i]){
            i++;
            continue;
        }
    }
    return count;
}

int wordlength(char const *str, int start)
{
    int length = 0;

    for (int i = start; char_isalpha(str[i]); i++){
        length++;
    }
    return length;
}

char *my_strndup(char const *str, int start)
{
    int k = 0;
    int length = wordlength(str, start);
    char *dup = malloc(sizeof(char) * (length + 1));

    for (int p = start; p != (start + length); p++){
        dup[k] = str[p];
        k++;
    }
    dup[k] = '\0';
    return dup;
}

int delim(char const *str, int start)
{
    int count = 0;

    for (int i = start; !char_isalpha(str[i]) && str[i] != '\0'; i++){
        count++;
    }
    return count;
}

char **my_str_to_word_array(char const *str)
{
    int start = 0;
    int length = 0;
    int count = 0;
    char **pol;

    for (; !char_isalpha(str[0]) && str[0] != '\0'; str++);
    count = count_words(str);
    pol = malloc(sizeof(char *) * (count + 1));
    length = wordlength(str, 0);
    for (int i = 0; i != count; i++){
        pol[i] = my_strndup(str, start);
        start += length;
        start += delim(str, start);
        length = wordlength(str, start);
    }
    pol[count] = NULL;
    return pol;
}
