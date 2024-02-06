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

#include "../../inc/checker.h"

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
