/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** tower
*/
#include "SFML/Graphics.h"

#ifndef INCLUDED_TOWER_H
    #define INCLUDED_TOWER_H

typedef struct tower_s {
    sfVector2f position;
    sfCircleShape *range;
    unsigned int radius;
    sfSprite *tower;
}tower_t;

tower_t *create_tower(sfVector2f position, unsigned int radius);
tower_t **init_tower_from_data(char *data, sfTexture *texture, int *nbr_tower);
char *file_to_buffer(const char *filepath);

#endif
