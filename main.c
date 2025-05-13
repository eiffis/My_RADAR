/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** main
*/

#include "SFML/Graphics.h"
#include "tower.h"
#include "plane.h"
#include "collision.h"
#include "quadtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "helper.h"
#include "chrono.h"
#include "utils.h"

utils_t init_sim(void)
{
    utils_t sim = {0};

    sim.show_rectangle = true;
    sim.show_sprites = true;
    sim.chrono_clock = sfClock_create();
    sim.minutes = 0;
    sim.chrono_text = NULL;
    sim.seconds = 0;
    return sim;
}

static int check_error(int init, sfRenderWindow *window, utils_t sim,
    int inittextures)
{
    if ((inittextures == 1) | !window || init != 0){
        destroy_all(&sim, window);
        return 84;
    }
    return 0;
}

static void call_function(sfRenderWindow *window, utils_t sim, sfEvent event,
    quadtree_t *quadtree)
{
    sfRenderWindow_setFramerateLimit(window, 30);
    sim_loop(window, &sim, event, quadtree);
    destroy_all(&sim, window);
}

int display_helper(char **av)
{
    if ((my_strcmp(av[1], "-h") == 0)) {
        print_helper("./src/helper/helper.txt");
        return 1;
    }
    return 0;
}

int no_window(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (display_helper(av) == 1)
        return -1;
    return 0;
}

int main(int ac, char **av)
{
    utils_t sim = init_sim();
    int inittextures = init_textures(&sim);
    sfFont *font = sfFont_createFromFile("./src/chrono/stocky.ttf");
    int data;
    int init = init_chrono(&sim, font);
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    quadtree_t *quadtree = create_quadtree((sfIntRect){0, 0, 1920, 1080});
    sfRenderWindow *window = sfRenderWindow_create(mode,
        "my_radar", sfResize | sfClose, NULL);

    if (no_window(ac, av) == -1 || (no_window(ac, av) == 84))
        return -1;
    data = load_data(&sim, av[1]);
    if (data == 84)
        return 84;
    if (check_error(init, window, sim, inittextures) == 84)
        return 84;
    call_function(window, sim, event, quadtree);
    return 0;
}
