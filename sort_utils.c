#include "push_swap.h"

bool	is_a_sorted(stack *a)
{
	int	i;

	i = a->bottom;
	while (i != index_down(a, a->bottom) && a->values[i] > a->values[index_up(a, i)])
	{
		i = index_up(a, i);
	}
	if (i == index_down(a, a->bottom))
		return(true);
	return(false);
}

int		less_move(int *count)
{
	int min;
	int i;

	min = INT_MAX;
	i = 0;
	while (i < 4) //4)
	{
		if(count[i] < min)
			min = count[i];
		i++;
	}
	return (min);
}

int		best_strat(int *count)
{
	int min;
	int strat;
	int i;

	min = INT_MAX;
	i = 0;
	strat = 1;
	while (i < 4) //4)
	{
		if(count[i] < min)
		{
			strat = (i + 1);
			min = count[i];
		}
		i++;
	}	
	return (strat);
}
