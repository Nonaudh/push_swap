#include "push_swap.h"

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

void	check_duplicate(p_s *data, int *tab, int size)
{
	int	i;
	int	j;
	bool	duplicate;

	i = 0;
	duplicate = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && tab[i] == tab[j])
				error(data);
			j++;
		}
	i++;
	}
}

void	check_valid_arg(p_s *data, char *arg, int *tab)
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

void	fill_the_stack(p_s *data, stack *a, int size, char *argv[])
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);

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

void	init_stack(p_s *data, stack *stck, int size)
{
	stck->values = malloc(sizeof(int) * size);
	stck->bottom = 0;
	stck->top = 0;
	stck->size = size;
}

void	init_data(p_s *data, int argc, char *argv[])
{
	argc--;
	argv++;
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_the_stack(data, &data->a, argc, argv);
}

int	main(int argc, char *argv[])
{
	p_s	data;

	init_data(&data, argc, argv);

		print_stack(&data.a);
		print_stack(&data.b);

	sort(&data);

	/*for (int i=0; i<20; i++)
	{
		ft_printf("\n");
		print_stack(&data.a);
		print_stack(&data.b);
		if (i < 8)
			push_b(&data);
		else
			rotate_ab(&data);
	}*/
		print_stack(&data.a);
		print_stack(&data.b);
	if(is_a_sorted(&data.a))
		ft_printf("ok\n");
	free_data(&data);
	return (1);
}
