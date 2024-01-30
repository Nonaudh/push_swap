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

int	value_location_a(stack *a, int value_src)
{
	int	i;

	i = a->bottom;
	if (value_src < a->values[a->top] && value_src > a->values[i])
			return (a->values[a->top]);
	while (i != a->top)
	{
		if (value_src < a->values[i] && value_src > a->values[index_up(a, i)])
			return (a->values[i]);
		i = index_up(a, i);
	}
	exit(EXIT_FAILURE);
}

void	push_to_a(p_s *data, stack *a, int value_src)
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
		value_dst = value_location_a(a, value_src);
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
		push_to_a(data, a, b->values[b->top]);
	last_rotation_a(data, a);
}