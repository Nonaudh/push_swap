#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "lib/libft/libft.h"
#include "lib/ft_printf/ft_printf.h"

#include <stdio.h> /////////

typedef struct s_stack
{
	int *values;
	int bottom;
	int top;
	int size;
	int num_entries;
} stack;

typedef struct push_swap
{
	stack a;
	stack b;
} p_s;

int	    main(int argc, char *argv[]);
void	init_data(p_s *data, int argc, char *argv[]);
void	init_stack(p_s *data, stack *stck, int size);
void	fill_the_stack(p_s *data, stack *a, int size, char *argv[]);

void	check_valid_arg(char *arg);
void	check_duplicate(int *tab, int size);
void	simplify_and_stack(int *tab, int *values, int size);

void	print_stack(stack *stck); //////

bool	stack_full(stack *a);
bool	stack_empty(stack *a);

void    swap(stack *stck);
void	swap_a(stack *a);
void	swap_b(stack *a);
void	swap_ab(stack *a, stack *b);

int		index_down(stack *stck, int index);
int		index_up(stack *stck, int index);

void	push(stack *src, stack *dst);
void	push_a(p_s *data);
void	push_b(p_s *data);

void	rotate(stack *stck);
void	rotate_a(p_s *data)
void	rotate_b(p_s *data)
void	rotate_ab(p_s *data)

#endif
