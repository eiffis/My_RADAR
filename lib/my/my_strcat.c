/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** Concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    while (dest[i])
        i++;
    for (int k = 0; src[k] != '\0'; k++) {
        dest[i] = src[k];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
