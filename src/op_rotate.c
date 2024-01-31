/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:01:26 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:01:29 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack *stck)
{
	int	tmp;

	if (stack_full(stck))
	{
		stck->bottom = index_down(stck, stck->bottom);
		stck->top = index_down(stck, stck->top);
	}
	else
	{
		tmp = stck->values[stck->top];
		stck->bottom = index_down(stck, stck->bottom);
		stck->top = index_down(stck, stck->top);
		stck->values[stck->bottom] = tmp;
	}
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
