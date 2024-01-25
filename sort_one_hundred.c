#include "push_swap.h"

bool	value_is_max(int value, int *tab, stack *b)
{
	int	i;
	int size;

	i = b->bottom;

	while (i != b->top && value > tab[i])
		i = index_up(b, i);	
	
	if (i == b->top && value > tab[i])
		return (true);
	return(false);
}

int	index_max(stack *stck)
{
	int i;
	int	index;

	i = stck->bottom;
	index = stck->bottom;

	while (i != stck->top)
	{
		if (i != index && stck->values[i] > stck->values[index])
			index = i;
		i = index_up(stck, i);
	}
	if (i != index && stck->values[i] > stck->values[index])
			index = i;
	return (index);
}

bool	value_is_min(int value, int *tab, stack *b)
{
	int	i;
	int size;

	i = b->bottom;

	while (i != b->top && value < tab[i])
		i = index_up(b, i);	
	
	if (i == b->top && value < tab[i])
		return (true);
	return(false);
}

int	index_min(stack *stck)
{
	int i;
	int	index;

	i = stck->bottom;
	index = stck->bottom;

	while (i != stck->top)
	{
		if (i != index && stck->values[i] < stck->values[index])
			index = index_down(stck, i);
		i = index_up(stck, i);
	}
	if (i != index && stck->values[i] < stck->values[index])
			index = index_down(stck, i);
	return (index_down(stck, index));
}

int locate_index(int value, int *tab, stack *b)
{
	int	i;

	i = b->bottom;

	while (i != b->top)
	{
		if (value > tab[i] && value < tab[index_up(b, i)])
			return (i);
		i = index_up(b, i);
	}
	if (value > tab[i] && value < tab[index_up(b, i)])
			return (i);
	return (-1);
}

int	find_index(int value, int *tab, stack *b)
{
	if (value_is_max(value, tab, b))
		return(index_max(b));
	if (value_is_min(value, tab, b))
		return(index_min(b));
	return(locate_index(value, tab, b));
}

void	sort_one_hundred(p_s *data, stack *a, stack *b)
{
	int index;

	while (b->num_entries != 3)
		push_b(data);	
	sort_three_b(data, b);
	//rotate_b(data);

	while (a->num_entries != 3)
	{
		index = find_index(a->values[a->top], b->values, b);
		push_to_index(data, b, b->values, index);	
	}
}	