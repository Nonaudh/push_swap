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

	min = value_min(b);
	if (min > value)
		return(value_max(b));
	max = value_max(b);
	if (max < value)
		return(max);
	return(value_location_b(b, b->values, value));
}

void	align_dst_and_src(p_s *data, stack *a, stack *b, int value_src, int value_dst)
{
	int	strategy;

	strategy = define_strategy(a, b, value_src, value_dst, 2);
	//printf("strat; %d\n", strategy);

	if (strategy == 1)
		ex_first_strategy(data, a, b, value_src, value_dst);
	if (strategy == 2)
		ex_second_strategy(data, a, b, value_src, value_dst);
	/**/if (strategy == 3)
		ex_third_strategy(data, a, b, value_src, value_dst);
	if (strategy == 4)
		ex_fourth_strategy(data, a, b, value_src, value_dst);/**/
}

int	count_operations(p_s *data, stack *b, int value_src)
{
	int	value_dst;

	value_dst = find_value_dst(b, value_src);
	return (define_strategy(&data->a, b, value_src, value_dst, 1));
}

int	optimisation(p_s *data, stack *a, stack *b)
{
	int index;
	int count_min;
	int current_count;
	int x;
	int	value_opti;

	index = a->top;
	count_min = INT_MAX;
	x = 0;

	while (x < count_min && index != a->bottom)
	{
		current_count = count_operations(data, b, a->values[index]);
		if (count_min > current_count)
		{
			count_min = current_count;
			value_opti = a->values[index];
		}
		index = index_down(a, index);
		x++;
	}
	/**/index = a->bottom;
	x = 0;
	while (x < count_min && index != a->top)
	{
		current_count = count_operations(data, b, a->values[index]);
		if (count_min > current_count)
		{
			count_min = current_count;
			value_opti = a->values[index];
		}
		index = index_up(a, index);
		x++;
	}/**/
	return (value_opti);
}

void    push_to_b(p_s *data, stack *a, stack *b)
{
	int	value_src;
	int	value_dst;

	value_src = optimisation(data, a, b);
	value_dst = find_value_dst(b, value_src);
	//printf("src;  %d  dst;  %d\n", value_src, value_dst);
	align_dst_and_src(data, a, b, value_src, value_dst);
	//print_stack(a);
	push_b(data);
	//print_stack(b);
}

void	sort_hundred(p_s *data, stack *a, stack *b)
{
	while (b->num_entries != 3)
		push_b(data);
	sort_three_b(data, b);

	while (a->num_entries != 3)
		push_to_b(data, a, b);
	sort_three_a(data, a);

	final_push(data, a, b);
}	