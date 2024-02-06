CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = src/push_swap/push_swap.c src/push_swap/algorithm_a_to_b.c \
src/push_swap/check_arg.c src/push_swap/error_and_free.c src/push_swap/execute_strategy.c \
src/push_swap/final_push.c src/push_swap/init_data.c src/push_swap/op_push.c \
src/push_swap/op_rotate.c src/push_swap/op_r_rotate.c src/push_swap/op_swap.c \
src/push_swap/sort.c src/push_swap/sort_hundred.c src/push_swap/sort_utils.c \
src/push_swap/stack_utils.c src/push_swap/strategies.c src/push_swap/stragegy_utils.c

SRC_BONUS = src/checker/checker_bonus.c src/checker/check_operation_bonus.c \
src/checker/check_arg_bonus.c src/checker/error_and_free_bonus.c \
src/checker/init_data_bonus.c src/checker/op_push_bonus.c src/checker/op_rotate_bonus.c \
src/checker/op_r_rotate_bonus.c src/checker/op_swap_bonus.c src/checker/stack_utils_bonus.c \
src/checker/sort_utils_bonus.c

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

INCLUDE = -Llib/libft -lft

LIBFTDIR = lib/libft

NAME = push_swap

BONUS = checker

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	@tput setaf 2
	@$(MAKE) -sC $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo $(NAME) compiled

$(BONUS) : $(OBJ_BONUS)
	@tput setaf 2
	@$(MAKE) -sC $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCLUDE) -o $(BONUS)
	@echo $(BONUS) compiled

all : $(NAME)

bonus : $(BONUS)

clean :
	@tput setaf 3
	@rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -sC $(LIBFTDIR) clean
	@echo object files deleted

fclean : clean
	@tput setaf 3
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -sC $(LIBFTDIR) fclean
	@echo executable files deleted

re: fclean all

.PHONY : all bonus clean fclean re