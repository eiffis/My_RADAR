/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** create_tower
*/

#include "SFML/Graphics.h"
#include "stdlib.h"
#include "../../include/struct/tower.h"

tower_t *create_tower(sfVector2f position, unsigned int radius)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (tower == NULL)
        return NULL;
    tower->position = position;
    tower->range = sfCircleShape_create();
    tower->radius = radius;
    tower->tower = sfSprite_create();
    sfCircleShape_setRadius(tower->range, radius);
    sfCircleShape_setPosition(tower->range, (sfVector2f){position.x - radius,
        position.y - radius});
    sfCircleShape_setFillColor(tower->range, sfTransparent);
    sfCircleShape_setOutlineColor(tower->range, sfRed);
    sfCircleShape_setOutlineThickness(tower->range, 3);
    return tower;
}
