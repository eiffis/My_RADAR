/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** planes_collide
*/

#include "plane.h"
#include "tower.h"
#include "collision.h"
#include <SFML/Graphics.h>
#include <stdio.h>
sfBool intersect_rectangle(sfFloatRect r1, sfFloatRect r2)
{
    if (!r1.height || !r2.height)
        return sfFalse;
    if (r1.left < r2.left + r2.width &&
        r1.left + r1.width > r2.left &&
        r1.top < r2.top + r2.height &&
        r1.top + r1.height > r2.top)
            return sfTrue;
    return sfFalse;
}

sfBool is_colliding(plane_t *plane1, plane_t *plane2,
    tower_t **towers, int nbr_towers)
{
    if (plane1->visible == 1 || plane2->visible == 1)
        return sfFalse;
    if (plane1 == plane2){
        return sfFalse;
    }
    if (intersect_rectangle(plane1->hitbox, plane2->hitbox)){
        return sfTrue;
    }
    return sfFalse;
}
