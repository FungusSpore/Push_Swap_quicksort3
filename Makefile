NAME = push_swap
DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a
SOURCE =\
		 src/error_checking.c src/presort_enumeration.c src/push_swap.c \
		 src/sort_chucks.c src/split_chuck.c src/setting_pivot.c src/simple_sort.c \
		 src/simple_sort_logic.c src/handle_bottom_a.c src/handle_bottom_b.c src/handle_top_b.c \
		 operators/push.c operators/reverse_rotate.c operators/rotate.c operators/swap.c
OBJ = $(SOURCE:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I$(DIR_LIBFT) $(^) -o $(@)

$(LIBFT):
	make -C $(DIR_LIBFT) bonus

%.o: %.c
	$(CC) $(CFLAGS) -I$(DIR_LIBFT) -c $(<) -o $(@)

clean:
	rm -rf operators/*.o
	rm -rf src/*.o
	make -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
