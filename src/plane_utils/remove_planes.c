/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** remove_planes
*/

#include "plane.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void remove_planes(plane_t **planes, int *nbr_planes, int i)
{
    if (i < 0 || i > (*nbr_planes))
        return;
    sfSprite_destroy(planes[i]->airplane);
    sfRectangleShape_destroy(planes[i]->rectangle);
    free(planes[i]);
    for (size_t i = 0; i < (*nbr_planes); i++){
        planes[i] = planes[i + 1];
    }
    (*nbr_planes)--;
    planes[(*nbr_planes)] = NULL;
}
