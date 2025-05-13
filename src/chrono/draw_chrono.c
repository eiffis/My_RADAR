/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** draw_timer
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "utils.h"

void draw_chrono(sfRenderWindow *window, sfText *chrono_text)
{
    sfRenderWindow_drawText(window, chrono_text, NULL);
}
