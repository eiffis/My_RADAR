/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** clear_quadtree
*/

#include "quadtree.h"
#include <stdlib.h>

void quadtree_clear(quadtree_t *quadtree)
{
    for (size_t i = 0; i < quadtree->nbr_planes;) {
        if (quadtree->planes[i]->crashed == sfTrue) {
            quadtree->nbr_planes--;
            quadtree->planes[i] = quadtree->planes[quadtree->nbr_planes];
        } else {
            i++;
        }
    }
    if (quadtree->divided == sfTrue) {
        for (size_t j = 0; j < 4; j++) {
            quadtree_clear(quadtree->children[j]);
        }
    }
}
