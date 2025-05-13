/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** quadtree
*/

#ifndef INCLUDED_QUADTREE_H
    #define INCLUDED_QUADTREE_H
    #include "plane.h"
    #include <SFML/Graphics.h>

typedef struct plane_s plane_t;

typedef struct quadtree_s {
    sfIntRect boundary;
    plane_t **planes;
    int nbr_planes;
    sfBool divided;
    struct quadtree_s **children;
}quadtree_t;

quadtree_t *create_quadtree(sfIntRect boundary);
int subdivide_quadtree(quadtree_t *quadtree);
int quadtree_insert(quadtree_t *quadtree, plane_t *plane);
void remove_quadtree(quadtree_t *quadtree, plane_t *plane);
void quadtree_clear(quadtree_t *quadtree);
sfBool plane_in_boundary(sfIntRect boundary, sfVector2f planepos);
#endif
