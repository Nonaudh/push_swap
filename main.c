#include "push_swap.h"

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
	free(a->tab);
}

bool	fill_the_stack(stack *a, int value)
{
	if (stack_full(a))
		return (false);
	
	a->tab[a->top] = value;
	a->num_entries++;
	a->top = (a->top + 1) % a->size;

	return (true);
}

void	init_stack(stack *a, int buff_size)
{
	a->size = buff_size;
	a->tab = malloc(sizeof(int) * a->size);
	a->top = 0;
	a->bottom = 0;
	a->num_entries = 0;
}

void	print_stack(stack *a)
{
	int i = 1;

	while (a->num_entries - i > -1)
	{
		ft_printf("%d\n", a->tab[a->num_entries - i]);
		i++;
	}
	printf("num; %d\n", a->num_entries);
	printf("size; %d\n", a->size);
	printf("top; %d\n", a->top);
	printf("bott; %d\n", a->bottom);
}

int	*fill_the_tab(int *tab, int argc, char *argv[])
{
	int i;

	i = 0;
	tab = malloc(sizeof(int) * (argc - 1));

	while (i < argc - 1)
	{
		tab[i] = ft_atoi(argv[argc - 1 - i]);
		i++;
	}
	return (tab);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	int *tab = NULL;
	stack	a;
	stack	b;

	if (argc > 1)
	{
		tab = fill_the_tab(tab, argc, argv);

		init_stack(&a, argc - 1);
		init_stack(&b, argc - 1);

		while (i < argc - 1)
		{
			fill_the_stack(&a, tab[i]);
			i++;
		}
		free (tab);
		print_stack(&a);
		print_stack(&b);
	}
	return (1);
}
