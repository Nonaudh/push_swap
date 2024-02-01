/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:04:35 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:04:37 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define STRATS 4
# define STRAT_1 1
# define STRAT_2 2
# define STRAT_3 3
# define STRAT_4 4

typedef struct s_stack
{
	int	*values;
	int	bottom;
	int	top;
	int	size;
	int	num_entries;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	char	**tab;
	bool	tab_to_free;
}	t_ps;

int		main(int argc, char **argv);
void	init_data(t_ps *data, int argc, char **argv);
void	init_stack(t_stack *stck, int size);
void	check_values(t_ps *data, t_stack *a, int size, char **argv);

int		count_arg(char *arg, char c);
void	free_the_tab(char **tab, int argc);

void	check_valid_arg(t_ps *data, char *arg, int *tab);
void	check_duplicate(t_ps *data, int *tab, int size);
void	simplify_and_stack(int *tab, int *values, int size);

int		index_down(t_stack *stck, int index);
int		index_up(t_stack *stck, int index);

bool	stack_full(t_stack *stck);
bool	stack_empty(t_stack *stck);

void	error(t_ps *data);
void	free_data(t_ps *data);

void	swap(t_stack *stck);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);

void	push(t_stack *src, t_stack *dst);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

void	rotate(t_stack *stck);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_ab(t_stack *a, t_stack *b);

void	reverse_rotate(t_stack *stck);
void	r_rotate_a(t_stack *a);
void	r_rotate_b(t_stack *b);
void	r_rotate_ab(t_stack *a, t_stack *b);

void	sort(t_ps *data);
bool	is_stack_sorted(t_stack *a);

void	sort_three(t_stack *a);

void	sort_two(t_stack *a);

void	sort_five(t_stack *a, t_stack *b);

void	sort_hundred(t_stack *a, t_stack *b);
void	push_to_b(t_stack *a, t_stack *b);
int		find_value_opti(t_stack *a, t_stack *b);
int		value_opti_from_bottom(t_stack *a, t_stack *b, int val_opti, int c_min);
int		find_value_dst(t_stack *b, int value);
int		count_operations(t_stack *a, t_stack *b, int value);
void	align_a_and_b(t_stack *a, t_stack *b, int value_src, int value_dst);
int		value_location_in_b(t_stack *b, int value);

int		find_min_value(t_stack *stck);
int		find_max_value(t_stack *stck);

int		define_strategy(t_stack *a, t_stack *b, int index_src, int index_dst);
int		numbers_of_op(t_stack *a, t_stack *b, int value_src, int value_dst);
int		first_strategy(t_stack *a, t_stack *b, int index_src, int index_dst);
int		second_strategy(t_stack *a, t_stack *b, int index_src, int index_dst);
int		third_strategy(t_stack *a, t_stack *b, int value_src, int value_dst);
int		fourth_strategy(t_stack *a, t_stack *b, int value_src, int value_dst);

int		minimum_operations(int *count, int size);
int		best_strategy(int *count, int size);

void	ex_first_strategy(t_stack *a, t_stack *b, int val_src, int val_dst);
void	ex_second_strategy(t_stack *a, t_stack *b, int val_src, int val_dst);
void	ex_third_strategy(t_stack *a, t_stack *b, int val_src, int val_dst);
void	ex_fourth_strategy(t_stack *a, t_stack *b, int val_src, int val_dst);

void	final_push(t_stack *a, t_stack *b);

void	push_to_a(t_stack *a, t_stack *b, int value_src);
int		value_location_a(t_stack *a, int value_src);
int		strategy_b_to_a(t_stack *a, int value_dst);

#endif
