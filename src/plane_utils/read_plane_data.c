/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** read_plane_data
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/struct/plane.h"
#include "../../include/my.h"

plane_t *create_plane_from_data(char **data_array,
    int index, sfTexture *texture)
{
    sfVector2f departure = {my_getnbr(data_array[index + 1]),
        my_getnbr(data_array[index + 2])};
    sfVector2f arrival = {my_getnbr(data_array[index + 3]),
        my_getnbr(data_array[index + 4])};
    float speed = my_getnbr(data_array[index + 5]);
    float delay = my_getnbr(data_array[index + 6]);
    plane_t *new_plane = create_plane(departure, arrival, speed, delay);

    if (new_plane) {
        sfSprite_setTexture(new_plane->airplane, texture, sfTrue);
        sfSprite_setPosition(new_plane->airplane, departure);
    }
    return new_plane;
}

void iterate_trought_tab(plane_t *new_plane, plane_t **planes, int *it)
{
    if (new_plane) {
        planes[(*it)] = new_plane;
        (*it)++;
    }
}

plane_t **init_plane_from_data(char *data, sfTexture *texture, int *nbr_plane)
{
    char **data_array = my_str_to_word_array(data);
    plane_t **planes;
    plane_t *new_plane;
    int it = 0;

    *nbr_plane = 0;
    for (int i = 0; data_array[i]; i++)
        if (data_array[i][0] == 'A')
            (*nbr_plane)++;
    planes = malloc(sizeof(plane_t *) * (*nbr_plane + 1));
    if (!planes || !data_array)
        return NULL;
    for (int i = 0; data_array[i]; i++) {
        if (data_array[i][0] == 'A') {
            new_plane = create_plane_from_data(data_array, i, texture);
            iterate_trought_tab(new_plane, planes, &it);
        }
    }
    planes[*nbr_plane] = NULL;
    return planes;
}
