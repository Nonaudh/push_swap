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
	while (i < 4)
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
	while (i < 4)
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

int value_max(stack *stck)
{
	int i;
	int x;
	int max;

	i = stck->bottom;
	x = 0;
	max = 0;
	while (x != stck->num_entries)
	{
		if (stck->values[i] > max)
			max = stck->values[i];
		i = index_up(stck, i);
		x++;
	}
	return(max);
}

int	value_min(stack *stck)
{
	int	i;
	int	x;
	int	min;

	i = stck->bottom;
	x = 0;
	min = INT_MAX;
	while (x != stck->num_entries)
	{
		if (stck->values[i] < min)
			min = stck->values[i];
		i = index_up(stck, i);
		x++;
	}
	return(min);
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

void	free_the_tab(char **tab, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
