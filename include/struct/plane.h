/*
** EPITECH PROJECT, 2025
** B-MUL-100-REN-1-1-myradar-enzo.iffis
** File description:
** plane
*/

#ifndef INCLUDED_PLANE_H
    #define INCLUDED_PLANE_H
    #include <SFML/Graphics.h>

typedef struct quadtree_s quadtree_t;
typedef struct utils_s utils_t;

typedef struct plane_s {
    sfVector2f departure;
    sfVector2f arrival;
    sfVector2f livepos;
    float delay;
    float speed;
    sfSprite *airplane;
    sfFloatRect hitbox;
    sfRectangleShape *rectangle;
    int visible;
    sfBool crashed;
}plane_t;

plane_t *create_plane(sfVector2f departure,
    sfVector2f arrival, float speed, float delay);
plane_t **init_plane_from_data(char *data, sfTexture *texture, int *nbr_plane);
void plane_travelling(plane_t *plane, float delay_time, quadtree_t *quadtree);
char *file_to_buffer(const char *filepath);
void remove_planes(plane_t **planes, int *nbr_planes, int i);
void update_planes(utils_t *sim, quadtree_t *quadtree, float delta_t);
void set_hitbox_plane(plane_t *plane);
#endif
