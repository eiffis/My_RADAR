/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** create_quadtree
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "quadtree.h"

quadtree_t *create_quadtree(sfIntRect boundary)
{
    quadtree_t *quadtree = malloc(sizeof(*quadtree));

    if (!quadtree)
        return NULL;
    quadtree->boundary = boundary;
    quadtree->planes = malloc(sizeof(plane_t *) * (4 + 1));
    quadtree->nbr_planes = 0;
    quadtree->divided = sfFalse;
    quadtree->children = NULL;
    if (!quadtree->planes){
        free(quadtree);
        return NULL;
    }
    return quadtree;
}
