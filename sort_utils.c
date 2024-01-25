#include "push_swap.h"

bool	is_a_sorted(stack *a)
{
	int	i;
	int lenght;

	i = a->bottom;

	while (i != index_down(a, a->bottom) && a->values[i] > a->values[index_up(a, i)])
	{
		i = index_up(a, i);
	}
	if (i == index_down(a, a->bottom))
		return(true);
	return(false);
}
