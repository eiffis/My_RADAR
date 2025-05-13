/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** draw_tower
*/

#include "SFML/Graphics.h"
#include "tower.h"
#include "plane.h"
#include "collision.h"
#include "quadtree.h"
#include "utils.h"

static void display_hitbox_plane(utils_t *sim, int i, sfRenderWindow *window)
{
    if (sim->show_rectangle){
        sfRenderWindow_drawRectangleShape(window,
            sim->planes[i]->rectangle, NULL);
    }
}

static void display_plane_sprite(utils_t *sim, int i, sfRenderWindow *window)
{
    if (sim->show_sprites)
        sfRenderWindow_drawSprite(window, sim->planes[i]->airplane, NULL);
}

void draw_sprites(utils_t *sim, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, sim->bgsprite, NULL);
    for (size_t i = 0; i < sim->nbr_planes; i++){
        if (sim->planes[i]->visible == 0){
            display_plane_sprite(sim, i, window);
            display_hitbox_plane(sim, i, window);
        }
    }
    for (size_t k = 0; k < sim->nbr_towers; k++){
        if (sim->show_sprites)
            sfRenderWindow_drawSprite(window, sim->towers[k]->tower, NULL);
        if (sim->show_rectangle){
            sfRenderWindow_drawCircleShape(window,
                sim->towers[k]->range, NULL);
        }
    }
}
