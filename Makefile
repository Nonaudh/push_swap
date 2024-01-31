CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = algorithm_a_to_b.c check_arg.c error_and_free.c execute_strategy.c \
final_push.c op_push.c op_rotate.c op_r_rotate.c op_swap.c \
push_swap.c sort.c sort_hundred.c sort_utils.c stack_utils.c \
strategies.c stragegy_utils.c

OBJECTS = $(SOURCES:%.c=%.o)

INCLUDE = -Llib/libft -lft -Llib/ft_printf -lftprintf

LIBFT = libft.a
FT_PRINTF = libftprintf.a
NAME = push_swap

%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(NAME) : $(LIBFT) $(FT_PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(INCLUDE)

$(LIBFT):
	$(MAKE) -C lib/ft_printf make all

$(FT_PRINTF):
	$(MAKE) -C lib/ft_printf make all

all : $(LIBFT) $(FT_PRINTF) $(NAME)

clean :
	rm -f $(OBJECTS)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean

re: fclean all

.PHONY : clean fclean all re
