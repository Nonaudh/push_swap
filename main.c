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

void	check_valid_arg(p_s *data, char *arg)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (arg[i] <= 32)
		i++;
	
	if (arg[i] == '-' || arg[i] == '+')
	{
		if(arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error(data);
		nb = (nb * 10) + (arg[i] - 48);
		i++;
	}
	nb *= sign;
	if (nb < INT_MIN || nb > INT_MAX)
		error(data);
}

void	fill_the_stack(p_s *data, stack *a, int size, char *argv[])
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);

	while (argv[i])
	{
		check_valid_arg(data, argv[i]);
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

	for (int i = 0; i != 4; i++)
	{
		print_stack(&data.a);
		//print_stack(&data.b);
		r_rotate_a(&data);
	}

	for (int i = 0; i != 0; i++)
	{
		//print_stack(&data.a);
		//print_stack(&data.b);
		push_b(&data);
	}
	for (int i = 0; i != 0; i++)
	{
		//print_stack(&data.a);
		print_stack(&data.b);
		r_rotate_b(&data);
	}
	//print_stack(&data.a);
	print_stack(&data.b);
	free_data(&data);
	return (1);
}
