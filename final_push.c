#include "push_swap.h"

int	value_location_a(stack *a, int *tab_a, int value_src)
{
	int	i;
	int	x;

	i = a->bottom;
	x = 0;

	if (value_src < tab_a[a->top] && value_src > tab_a[i])
			return (tab_a[a->top]);
	while (x != (a->num_entries))
	{
		if (value_src < tab_a[i] && value_src > tab_a[index_up(a, i)])
			return (tab_a[i]);
		i = index_up(a, i);
		x++;
	}
	return (-1);
}

int	locate_value_a(stack *a, int *tab_a, int value_src)
{
	int	min;
	int	max;

	min = value_min(a);
	if (min > value_src)
		return(min);
	max = value_max(a);
	if (max < value_src)
		return(value_min(a));
	return(value_location_a(a, tab_a, value_src));
}

int strategy_b_to_a(stack *a, int value_dst)
{
	int	i;
	int count_1;
	int count_2;

	i = a->top;
	count_1 = 0;
	count_2 = 0;
	while (a->values[i] != value_dst)
	{
		count_1++;
		i = index_down(a, i);
	}
	i = a->bottom;
	count_2++;
	while (a->values[i] != value_dst)
	{
		count_2++;
		i = index_up(a, i);
	}
	if (count_1 <= count_2)
		return (1);
	return (2);
}

void	push_to_a(p_s *data, stack *a, int value_dst)
{
	int strategy;

	strategy = strategy_b_to_a(a, value_dst);

	while (a->values[a->top] != value_dst)
	{
		if (strategy == 1)
			rotate_a(data);
		if (strategy == 2)
			r_rotate_a(data);
	}
	push_a(data);
}

void    align_and_push(p_s *data, stack *a, int value_src)
{
	int value_dst;

	value_dst = locate_value_a(a, a->values, value_src);
	push_to_a(data, a, value_dst);
	
}

void	last_rotation_a(p_s *data, stack *a)
{
	int	strategy;
	int	min;

	min = value_min(a);
	strategy = strategy_b_to_a(a, min);

	while (a->values[a->top] != min)
	{
		if (strategy == 1)
			rotate_a(data);
		if (strategy == 2)
			r_rotate_a(data);
	}
}

void    final_push(p_s *data, stack *a, stack *b)
{
	while (b->num_entries != 0)
		align_and_push(data, a, b->values[b->top]);

	last_rotation_a(data, a);
}