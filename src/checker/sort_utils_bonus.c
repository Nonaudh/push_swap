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
