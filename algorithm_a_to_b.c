/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:05:20 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:05:21 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_strategy(t_stack *a, t_stack *b, int value_src, int value_dst, int mode)
{
	int	count[4];

	count[0] = first_strategy(a, b, value_src, value_dst);
	count[1] = second_strategy(a, b, value_src, value_dst);
	count[2] = third_strategy(a, b, value_src, value_dst);
	count[3] = fourth_strategy(a, b, value_src, value_dst);
	if (mode == COUNT)
		return (minimum_operations(count, 4));
	if (mode == STRAT)
		return (best_strategy(count, 4));
	return (0);
}

void	align_a_and_b(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	strategy;

	strategy = define_strategy(a, b, value_src, value_dst, STRAT);
	if (strategy == STRAT_1)
		ex_first_strategy(a, b, value_src, value_dst);
	if (strategy == STRAT_2)
		ex_second_strategy(a, b, value_src, value_dst);
	if (strategy == STRAT_3)
		ex_third_strategy(a, b, value_src, value_dst);
	if (strategy == STRAT_4)
		ex_fourth_strategy(a, b, value_src, value_dst);
}

int	count_operations(t_stack *a, t_stack *b, int value_src)
{
	int	value_dst;

	value_dst = find_value_dst(b, value_src);
	return (define_strategy(a, b, value_src, value_dst, COUNT));
}

int	find_value_opti(t_stack *a, t_stack *b)
{
	int	index;
	int	count_min;
	int	current_count;
	int	x;
	int	value_opti;

	index = a->top;
	count_min = INT_MAX;
	x = 0;
	while (x < count_min && x != a->num_entries)
	{
		current_count = count_operations(a, b, a->values[index]);
		if (count_min > current_count)
		{
			count_min = current_count;
			value_opti = a->values[index];
		}
		index = index_down(a, index);
		x++;
	}
	return (value_opti_from_bottom(a, b, value_opti, count_min));
}

int	value_opti_from_bottom(t_stack *a, t_stack *b, int val_opti, int c_min)
{
	int	index;
	int	current_count;
	int	x;

	index = a->bottom;
	x = 0;
	while (x < c_min && x != a->num_entries)
	{
		current_count = count_operations(a, b, a->values[index]);
		if (c_min > current_count)
		{
			c_min = current_count;
			val_opti = a->values[index];
		}
		index = index_up(a, index);
		x++;
	}
	return (val_opti);
}
