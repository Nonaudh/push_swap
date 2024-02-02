/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:05:13 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:05:15 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	value_location_in_b(t_stack *b, int value)
{
	int	i;

	i = b->bottom;
	if (value > b->values[b->top] && value < b->values[i])
		return (b->values[b->top]);
	while (i != b->top)
	{
		if (value > b->values[i] && value < b->values[index_up(b, i)])
			return (b->values[i]);
		i = index_up(b, i);
	}
	exit(EXIT_FAILURE);
}

int	find_value_dst(t_stack *b, int value)
{
	int	min;
	int	max;

	min = find_min_value(b);
	max = find_max_value(b);
	if (min > value || max < value)
		return (max);
	return (value_location_in_b(b, value));
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	value_src;
	int	value_dst;

	value_src = find_value_opti(a, b);
	value_dst = find_value_dst(b, value_src);
	align_a_and_b(a, b, value_src, value_dst);
	push_b(a, b);
}

void	sort_hundred(t_stack *a, t_stack *b)
{
	while (b->num_entries != 2)
		push_b(a, b);
	while (a->num_entries != 3)
		push_to_b(a, b);
	sort_three(a);
	final_push(a, b);
}
