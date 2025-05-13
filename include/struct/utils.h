/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H

    #include "SFML/Graphics.h"
    #include "tower.h"
    #include "plane.h"
    #include "collision.h"
    #include "quadtree.h"
    #include <stdbool.h>

typedef struct utils_s {
    sfTexture *bgtexture;
    sfTexture *towertexture;
    sfTexture *airplanetexture;
    sfSprite *bgsprite;
    char *data;
    tower_t **towers;
    plane_t **planes;
    int nbr_towers;
    int nbr_planes;
    bool show_rectangle;
    bool show_sprites;
    sfText *chrono_text;
    sfClock *chrono_clock;
    int minutes;
    int seconds;
}utils_t;

void destroy_sprites(utils_t *sim);
void destroy_all(utils_t *sim, sfRenderWindow *window);
int load_data(utils_t *sim, char const *filepath);
int init_textures(utils_t *sim);
void draw_sprites(utils_t *sim, sfRenderWindow *window);
void sim_loop(sfRenderWindow *window, utils_t *sim,
    sfEvent event, quadtree_t *quadtree);

#endif
