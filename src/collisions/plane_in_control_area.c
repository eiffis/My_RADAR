/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** plane_in_control_area
*/

#include "plane.h"
#include "tower.h"
#include "collision.h"
#include "math.h"
#include <SFML/Graphics.h>

sfBool plane_in_control_area(plane_t *plane, tower_t *tower)
{
    float distance_x = (tower->position.x - plane->livepos.x);
    float distance_y = (tower->position.y - plane->livepos.y);
    float distance = sqrtf((distance_x * distance_x)
        + (distance_y * distance_y));

    if ((distance <= tower->radius) &&
        corner_in_area(plane->hitbox, tower->position, tower->radius))
        return sfTrue;
    return sfFalse;
}
