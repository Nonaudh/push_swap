CC = cc -g

CFLAGS = -Wall -Werror -Wextra

SRC1 = src/push_swap/push_swap.c

SRC2 = src/push_swap/algorithm_a_to_b.c src/push_swap/check_arg.c src/push_swap/error_and_free.c \
src/push_swap/execute_strategy.c src/push_swap/final_push.c src/push_swap/init_data.c src/push_swap/op_push.c \
src/push_swap/op_rotate.c src/push_swap/op_r_rotate.c src/push_swap/op_swap.c src/push_swap/sort.c \
src/push_swap/sort_hundred.c src/push_swap/sort_utils.c src/push_swap/stack_utils.c \
src/push_swap/strategies.c src/push_swap/stragegy_utils.c

SRC_BONUS = src/checker/checker.c

OBJ1 = $(SRC1:%.c=%.o)

OBJ2 = $(SRC2:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

INCLUDE = -Llib/libft -lft -Llib/ft_printf -lftprintf

NAME = push_swap

BONUS = checker

%.o: %.c
	$(CC) -c $< -o ${<:.c=.o} #flag

$(NAME) : $(OBJ1) $(OBJ2)
	$(MAKE) -C lib/libft/
	$(MAKE) -C lib/ft_printf/
	$(CC) $(CFLAGS) $(OBJ1) $(OBJ2) $(INCLUDE) -o $(NAME)

$(BONUS) : $(OBJ_BONUS) $(OBJ2)
	$(MAKE) -C lib/libft/
	$(MAKE) -C lib/ft_printf/
	$(CC) $(OBJ_BONUS) $(OBJ2) $(INCLUDE) -o $(BONUS)

all : $(NAME)

bonus : $(BONUS)

clean :
	rm -f $(OBJ1) $(OBJ2) $(OBJ_BONUS)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean

fclean : clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean

re: fclean all

.PHONY : clean fclean all re