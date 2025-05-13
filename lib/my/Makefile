##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## MAKEFILE
##

SRC = my_getnbr.c \
      my_putchar.c \
      my_put_nbr.c \
      my_putstr.c \
      my_printf.c \
      my_revstr.c \
      my_len_array.c \
      my_base.c \
      my_hexa.c \
      my_put_bignbr.c \
      my_get_double.c \
      my_len_int.c \
      base_specifiers.c \
      my_adressptr.c \
      advanced_specifiers.c \
      my_put_nbr_unsigned.c \
      my_int_to_str.c \
      my_printf.c \
      aeg_specifiers.c \
      my_putscience.c \
      my_shorter.c \
      my_strlen.c \
      my_strcat.c \
      my_strdup.c \
      my_strupcase.c \
      my_strncpy.c \
      my_strcpy.c \
      my_strcmp.c \
      my_str_to_words_array.c


OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror
CFLAGS += -Iinclude

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re
