#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "lib/libft/libft.h"
#include "lib/ft_printf/ft_printf.h"

#define COUNT 1
#define STRAT 2
#define STRAT_1 1
#define STRAT_2 2
#define STRAT_3 3
#define STRAT_4 4

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
	char **tab;
	bool tab_to_free;
} p_s;

int	    main(int argc, char **argv);
void	init_data(p_s *data, int argc, char **argv);
void	init_stack(stack *stck, int size);
void	check_values(p_s *data, stack *a, int size, char **argv);

int		count_arg(char *arg, char c);
void	free_the_tab(char **tab, int argc);

void	check_valid_arg(p_s *data, char *arg, int *tab);
void	check_duplicate(p_s *data, int *tab, int size);
void	simplify_and_stack(int *tab, int *values, int size);

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
bool	is_stack_sorted(stack *a);

void	sort_three(p_s *data, stack *a);

void    sort_two(p_s *data, stack *a);

void	sort_five(p_s *data, stack *a);

void	sort_hundred(p_s *data, stack *a, stack *b);
void    push_to_b(p_s *data, stack *a, stack *b);
int		find_value_opti(p_s *data, stack *a, stack *b);
int		find_value_dst(stack *b, int value);
int		count_operations(p_s *data, stack *b, int value);
void	align_dst_and_src(p_s *data, stack *a, stack *b, int value_src, int value_dst);
int		value_location_b(stack *b, int *tab_b, int value);

int		find_min_value(stack *stck);
int		find_max_value(stack *stck);

int		define_strategy(stack *a, stack *b, int index_src, int index_dst, int mode);
int 	first_strategy(stack *a, stack *b, int index_src, int index_dst);
int 	second_strategy(stack *a, stack *b, int index_src, int index_dst);
int 	third_strategy(stack *a, stack *b, int value_src, int value_dst);
int 	fourth_strategy(stack *a, stack *b, int value_src, int value_dst);

int		minimum_operations(int *count);
int		best_strategy(int *count);

void	ex_first_strategy(p_s *data, stack *a, stack *b, int index_src, int index_dst);
void	ex_second_strategy(p_s *data, stack *a, stack *b, int value_src, int value_dst);
void	ex_third_strategy(p_s *data, stack *a, stack *b, int index_src, int index_dst);
void	ex_fourth_strategy(p_s *data, stack *a, stack *b, int value_src, int value_dst);

void	final_push(p_s *data, stack *a, stack *b);

void	push_to_a(p_s *data, stack *a, int *tab_a, int value_src);
int		value_location_a(stack *a, int *tab_a, int value_src);
int 	strategy_b_to_a(stack *a, int value_dst);

#endif
