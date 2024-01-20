#include "push_swap.h"

void	swap(stack *stck)
{
	int tmp;

	tmp = 0;
	if (stck->num_entries <= 1)
		return ;

	tmp = stck->values[stck->top];
	stck->values[stck->top] = stck->values[index_up(stck, stck->top)];
	stck->values[index_up(stck, stck->top)] = tmp;
}

void	swap_a(stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	swap_ab(stack *a, stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}