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

#include "../../inc/push_swap.h"

void	align_a_and_b(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	strategy;

	strategy = define_strategy(a, b, value_src, value_dst);
	if (strategy == 1)
		ex_first_strategy(a, b, value_src, value_dst);
	if (strategy == 2)
		ex_second_strategy(a, b, value_src, value_dst);
	if (strategy == 3)
		ex_third_strategy(a, b, value_src, value_dst);
	if (strategy == 4)
		ex_fourth_strategy(a, b, value_src, value_dst);
}

int	count_operations(t_stack *a, t_stack *b, int value_src)
{
	int	value_dst;

	value_dst = find_value_dst(b, value_src);
	return (numbers_of_op(a, b, value_src, value_dst));
}

int	find_value_opti(t_stack *a, t_stack *b)
{
	int	index;
	int	c_min;
	int	current_count;
	int	x;
	int	val_opti;

	index = a->top;
	c_min = INT_MAX;
	x = 0;
	while (x < c_min && x != a->num_entries)
	{
		current_count = count_operations(a, b, a->values[index]);
		if (c_min > current_count)
		{
			c_min = current_count;
			val_opti = a->values[index];
		}
		index = index_down(a, index);
		x++;
	}
	if (x != a->num_entries)
		val_opti = value_opti_from_bottom(a, b, val_opti, c_min);
	return (val_opti);
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
