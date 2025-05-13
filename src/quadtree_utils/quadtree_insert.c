/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** quadtree_insert
*/

#include <stdlib.h>
#include "quadtree.h"
#include <stdio.h>

int quadtree_insert(quadtree_t *quadtree, plane_t *plane)
{
    if (!plane_in_boundary(quadtree->boundary, plane->livepos))
        return 1;
    if (quadtree->nbr_planes < 4 && !quadtree->divided){
        quadtree->planes[quadtree->nbr_planes] = plane;
        quadtree->nbr_planes++;
        return 0;
    }
    if (!quadtree->divided){
        if (subdivide_quadtree(quadtree) != 0)
            return -1;
        for (size_t i = 0; i < quadtree->nbr_planes; i++)
            quadtree->planes[i] = NULL;
        quadtree->nbr_planes = 0;
    }
    for (size_t k = 0; k < 4; k++){
        if (quadtree_insert(quadtree->children[k], plane) == 0)
            return 0;
    }
    return 1;
}
