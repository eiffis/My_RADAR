/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** remove_plane_quadtree
*/

#include "plane.h"
#include "quadtree.h"

void remove_quadtree(quadtree_t *quadtree, plane_t *plane)
{
    for (size_t i = 0; i < quadtree->nbr_planes; i++){
        if (quadtree->planes[i] == plane) {
            quadtree->nbr_planes--;
            quadtree->planes[i] = quadtree->planes[quadtree->nbr_planes];
            return;
        }
    }
    if (quadtree->divided == sfTrue){
        for (size_t j = 0; j < 4; j++){
            remove_quadtree(quadtree->children[j], plane);
        }
    }
}
