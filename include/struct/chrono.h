/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** timer
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>

#ifndef INCLUDED_TIMER_H
    #define INCLUDED_TIMER_H

int init_chrono(utils_t *sim, sfFont *chronofont);
void update_chrono(utils_t *sim);
void draw_chrono(sfRenderWindow *window, sfText *chrono_text);
#endif
