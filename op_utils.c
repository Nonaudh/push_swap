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