/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:09:48 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:09:52 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	if (stack_empty(src))
		return ;
	if (!stack_empty(dst))
		dst->top = index_up(dst, dst->top);
	dst->values[dst->top] = src->values[src->top];
	src->top = index_down(src, src->top);
	src->num_entries--;
	dst->num_entries++;
	if (stack_empty(src))
	{
		src->bottom = 0;
		src->top = 0;
	}
}

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}
