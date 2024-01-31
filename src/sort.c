/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:04:19 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:04:21 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->num_entries != 3)
	{
		if (a->values[a->top] == 1 || a->values[a->top] == 2)
			push_b(a, b);
		else
			rotate_a(a);
	}
	sort_three(a);
	while (!stack_full(a))
		push_a(a, b);
	if (a->values[a->top] > a->values[index_down(a, a->top)])
		swap_a(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->values[a->top];
	second = a->values[index_down(a, a->top)];
	third = a->values[a->bottom];
	if (first > second && second > third && first > third)
	{
		swap_a(a);
		r_rotate_a(a);
	}
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first > third)
		r_rotate_a(a);
}

void	sort_two(t_stack *a)
{
	if (a->values[a->top] > a->values[index_down(a, a->top)])
		swap_a(a);
}

void	sort(t_ps *data)
{
	if (is_stack_sorted(&data->a))
		return ;
	if (data->a.size == 2)
		sort_two(&data->a);
	if (data->a.size == 3)
		sort_three(&data->a);
	if (data->a.size == 5 || data->a.size == 4)
		sort_five(&data->a, &data->b);
	if (data->a.size > 5)
		sort_hundred(&data->a, &data->b);
}
