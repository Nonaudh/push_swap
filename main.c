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

void	print_stack(int *tab, int start, int end, int size)
{
	while (end != start)
	{
		ft_printf("%d\n", tab[end]);
		end = (end + 1) % size;
	}
	ft_printf("%d\n", tab[end]);
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

void	*fill_the_stack(p_s *data, stack *a, int size, char *argv[])
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);

	while(argv[i])
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	simplify_and_stack(tab, a->values, size);
	a->bottom = size - 1;

	print_stack(a->values, a->bottom, a->top, a->size);
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
