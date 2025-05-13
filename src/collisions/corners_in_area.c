/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** corners_in_area
*/

#include "plane.h"
#include "tower.h"
#include "collision.h"
#include <SFML/Graphics.h>

static sfBool point_in_range(sfVector2f corner,
    sfVector2f towerpos, float radius)
{
    float distance_x = corner.x - towerpos.x;
    float distance_y = corner.y - towerpos.y;

    if ((distance_x * distance_x) +
        (distance_y * distance_y) <= (radius * radius))
        return sfTrue;
    return sfFalse;
}

sfBool corner_in_area(sfFloatRect hitbox, sfVector2f towerpos, float radius)
{
    sfVector2f corners[4];

    corners[0] = (sfVector2f){hitbox.left, hitbox.top};
    corners[1] = (sfVector2f){hitbox.left + hitbox.width, hitbox.top};
    corners[2] = (sfVector2f){hitbox.left, hitbox.top + hitbox.height};
    corners[3] = (sfVector2f){hitbox.left + hitbox.width,
        hitbox.top + hitbox.height};
    for (size_t i = 0; i < 4; i++){
        if (point_in_range(corners[i], towerpos, radius) == sfTrue)
            return sfTrue;
    }
    return sfFalse;
}
