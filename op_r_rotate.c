/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:56:31 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 12:57:44 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stck)
{
	int	tmp;

	if (stack_full(stck))
	{
		stck->bottom = index_up(stck, stck->bottom);
		stck->top = index_up(stck, stck->top);
	}
	else
	{
		tmp = stck->values[stck->bottom];
		stck->bottom = index_up(stck, stck->bottom);
		stck->top = index_up(stck, stck->top);
		stck->values[stck->top] = tmp;
	}
}

void	r_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	r_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	r_rotate_ab(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
