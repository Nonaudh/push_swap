/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:14:47 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:14:48 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	simplify_and_stack(int *tab, int *values, int size)
{
	int	j;
	int	i;
	int	rank;

	i = 0;
	while (i < size)
	{
		j = 0;
		rank = 0;
		while (j < size)
		{
			if (tab[i] >= tab[j])
				rank++;
			j++;
		}
		values[i] = rank;
		i++;
	}
}

void	check_values(t_ps *data, t_stack *a, int size, char **argv)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		check_valid_arg(data, argv[i], tab);
		tab[(size - 1) - i] = ft_atoi(argv[i]);
		i++;
	}
	check_duplicate(data, tab, size);
	simplify_and_stack(tab, a->values, size);
	free(tab);
	a->top = size - 1;
	a->num_entries = size;
}

void	init_stack(t_stack *stck, int size)
{
	stck->values = malloc(sizeof(int) * size);
	if (!stck->values)
		exit(EXIT_FAILURE);
	stck->bottom = 0;
	stck->top = 0;
	stck->size = size;
	stck->num_entries = 0;
}

void	init_data(t_ps *data, int argc, char **argv)
{
	init_stack(&data->a, argc);
	init_stack(&data->b, argc);
	check_values(data, &data->a, argc, argv);
}
