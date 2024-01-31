CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = src/algorithm_a_to_b.c src/check_arg.c src/error_and_free.c \
src/execute_strategy.c src/final_push.c src/op_push.c src/op_rotate.c \
src/op_r_rotate.c src/op_swap.c src/push_swap.c src/sort.c src/sort_hundred.c \
src/sort_utils.c src/stack_utils.c src/strategies.c src/stragegy_utils.c

#SRC_DIR = src/

OBJECTS = $(SOURCES:%.c=%.o)

INCLUDE = -Llib/libft -lft -Llib/ft_printf -lftprintf

#LIBFT = libft.a
#FT_PRINTF = libftprintf.a
NAME = push_swap

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME) : $(OBJECTS)
	$(MAKE) -C lib/libft/
	$(MAKE) -C lib/ft_printf/
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE) -o $(NAME) 

$(LIBFT):
	$(MAKE) -C lib/libft/

$(FT_PRINTF):
	$(MAKE) -C lib/ft_printf/

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