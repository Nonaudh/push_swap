#include "push_swap.h"

int	index_up(stack *stck, int index)
{
	if (index == stck->size - 1)
		return (0);
	
	return (index + 1);
}

int	index_down(stack *stck, int index)
{
	if (index == 0)
		return (stck->size - 1);

	return (index - 1);
}

void	error(p_s *data)
{
	free_data(data);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_data(p_s *data)
{
	free(data->a.values);
	free(data->b.values);
}

bool	stack_empty(stack *a)
{
	return (a->num_entries == 0);
}

bool	stack_full(stack *a)
{
	return (a->num_entries == a->size);
}

void	print_stack(stack *stck)
{
	int	i = 0;
	int	j = stck->bottom;

	while (i != stck->num_entries)
	{
		ft_printf("%d  ", stck->values[j]);
		j = index_up(stck, j);
		i++;
	}
	ft_printf("\n");
	//ft_printf("bot; %d  ", stck->bottom);
	//ft_printf("top; %d\n", stck->top);
	//ft_printf("num; %d\n", stck->num_entries);
}