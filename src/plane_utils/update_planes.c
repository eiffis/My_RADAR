/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** update_planes
*/
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "tower.h"
#include "plane.h"
#include "collision.h"
#include "quadtree.h"
#include "utils.h"

void update_planes(utils_t *sim, quadtree_t *quadtree, float delta_t)
{
    plane_t *plane;

    for (size_t i = 0; i < sim->nbr_planes; i++){
        plane = sim->planes[i];
        if (sim->planes[i]->crashed == sfFalse)
            plane_travelling(sim->planes[i], delta_t, quadtree);
        if (sim->planes[i]->visible == 0){
            remove_quadtree(quadtree, sim->planes[i]);
            quadtree_insert(quadtree, sim->planes[i]);
        }
        if (sim->planes[i]->crashed == sfTrue){
            sim->planes[i]->visible = 1;
            remove_quadtree(quadtree, plane);
        }
    }
}
