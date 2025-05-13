/*
** EPITECH PROJECT, 2024
** my_helper.h
** File description:
** Helper for my_lib
*/
#include <dirent.h>
#include <stdarg.h>
#include "../../include/struct/struct.h"
#include <SFML/Audio.h>

#ifndef MY_HELPER_H
    #define MY_HELPER_H

int my_len_array(char **str);

char *my_revstr(char *str);

int my_putstr(char const *str);

char *my_strupcase(char *str);

char *my_strdup(char const *src);

int my_strcmp(char const *s1, char const *s2);

int my_put_nbr(int nb);

char my_putchar(char c);

int my_getnbr(char const *str);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

char *my_shorter(double number);

int my_printf(const char *fmt, ...);

int my_len_int(int nb);

char *my_get_double(double nb, int after_coma);

char *my_base(unsigned int nb);

char *my_hexa(unsigned long nb);

int my_put_bignbr(long long int nb);

char *specifier_c(va_list list);

char *specifier_s(va_list list);

char *specifier_percent(va_list list);

char *specifier_d(va_list list);

char *specifier_f(va_list list);

char *my_adressptr(void *ptr);

char *specifier_o(va_list list);

char *specifier_x(va_list list);

char *specifier_xup(va_list list);

char *specifier_p(va_list list);

char *specifier_e(va_list list);

char *specifier_upe(va_list list);

char *specifier_g(va_list list);

char *specifier_upg(va_list list);

char *specifier_u(va_list list);

char *my_int_to_str(int nb);

char *my_putscience(double number, int aftercomma);

char *my_strncpy(char *dest, char *src, int n);

char *my_strcpy(char *dest, char const *src);

char **my_str_to_word_array(char const *str);

#endif
