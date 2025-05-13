/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** plane_move
*/
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "plane.h"
#include "../../include/my.h"
#include "math.h"
#include "quadtree.h"

int plane_waiting(plane_t *plane, float delay_time)
{
    if (plane->delay > 0){
        plane->delay -= delay_time;
        plane->visible = 1;
        return 1;
    }
    return 0;
}

float distance_calculation(plane_t *plane)
{
    sfVector2f direction;
    float distance;

    direction.x = plane->arrival.x - plane->livepos.x;
    direction.y = plane->arrival.y - plane->livepos.y;
    distance = sqrtf((direction.x * direction.x)
        + (direction.y * direction.y));
    return distance;
}

sfVector2f travel_calculation(plane_t *plane, float distance)
{
    sfVector2f direction;

    direction.x = plane->arrival.x - plane->livepos.x;
    direction.y = plane->arrival.y - plane->livepos.y;
    direction.x /= distance;
    direction.y /= distance;
    return direction;
}

void update_livepos_plane(plane_t *plane,
    float distance, float delay_time)
{
    sfVector2f direction;

    direction = travel_calculation(plane, distance);
    plane->livepos.x += (direction.x * plane->speed * delay_time);
    plane->livepos.y += (direction.y * plane->speed * delay_time);
}

void plane_travelling(plane_t *plane, float delay_time, quadtree_t *quadtree)
{
    float distance = 0;

    if (plane_waiting(plane, delay_time) == 1)
        return;
    plane->visible = 0;
    distance = distance_calculation(plane);
    if (distance < 1.0f){
        plane->livepos = plane->arrival;
        plane->visible = 1;
        return;
    }
    update_livepos_plane(plane, distance, delay_time);
    sfSprite_setPosition(plane->airplane, plane->livepos);
    sfRectangleShape_setPosition(plane->rectangle, plane->livepos);
    set_hitbox_plane(plane);
    remove_quadtree(quadtree, plane);
    quadtree_insert(quadtree, plane);
}
