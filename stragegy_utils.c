#include "push_swap.h"

int numbers_of_operations(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	count[STRATS];

	count[0] = first_strategy(a, b, value_src, value_dst);
	count[1] = second_strategy(a, b, value_src, value_dst);
	count[2] = third_strategy(a, b, value_src, value_dst);
	count[3] = fourth_strategy(a, b, value_src, value_dst);
	return (minimum_operations(count, STRATS));

}

int	define_strategy(t_stack *a, t_stack *b, int value_src, int value_dst)
{
	int	count[STRATS];

	count[0] = first_strategy(a, b, value_src, value_dst);
	count[1] = second_strategy(a, b, value_src, value_dst);
	count[2] = third_strategy(a, b, value_src, value_dst);
	count[3] = fourth_strategy(a, b, value_src, value_dst);
	return (best_strategy(count, STRATS));
}

int	minimum_operations(int *count, int size)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 0;
	while (i < size)
	{
		if (count[i] < min)
			min = count[i];
		i++;
	}
	return (min);
}

int	best_strategy(int *count, int size)
{
	int	min;
	int	strat;
	int	i;

	min = INT_MAX;
	i = 0;
	strat = 1;
	while (i < size)
	{
		if (count[i] < min)
		{
			strat = (i + 1);
			min = count[i];
		}
		i++;
	}
	return (strat);
}