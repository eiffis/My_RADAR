/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** init_timer
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <utils.h>

int init_chrono(utils_t *sim, sfFont *chronofont)
{
    sfVector2f position_text = (sfVector2f){40, 10};

    sim->chrono_text = sfText_create();
    sfText_setFont(sim->chrono_text, chronofont);
    sfText_setCharacterSize(sim->chrono_text, 26);
    sfText_setColor(sim->chrono_text, sfYellow);
    sfText_setPosition(sim->chrono_text, position_text);
    return 0;
}
