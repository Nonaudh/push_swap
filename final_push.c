#include "push_swap.h"

void	last_rotation_a(p_s *data, stack *a)
{
	int	strategy;
	int	min;

	min = find_min_value(a);
	strategy = strategy_b_to_a(a, min);
	while (a->values[a->top] != min)
	{
		if (strategy == STRAT_1)
			rotate_a(data);
		if (strategy == STRAT_2)
			r_rotate_a(data);
	}
}

int strategy_b_to_a(stack *a, int value_dst)
{
	int	i;
	int count_1;
	int count_2;

	i = a->top;
	count_1 = 0;
	count_2 = 1;
	while (a->values[i] != value_dst)
	{
		count_1++;
		i = index_down(a, i);
	}
	i = a->bottom;
	while (a->values[i] != value_dst)
	{
		count_2++;
		i = index_up(a, i);
	}
	if (count_1 <= count_2)
		return (STRAT_1);
	return (STRAT_2);
}

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
	exit(EXIT_FAILURE);
}

void	push_to_a(p_s *data, stack *a, int *tab_a, int value_src)
{
	int	min;
	int	max;
	int	value_dst;
	int strategy;

	min = find_min_value(a);
	max = find_max_value(a);
	if (min > value_src || max < value_src)
		value_dst = min;
	else
		value_dst = value_location_a(a, tab_a, value_src);
	strategy = strategy_b_to_a(a, value_dst);
	while (a->values[a->top] != value_dst)
	{
		if (strategy == STRAT_1)
			rotate_a(data);
		if (strategy == STRAT_2)
			r_rotate_a(data);
	}
	push_a(data);
}

void    final_push(p_s *data, stack *a, stack *b)
{
	while (b->num_entries != 0)
		push_to_a(data, a, a->values, b->values[b->top]);
	last_rotation_a(data, a);
}