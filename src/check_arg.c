/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:59:13 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 12:59:15 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_duplicate(t_ps *data, int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && tab[i] == tab[j])
			{
				free(tab);
				error(data);
			}
			j++;
		}
		i++;
	}
}

void	check_valid_arg(t_ps *data, char *arg, int *tab)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (arg[i] <= 32)
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			free(tab);
			error(data);
		}
		i++;
	}
	nb = ft_atol(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		error(data);
}
