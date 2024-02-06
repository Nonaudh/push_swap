/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:04:08 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:04:10 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

void	swap(t_stack *stck)
{
	int	tmp;

	tmp = 0;
	if (stck->num_entries <= 1)
		return ;
	tmp = stck->values[stck->top];
	stck->values[stck->top] = stck->values[index_down(stck, stck->top)];
	stck->values[index_down(stck, stck->top)] = tmp;
}
