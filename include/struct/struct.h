/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** struct
*/

#include <stdarg.h>

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H

typedef struct array_functions_s {
    char specifier;
    char *(*f_specifier)(va_list);
}arr_t;


#endif
