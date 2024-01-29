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

void	check_values(p_s *data, stack *a, int size, char **argv)
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

void	init_stack(stack *stck, int size)
{
	stck->values = malloc(sizeof(int) * size);
	if (!stck->values)
		exit(EXIT_FAILURE);
	stck->bottom = 0;
	stck->top = 0;
	stck->size = size;
	stck->num_entries = 0;
}

void	init_data(p_s *data, int argc, char **argv)
{
	
	init_stack(&data->a, argc);
	init_stack(&data->b, argc);
	check_values(data, &data->a, argc, argv);
}

int	main(int argc, char **argv)
{
	p_s		data;

	if (argc == 2)
	{
		argc = count_arg(argv[1], ' ');
		data.tab = ft_split(argv[1], ' ');
		if (!data.tab)
			exit(EXIT_FAILURE);
		data.tab_to_free = true;
		init_data(&data, argc, data.tab);
		sort(&data);
		free_data(&data);
	}
	else
	{
		argc--;
		argv++;
		data.tab_to_free = false;
		init_data(&data, argc, argv);
		sort(&data);
		free_data(&data);
	}
	exit(EXIT_SUCCESS);
}