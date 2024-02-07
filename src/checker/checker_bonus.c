/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:53:28 by ahuge             #+#    #+#             */
/*   Updated: 2024/02/06 13:53:31 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

void	execute_operation(t_ps *data, char *op)
{
	if (op[0] == 's')
	{
		check_swap(data, op);
		return ;
	}
	if (op[0] == 'p')
	{
		check_push(data, op);
		return ;
	}
	if (op[0] == 'r' && op[2] == '\n')
	{
		check_rotate(data, op);
		return ;
	}
	if (op[0] == 'r' && op[1] == 'r')
	{
		check_reverse_rotate(data, op);
		return ;
	}
	free(op);
	error(data);
}

void	checker(t_ps *data)
{
	char	*op;

	op = get_next_line(0);
	while (op && op[0] != '\n')
	{
		execute_operation(data, op);
		free (op);
		op = get_next_line(0);
	}
	free (op);
	if (is_stack_sorted(&data->a) && stack_empty(&data->b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_ps	data;

	data.tab = NULL;
	if (argc == 2)
	{
		argc = count_arg(argv[1], ' ');
		if (!argc)
			no_arg();
		data.tab = ft_split(argv[1], ' ');
		if (!data.tab)
			exit(EXIT_FAILURE);
		init_data(&data, argc, data.tab);
		checker(&data);
		free_data(&data);
	}
	else if (argc > 2)
	{
		argc--;
		argv++;
		init_data(&data, argc, argv);
		checker(&data);
		free_data(&data);
	}
	exit(EXIT_SUCCESS);
}
