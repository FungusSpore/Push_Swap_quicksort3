NAME = push_swap
BONUS_NAME = checker
DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a
SOURCE =\
		 src/error_checking.c src/presort_enumeration.c src/push_swap.c \
		 src/sort_chucks.c src/split_chuck.c src/setting_pivot.c src/simple_sort.c \
		 src/simple_sort_logic.c src/handle_bottom_a.c src/handle_bottom_b.c src/handle_top_b.c \
		 operators/push.c operators/reverse_rotate.c operators/rotate.c operators/swap.c
BONUS =\
			 bonus/checker.c bonus/checker_utils.c bonus/error_checking.c bonus/checker_helper.c \
			 operators_bonus/push_bonus.c operators_bonus/reverse_rotate_bonus.c \
			 operators_bonus/rotate_bonus.c operators_bonus/swap_bonus.c
OBJ = $(SOURCE:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
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
	rm -rf operators_bonus/*.o
	rm -rf bonus/*.o
	make -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	make -C $(DIR_LIBFT) fclean

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(DIR_LIBFT) $(^) -o $(@)

.PHONY: all clean fclean re bonus
