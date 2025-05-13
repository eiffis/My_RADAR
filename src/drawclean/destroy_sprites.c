/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** destroy_sprites
*/

#include "SFML/Graphics.h"
#include "tower.h"
#include "plane.h"
#include "collision.h"
#include "quadtree.h"
#include "utils.h"
#include <stdlib.h>

void destroy_sprites(utils_t *sim)
{
    for (size_t i = 0; i < sim->nbr_towers; i++){
        if (sim->towers[i]){
            sfSprite_destroy(sim->towers[i]->tower);
            sfCircleShape_destroy(sim->towers[i]->range);
            free(sim->towers[i]);
        }
    }
    for (size_t k = 0; k < sim->nbr_planes; k++){
        if (sim->planes[k]){
            sfSprite_destroy(sim->planes[k]->airplane);
            sfRectangleShape_destroy(sim->planes[k]->rectangle);
            free(sim->planes[k]);
        }
    }
    free(sim->towers);
    free(sim->planes);
}

void destroy_all(utils_t *sim, sfRenderWindow *window)
{
    sfSprite_destroy(sim->bgsprite);
    sfTexture_destroy(sim->bgtexture);
    sfTexture_destroy(sim->airplanetexture);
    sfTexture_destroy(sim->towertexture);
    free(sim->data);
    destroy_sprites(sim);
    sfRenderWindow_destroy(window);
}
