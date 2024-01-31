/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:01:04 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:01:07 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	index_up(t_stack *stck, int index)
{
	if (index == stck->size - 1)
		return (0);
	return (index + 1);
}

int	index_down(t_stack *stck, int index)
{
	if (index == 0)
		return (stck->size - 1);
	return (index - 1);
}

bool	stack_empty(t_stack *a)
{
	return (a->num_entries == 0);
}

bool	stack_full(t_stack *a)
{
	return (a->num_entries == a->size);
}

int	count_arg(char *arg, char c)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] != c && (arg[i + 1] == c || arg[i + 1] == '\0'))
			x++;
		i++;
	}
	return (x);
}
