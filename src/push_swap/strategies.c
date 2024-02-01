/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:03:33 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:03:35 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	first_strategy(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->top;
	j = b->top;
	count = 1;
	while (a->values[i] != value_src && b->values[j] != value_dst)
	{
		i = index_down(a, i);
		j = index_down(b, j);
		count++;
	}
	while (a->values[i] != value_src)
	{
		i = index_down(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_down(a, j);
		count++;
	}
	return (count);
}

int	second_strategy(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->top;
	j = b->bottom;
	count = 2;
	while (a->values[i] != value_src)
	{
		i = index_down(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_up(a, j);
		count++;
	}
	return (count);
}

int	third_strategy(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->bottom;
	j = b->top;
	count = 2;
	while (a->values[i] != value_src)
	{
		i = index_up(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_down(a, j);
		count++;
	}
	return (count);
}

int	fourth_strategy(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->bottom;
	j = b->bottom;
	count = 3;
	while (a->values[i] != value_src && b->values[j] != value_dst)
	{
		i = index_up(a, i);
		j = index_up(b, j);
		count++;
	}
	while (a->values[i] != value_src)
	{
		i = index_up(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_up(a, j);
		count++;
	}
	return (count);
}
