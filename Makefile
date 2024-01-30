CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = ./push_swap

SOURCES = algorithm_a_to_b.c

all : $(NAME)

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(NAME) : $(OBJECTS)
	(cd lib/libft; make all)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L /libft -lft


clean :
	(cd lib/libft; make clean)
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	(cd lib/libft; make fclean)
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean all re
