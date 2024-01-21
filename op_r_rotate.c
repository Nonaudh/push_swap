#include "push_swap.h"

void	reverse_rotate(stack *stck)
{
	int	tmp;

	if (stack_full(stck))
	{
		stck->bottom = index_up(stck, stck->bottom);
		stck->top = index_up(stck, stck->top);
	}
	else
	{
		tmp = stck->values[stck->bottom];
        stck->bottom = index_up(stck, stck->bottom);
		stck->top = index_up(stck, stck->top);
		stck->values[stck->top] = tmp;
	}
}

void	r_rotate_a(p_s *data)
{
	reverse_rotate(&data->a);
	ft_printf("rra\n");
}

void	r_rotate_b(p_s *data)
{
	reverse_rotate(&data->b);
	ft_printf("rrb\n");
}

void	r_rotate_ab(p_s *data)
{
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
	ft_printf("rrr\n");
}