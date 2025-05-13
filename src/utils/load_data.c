/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** load_data
*/

#include "utils.h"
#include "SFML/Graphics.h"
#include "tower.h"
#include "plane.h"
#include "collision.h"
#include "quadtree.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int load_data(utils_t *sim, char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1){
        my_printf("Script not found or incorrect\n");
        return 84;
    }
    sim->data = file_to_buffer(filepath);
    if (!sim->data)
        return 1;
    sim->towers = init_tower_from_data(sim->data,
        sim->towertexture, &sim->nbr_towers);
    sim->planes = init_plane_from_data(sim->data,
        sim->airplanetexture, &sim->nbr_planes);
    if (!sim->towers || !sim->planes)
        return 1;
    return 0;
}
