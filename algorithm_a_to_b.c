#include "push_swap.h"

int	define_strategy(stack *a, stack *b, int value_src, int value_dst, int mode)
{
	int	count[4];

	count[0] = first_strategy(a, b, value_src, value_dst);
	count[1] = second_strategy(a, b, value_src, value_dst);
	count[2] = third_strategy(a, b, value_src, value_dst);
	count[3] = fourth_strategy(a, b, value_src, value_dst);
	if (mode == COUNT)
		return (minimum_operations(count));

	if (mode == STRAT)
		return (best_strategy(count));
	return (0);
}

void	align_a_and_b(p_s *data, stack *a, stack *b, int value_src, int value_dst)
{
	int	strategy;

	strategy = define_strategy(a, b, value_src, value_dst, STRAT);
	if (strategy == STRAT_1)
		ex_first_strategy(data, a, b, value_src, value_dst);
	if (strategy == STRAT_2)
		ex_second_strategy(data, a, b, value_src, value_dst);
	if (strategy == STRAT_3)
		ex_third_strategy(data, a, b, value_src, value_dst);
	if (strategy == STRAT_4)
		ex_fourth_strategy(data, a, b, value_src, value_dst);
}

int	count_operations(p_s *data, stack *b, int value_src)
{
	int	value_dst;

	value_dst = find_value_dst(b, value_src);
	return (define_strategy(&data->a, b, value_src, value_dst, COUNT));
}

int	find_value_opti(p_s *data, stack *a, stack *b)
{
	int 	index;
	int 	count_min;
	int		current_count;
	int 	x;
	int		value_opti;
	bool	from_top;

	index = a->top;
	count_min = INT_MAX;
	x = 0;
	from_top = true;

	while (x < count_min && x != a->num_entries)
		{
			current_count = count_operations(data, b, a->values[index]);
			if (count_min > current_count)
			{
				count_min = current_count;
				value_opti = a->values[index];
			}
			if(from_top)
				index = index_down(a, index);
			else
				index= index_up(a, index);
			x++;
			if ((x == count_min || x == a->num_entries) && from_top)
			{
				index = a->bottom;
				from_top = false;
				x = 0;
			}
		}
	return (value_opti);
}