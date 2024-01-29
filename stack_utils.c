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

bool	stack_empty(stack *a)
{
	return (a->num_entries == 0);
}

bool	stack_full(stack *a)
{
	return (a->num_entries == a->size);
}

int	count_arg(char *arg, char c)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] != c && (arg[i + 1] == c || arg[i + 1] == '\0'))
			x++;
		i++;
	}
	return (x);
}
