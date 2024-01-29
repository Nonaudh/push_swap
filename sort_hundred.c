#include "push_swap.h"


int	value_location_b(stack *b, int *tab_b, int value)
{
	int	i;
	int	x;

	i = b->bottom;
	x = 0;
	if (value > tab_b[b->top] && value < tab_b[i])
			return (tab_b[b->top]);
	while (x != ((b->num_entries) - 1))
	{
		if (value > tab_b[i] && value < tab_b[index_up(b, i)])
			return (tab_b[i]);
		i = index_up(b, i);
		x++;
	}
	return (-1);
}

int	find_value_dst(stack *b, int value)
{
	int	min;
	int	max;

	min = find_min_value(b);
	max = find_max_value(b);
	if (min > value || max < value)
		return(max);
	return(value_location_b(b, b->values, value));
}

void    push_to_b(p_s *data, stack *a, stack *b)
{
	int	value_src;
	int	value_dst;

	value_src = find_value_opti(data, a, b);
	value_dst = find_value_dst(b, value_src);
	align_dst_and_src(data, a, b, value_src, value_dst);
	push_b(data);
}

void	sort_hundred(p_s *data, stack *a, stack *b)
{
	while (b->num_entries != 2)
		push_b(data);
	while (a->num_entries != 3)
		push_to_b(data, a, b);
	sort_three(data, a);

	final_push(data, a, b);
}	