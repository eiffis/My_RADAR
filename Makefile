##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## MAKEFILE
##


NAME = my_radar

SRC = src/collisions/plane_in_control_area.c \
	  src/collisions/planes_collide.c \
	  src/collisions/corners_in_area.c \
	  src/drawclean/destroy_sprites.c \
	  src/drawclean/draw_sprites.c \
	  src/plane_utils/create_plane.c \
	  src/plane_utils/plane_move.c \
	  src/plane_utils/read_plane_data.c \
	  src/plane_utils/remove_planes.c \
	  src/plane_utils/update_planes.c \
	  src/quadtree_utils/clear_quadtree.c \
	  src/quadtree_utils/create_quadtree.c \
	  src/quadtree_utils/plane_in_boundary.c \
	  src/quadtree_utils/quadtree_check_collide.c \
	  src/quadtree_utils/quadtree_insert.c \
	  src/quadtree_utils/remove_plane_quadtree.c \
	  src/quadtree_utils/subdivide_quadtree.c \
	  src/tower_utils/create_tower.c \
	  src/tower_utils/read_tower_data.c \
	  src/utils/init_textures.c \
	  src/utils/load_data.c \
	  src/utils/sim_loop.c \
	  src/chrono/draw_chrono.c \
	  src/chrono/init_chrono.c \
	  src/chrono/update_chrono.c \
	  src/helper/print_helper.c \
	  main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Iinclude/
CFLAGS += -Iinclude/struct -g
CFLAGS += -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -I ./include -I ./include/struct \
	-lm -lcsfml-window -lcsfml-graphics \
	-lcsfml-system -lcsfml-audio -L ./lib/my -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
