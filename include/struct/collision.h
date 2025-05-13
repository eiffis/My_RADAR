/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** collision
*/

#ifndef INCLUDED_COLLISION_H
    #define INCLUDED_COLLISION_H
    #include <SFML/Graphics.h>
    #include "tower.h"
    #include "plane.h"
    #include "quadtree.h"

sfBool plane_in_control_area(plane_t *plane, tower_t *tower);
sfBool is_colliding(plane_t *plane1, plane_t *plane2,
    tower_t **towers, int nbr_towers);
void quadtree_check_collide(quadtree_t *quadtree,
    tower_t **towers, int nbr_towers);
sfBool corner_in_area(sfFloatRect hitbox, sfVector2f towerpos, float radius);
#endif
