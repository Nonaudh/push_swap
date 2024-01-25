#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "lib/libft/libft.h"
#include "lib/ft_printf/ft_printf.h"

#include <stdio.h> ///////|to_delete|////////

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

void	check_valid_arg(p_s *data, char *arg, int *tab);
void	check_duplicate(p_s *data, int *tab, int size);
void	simplify_and_stack(int *tab, int *values, int size);

void	print_stack(stack *stck); ///////|to_delete|////////

int		index_down(stack *stck, int index);
int		index_up(stack *stck, int index);

bool	stack_full(stack *a);
bool	stack_empty(stack *a);

void	error(p_s *data);
void	free_data(p_s *data);

void    swap(stack *stck);
void	swap_a(p_s *data);
void	swap_b(p_s *data);
void	swap_ab(p_s *data);

void	push(stack *src, stack *dst);
void	push_a(p_s *data);
void	push_b(p_s *data);

void	rotate(stack *stck);
void	rotate_a(p_s *data);
void	rotate_b(p_s *data);
void	rotate_ab(p_s *data);

void	reverse_rotate(stack *stck);
void	r_rotate_a(p_s *data);
void	r_rotate_b(p_s *data);
void	r_rotate_ab(p_s *data);

void    sort(p_s *data);
bool	is_a_sorted(stack *a);

void	sort_three_a(p_s *data, stack *a);
void	sort_three_b(p_s *data, stack *b);

void    sort_two(p_s *data, stack *a);

void	sort_five(p_s *data, stack *a, stack *b);

void	sort_one_hundred(p_s *data, stack *a, stack *b);

int		find_index(int value, int *tab, stack *b);
int 	locate_index(int value, int *tab, stack *b);
int		index_min(stack *stck);
bool	value_is_min(int value, int *tab, stack *b);
int		index_max(stack *stck);
bool	value_is_max(int value, int *tab, stack *b);

void    push_to_index(p_s *data, stack *b, int *tab, int index);

#endif
