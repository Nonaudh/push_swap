/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:02:00 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:02:07 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(t_ps *data)
{
	free_data(data);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_data(t_ps *data)
{
	if (data->tab_to_free)
		free_the_tab(data->tab, (data->a.size));
	free(data->a.values);
	free(data->b.values);
}

void	free_the_tab(char **tab, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
