CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = ./push_swap

SOURCES = define_strategy.c execute_strategy.c final_push.c main.c op_push.c op_rotate.c \
op_r_rotate.c op_swap.c sort.c sort_five.c sort_hundred.c sort_three.c sort_utils.c \
utils.c

all : $(NAME)

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(NAME) : $(NAME) $(OBJECTS)
	(cd lib/libft; make all)
	$(CC) -o $(CFLAGS) $?


clean :
	(cd lib/libft; make clean)
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	(cd lib/libft; make fclean)
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean all re
