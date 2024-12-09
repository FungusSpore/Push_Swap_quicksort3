NAME = push_swap
NAME_BONUS = checker
DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a
SOURCE =\
		 src/presort_enumeration.c src/push_swap.c \
		 src/sort_chucks.c src/split_chuck.c src/setting_pivot.c src/simple_sort.c \
		 src/simple_sort_logic.c src/handle_bottom_a.c src/handle_bottom_b.c src/handle_top_b.c
COMMON =\
				src/error_checking.c src/push_swap_utils.c
OPERATORS = \
						operators/push.c operators/reverse_rotate.c operators/rotate.c operators/swap.c
OPERATORS_BONUS = \
						operators_bonus/push_bonus.c operators_bonus/reverse_rotate_bonus.c \
						operators_bonus/rotate_bonus.c operators_bonus/swap_bonus.c
BONUS =\
			 bonus/checker.c
OBJ = $(SOURCE:.c=.o)
OBJ_COMMON = $(COMMON:.c=.o)
OBJ_OPERATORS = $(OPERATORS:.c=.o)
OBJ_OPERATORS_BONUS = $(OPERATORS_BONUS:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_OPERATORS) $(OBJ_COMMON) $(LIBFT)
	$(CC) $(CFLAGS) -I$(DIR_LIBFT) $(^) -o $(@)

$(LIBFT):
	make -C $(DIR_LIBFT) bonus

%.o: %.c
	$(CC) $(CFLAGS) -I$(DIR_LIBFT) -c $(<) -o $(@)

clean:
	rm -rf operators/*.o
	rm -rf operators_bonus/*.o
	rm -rf src/*.o
	rm -rf bonus/*.o
	make -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make -C $(DIR_LIBFT) fclean

re: fclean all

bonus: $(OBJ_BONUS) $(OBJ_COMMON) $(OBJ_OPERATORS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(DIR_LIBFT) $(^) -o $(NAME_BONUS)

.PHONY: all clean fclean re bonus
