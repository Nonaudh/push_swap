#include "push_swap.h"
/*
bool	stack_empty(stack *a)
{
	return (a->num_entries == 0);
}

bool	stack_full(stack *a)
{
	return (a->num_entries == a->size);
}

void	free_the_stack(stack *a)
{
	free(a->values);
}

bool	fill_the_stack(stack *a, int *tab)
{
	
}


*/

void	print_stack(stack *stck)
{
	int i = stck->top;

	while (i != stck->bottom)
	{
		ft_printf("%d  ", stck->values[i]);
		i = (i + 1) % stck->size;
	}
	ft_printf("%d\n", stck->values[i]);
}

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

void	check_duplicate(int *tab, int size)
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
				exit(EXIT_FAILURE);
			j++;
		}
	i++;
	}
}

void	check_valid_arg(char *arg)
{
	int	i;
	long	nb;

	i = 0;
	while (arg[i] <= 32)
		i++;
	
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			exit(EXIT_FAILURE);
		nb = nb * 10 + arg[i] + 48;
		i++;
	}

	//if (nb < INT_MIN || nb > INT_MAX)
		//exit(EXIT_FAILURE);
}

void	fill_the_stack(p_s *data, stack *a, int size, char *argv[])
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);

	while (argv[i])
	{
		check_valid_arg(argv[i]);
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	check_duplicate(tab, size);
	simplify_and_stack(tab, a->values, size);
	a->bottom = size - 1;

	print_stack(a);
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
	return (1);
}
