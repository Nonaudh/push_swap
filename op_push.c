#include "push_swap.h"

void	push(stack *src, stack *dst)
{
	if(stack_empty(src))
		return ;

	if (!stack_empty(dst))
		dst->top = index_up(dst, dst->top);
	
	dst->values[dst->top] = src->values[src->top];
	
	src->top = index_down(src, src->top);
	src->num_entries--;
	dst->num_entries++;

	if (stack_empty(src))
	{
		src->bottom = 0;
		src->top = 0;
	}
}

void	push_a(p_s *data)
{
	push(&data->b, &data->a);
	ft_printf("pa\n");
}

void	push_b(p_s *data)
{
	push(&data->a, &data->b);
	ft_printf("pb\n");
}