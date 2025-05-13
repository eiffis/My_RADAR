/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** sim_loop
*/

#include "SFML/Graphics.h"
#include "tower.h"
#include "plane.h"
#include "collision.h"
#include "quadtree.h"
#include "utils.h"
#include <stdio.h>
#include "chrono.h"

void event_loop(sfRenderWindow *window, sfEvent event, utils_t *sim)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyL)){
            sim->show_rectangle = !sim->show_rectangle;
        }
        if ((event.type == sfEvtKeyPressed) && (event.key.code == sfKeyS)){
            sim->show_sprites = !sim->show_sprites;
        }
    }
}

sfBool end_sim(utils_t *sim)
{
    int end = 0;

    for (size_t i = 0; i < sim->nbr_planes; i++){
        if ((sim->planes[i]->crashed == sfTrue) ||
            (sim->planes[i]->livepos.x == sim->planes[i]->arrival.x &&
            sim->planes[i]->livepos.y == sim->planes[i]->arrival.y)){
                end++;
            }
    }
    if (end == sim->nbr_planes)
        return sfTrue;
    return sfFalse;
}

void sim_loop(sfRenderWindow *window, utils_t *sim,
    sfEvent event, quadtree_t *quadtree)
{
    sfClock *clock = sfClock_create();
    sfTime elapsed_time;
    float delta_t;

    while (sfRenderWindow_isOpen(window)){
        elapsed_time = sfClock_restart(clock);
        delta_t = sfTime_asSeconds(elapsed_time);
        event_loop(window, event, sim);
        if (end_sim(sim) == sfTrue)
            sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfBlack);
        update_chrono(sim);
        quadtree_clear(quadtree);
        update_planes(sim, quadtree, delta_t);
        quadtree_check_collide(quadtree, sim->towers, sim->nbr_towers);
        draw_sprites(sim, window);
        draw_chrono(window, sim->chrono_text);
        sfRenderWindow_display(window);
        sfSleep(sfMilliseconds(16));
    }
}
