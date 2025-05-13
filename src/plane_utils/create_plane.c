/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** create_plane
*/

#include "SFML/Graphics.h"
#include "stdlib.h"
#include "plane.h"
#include <math.h>

static void set_text_planes(plane_t *plane, sfVector2f departure)
{
    sfRectangleShape_setSize(plane->rectangle, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(plane->rectangle, departure);
    sfRectangleShape_setOutlineColor(plane->rectangle, sfGreen);
    sfRectangleShape_setOutlineThickness(plane->rectangle, 2);
    sfRectangleShape_setFillColor(plane->rectangle, sfTransparent);
}

void set_hitbox_plane(plane_t *plane)
{
    sfVector2f size;
    sfVector2f pos;

    pos = sfRectangleShape_getPosition(plane->rectangle);
    size = sfRectangleShape_getSize(plane->rectangle);
    plane->hitbox.left = pos.x;
    plane->hitbox.top = pos.y;
    plane->hitbox.width = size.x;
    plane->hitbox.height = size.y;
    sfSprite_setOrigin(plane->airplane, (sfVector2f){size.x / 2, size.y / 2});
    sfRectangleShape_setOrigin(plane->rectangle,
        (sfVector2f){size.x / 2, size.y / 2});
}

void set_orientation_plane(plane_t *plane,
    sfVector2f departure, sfVector2f arrival)
{
    sfVector2f direction = {0, 0};
    float angle = 0;
    float pi = 3.14159265358979323846;

    direction.x = (arrival.x - departure.x);
    direction.y = (arrival.y - departure.y);
    angle = atan2f(direction.y, direction.x);
    angle *= (180.0f / pi);
    sfSprite_setRotation(plane->airplane, angle);
}

plane_t *create_plane(sfVector2f departure,
    sfVector2f arrival, float speed, float delay)
{
    plane_t *plane = malloc(sizeof(plane_t));

    if (!plane)
        return NULL;
    plane->departure = departure;
    plane->arrival = arrival;
    plane->livepos = departure;
    plane->speed = speed;
    plane->delay = delay;
    plane->visible = 0;
    plane->crashed = sfFalse;
    plane->airplane = sfSprite_create();
    plane->rectangle = sfRectangleShape_create();
    if (!plane->rectangle || !plane->airplane)
        return NULL;
    set_text_planes(plane, departure);
    set_hitbox_plane(plane);
    set_orientation_plane(plane, departure, arrival);
    return plane;
}
