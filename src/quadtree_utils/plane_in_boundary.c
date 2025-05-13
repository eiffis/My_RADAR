/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** plane_in_boundary
*/

#include "plane.h"
#include "quadtree.h"
#include <SFML/Graphics.h>
#include <stdio.h>

sfBool plane_in_boundary(sfIntRect boundary, sfVector2f planepos)
{
    if (boundary.width <= 0 || boundary.height <= 0)
        return sfFalse;
    if (planepos.x < boundary.left ||
        planepos.x >= boundary.left + boundary.width)
            return sfFalse;
    if (planepos.y < boundary.top
        || planepos.y >= boundary.top + boundary.height)
            return sfFalse;
    return sfTrue;
}
