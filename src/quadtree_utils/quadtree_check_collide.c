/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** quadtree_check_collide
*/

#include <SFML/Graphics.h>
#include "tower.h"
#include "plane.h"
#include "quadtree.h"
#include "collision.h"

sfBool control_area_bool(tower_t **towers, plane_t *plane1,
    plane_t *plane2, int nbr_towers)
{
    for (size_t i = 0; i < nbr_towers; i++){
        if ((plane_in_control_area(plane1, towers[i]) == sfTrue)
            && (plane_in_control_area(plane2, towers[i]) == sfTrue)){
                return sfTrue;
            }
    }
    return sfFalse;
}

void check_collide_loop(plane_t *plane1, plane_t *plane2,
    tower_t **towers, int nbr_towers)
{
    if ((is_colliding(plane1, plane2, towers, nbr_towers) == sfTrue)
        && (control_area_bool(towers, plane1, plane2, nbr_towers) == sfFalse)){
            plane1->crashed = sfTrue;
            plane2->crashed = sfTrue;
    }
}

void quadtree_check_collide(quadtree_t *quadtree,
    tower_t **towers, int nbr_towers)
{
    plane_t *plane1;
    plane_t *plane2;

    for (size_t i = 0; i < quadtree->nbr_planes; i++){
            plane1 = quadtree->planes[i];
            if (plane1->crashed == sfTrue)
            continue;
        for (size_t j = i + 1; j < quadtree->nbr_planes; j++){
            plane2 = quadtree->planes[j];
            check_collide_loop(plane1, plane2, towers, nbr_towers);
        }
    }
    if (quadtree->divided == sfTrue){
        for (size_t i = 0; i < 4; i++){
            quadtree_check_collide(quadtree->children[i], towers, nbr_towers);
        }
    }
}
