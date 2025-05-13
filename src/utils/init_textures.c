/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** init_textures
*/

#include "SFML/Graphics.h"
#include "tower.h"
#include "plane.h"
#include "collision.h"
#include "quadtree.h"
#include "utils.h"
#include <stdio.h>

int init_textures(utils_t *sim)
{
    const char *airplanepath = "/home/enzo/Tek1/Semester1/B-MUL/"
        "B-MUL-100-REN-1-1-myradar-enzo.iffis/assets/plane.png";
    const char *towerpath = "/home/enzo/Tek1/Semester1/B-MUL/"
        "B-MUL-100-REN-1-1-myradar-enzo.iffis/assets/tower.png";
    const char *bgpath = "/home/enzo/Tek1/Semester1/B-MUL/"
        "B-MUL-100-REN-1-1-myradar-enzo.iffis/assets/world.jpg";

    sim->airplanetexture = sfTexture_createFromFile(airplanepath, NULL);
    sim->bgtexture = sfTexture_createFromFile(bgpath, NULL);
    sim->towertexture = sfTexture_createFromFile(towerpath, NULL);
    sim->bgsprite = sfSprite_create();
    if (!sim->bgtexture || !sim->towertexture || !sim->airplanetexture){
        return 1;
    }
    sfSprite_setTexture(sim->bgsprite, sim->bgtexture, sfTrue);
    return 0;
}
