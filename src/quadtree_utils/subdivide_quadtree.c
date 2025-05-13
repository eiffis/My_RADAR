/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** subdivide_quadtree
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <quadtree.h>
#include <stdio.h>

int subdivide_quadtree(quadtree_t *quadtree)
{
    int x = quadtree->boundary.left;
    int y = quadtree->boundary.top;
    int w = quadtree->boundary.width / 2;
    int h = quadtree->boundary.height / 2;

    quadtree->children = malloc(sizeof(quadtree_t *) * 4);
    if (!(quadtree->children))
        return 1;
    quadtree->children[0] = create_quadtree((sfIntRect){x, y, w, h});
    quadtree->children[1] = create_quadtree((sfIntRect){x + w, y, w, h});
    quadtree->children[2] = create_quadtree((sfIntRect){x, y + h, w, h});
    quadtree->children[3] = create_quadtree((sfIntRect){x + w, y + h, w, h});
    for (size_t i = 0; i < 4; i++){
        if (quadtree->children[i] == NULL)
            return 1;
    }
    quadtree->divided = sfTrue;
    return 0;
}
