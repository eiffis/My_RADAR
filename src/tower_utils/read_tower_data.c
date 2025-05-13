/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** read_tower_data
*/
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/struct/tower.h"
#include "../../include/my.h"

char *file_to_buffer(const char *filepath)
{
    struct stat file_stats;
    size_t size;
    char *buffer;
    FILE *file;
    size_t read_size = 0;

    if (stat(filepath, &file_stats) == -1)
        return NULL;
    size = file_stats.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    if (!buffer)
        return NULL;
    file = fopen(filepath, "r");
    if (!file)
        return NULL;
    read_size = fread(buffer, 1, size, file);
    buffer[read_size] = '\0';
    fclose(file);
    return buffer;
}

tower_t *create_tower_from_data(char **data_array,
    int index, sfTexture *texture)
{
    int x = my_getnbr(data_array[index + 1]);
    int y = my_getnbr(data_array[index + 2]);
    int radius = my_getnbr(data_array[index + 3]);
    tower_t *new_tower = create_tower((sfVector2f){x, y}, radius);

    if (new_tower) {
        sfSprite_setTexture(new_tower->tower, texture, sfTrue);
        sfSprite_setPosition(new_tower->tower, (sfVector2f){x, y});
        sfCircleShape_setPosition(new_tower->range,
            (sfVector2f){x + 20 - radius, y + 20 - radius});
    }
    return new_tower;
}

static void iterate_throught_tab(tower_t *new_tower, tower_t **towers, int *it)
{
    if (new_tower) {
        towers[(*it)] = new_tower;
        (*it)++;
    }
}

tower_t **init_tower_from_data(char *data, sfTexture *texture, int *nbr_tower)
{
    char **data_array = my_str_to_word_array(data);
    tower_t **towers;
    tower_t *new_tower;
    int it = 0;

    *nbr_tower = 0;
    for (int i = 0; data_array[i]; i++)
        if (data_array[i][0] == 'T')
            (*nbr_tower)++;
    towers = malloc(sizeof(tower_t *) * (*nbr_tower + 1));
    if (!towers || !data_array)
        return NULL;
    for (int i = 0; data_array[i]; i++) {
        if (data_array[i][0] == 'T') {
            new_tower = create_tower_from_data(data_array, i, texture);
            iterate_throught_tab(new_tower, towers, &it);
        }
    }
    towers[*nbr_tower] = NULL;
    return towers;
}
