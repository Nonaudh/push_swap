#include "push_swap.h"

void	swap(stack *stck)
{
	int tmp;

	tmp = 0;
	if (stck->num_entries <= 1)
		return ;

	tmp = stck->values[stck->top];
	stck->values[stck->top] = stck->values[index_down(stck, stck->top)];
	stck->values[index_down(stck, stck->top)] = tmp;
}

void	swap_a(p_s *data)
{
	swap(&data->a);
	ft_printf("sa\n");
}

void	swap_b(p_s *data)
{
	swap(&data->b);
	ft_printf("sb\n");
}

void	swap_ab(p_s *data)
{
	swap(&data->a);
	swap(&data->b);
	ft_printf("ss\n");
}