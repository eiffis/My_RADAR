/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** update_timer
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include "utils.h"
#include <stdlib.h>

void update_chrono(utils_t *sim)
{
    sfTime elapsed_time = sfClock_getElapsedTime(sim->chrono_clock);
    char *chronotab;

    sim->seconds = (int)(sfTime_asSeconds(elapsed_time));
    if (sim->seconds >= 60){
        sim->seconds = 0;
        (sim->minutes)++;
        sfClock_restart(sim->chrono_clock);
    }
    chronotab = malloc(sizeof(char) *
        (my_len_int(sim->seconds) + my_len_int(sim->minutes) + 1));
    if (!chronotab)
        return;
    chronotab = my_strdup(my_int_to_str(sim->minutes));
    chronotab = my_strcat(chronotab, ":");
    chronotab = my_strcat(chronotab, my_int_to_str(sim->seconds));
    sfText_setString(sim->chrono_text, chronotab);
}
