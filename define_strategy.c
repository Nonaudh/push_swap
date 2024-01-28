#include "push_swap.h"

int first_strategy(stack *a, stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->top;
	j = b->top;
	count = 1;

	while (a->values[i] != value_src && b->values[j] != value_dst)
	{
		i = index_down(a, i);
		j= index_down(b, j);
		count++;
	}
	while (a->values[i] != value_src)
	{
		i = index_down(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_down(a, j);
		count++;
	}
	return (count);
}

int second_strategy(stack *a, stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->top;
	j = b->bottom;
	count = 2;

	while (a->values[i] != value_src)
	{
		i = index_down(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_up(a, j);
		count++;
	}
	return (count);
}

int third_strategy(stack *a, stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->bottom;
	j = b->top;
	count = 2;

	while (a->values[i] != value_src)
	{
		i = index_up(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_down(a, j);
		count++;
	}
	return (count);

}

int fourth_strategy(stack *a, stack *b, int value_src, int value_dst)
{
	int	i;
	int	j;
	int	count;

	i = a->bottom;
	j = b->bottom;
	count = 3;

	while (a->values[i] != value_src && b->values[j] != value_dst)
	{
		i = index_up(a, i);
		j= index_up(b, j);
		count++;
	}
	while (a->values[i] != value_src)
	{
		i = index_up(a, i);
		count++;
	}
	while (b->values[j] != value_dst)
	{
		j = index_up(a, j);
		count++;
	}
	return (count);
	
}

int	define_strategy(stack *a, stack *b, int value_src, int value_dst, int mode)
{
	int	count[4];

	count[0] = first_strategy(a, b, value_src, value_dst);
	count[1] = second_strategy(a, b, value_src, value_dst);
	count[2] = third_strategy(a, b, value_src, value_dst);
	count[3] = fourth_strategy(a, b, value_src, value_dst);
	if (mode == COUNT)
		return (less_move(count));

	if (mode == STRAT)
		return (best_strat(count));
	return (0);
}