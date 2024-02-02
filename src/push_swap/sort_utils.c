/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:04:58 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:05:00 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_stack_sorted(t_stack *stck)
{
	int	i;

	i = stck->bottom;
	while (i != stck->top && stck->values[i] > stck->values[index_up(stck, i)])
	{
		i = index_up(stck, i);
	}
	if (i == stck->top)
		return (TRUE);
	return (FALSE);
}

int	find_max_value(t_stack *stck)
{
	int	i;
	int	x;
	int	max;

	i = stck->bottom;
	x = 0;
	max = 0;
	while (x != stck->num_entries)
	{
		if (stck->values[i] > max)
			max = stck->values[i];
		i = index_up(stck, i);
		x++;
	}
	return (max);
}

int	find_min_value(t_stack *stck)
{
	int	i;
	int	x;
	int	min;

	i = stck->bottom;
	x = 0;
	min = INT_MAX;
	while (x != stck->num_entries)
	{
		if (stck->values[i] < min)
			min = stck->values[i];
		i = index_up(stck, i);
		x++;
	}
	return (min);
}
