#include "push_swap.h"

void	rotate(stack *stck)
{
	int	tmp;

	if (stack_full(stck))
	{
		stck->top = index_up(stck, stck->top);
		stck->bottom = index_up(stck, stck->bottom);
	}
	else
	{
		tmp = stck->values[stck->top];
		stck->top = index_up(stck, stck->top);
		stck->bottom = index_up(stck, stck->bottom);
		stck->values[stck->bottom] = tmp;
	}
}

void	rotate_a(p_s *data)
{
	rotate(&data->a);
	ft_printf("ra\n");
}

void	rotate_b(p_s *data)
{
	rotate(&data->b);
	ft_printf("rb\n");
}

void	rotate_ab(p_s *data)
{
	rotate(&data->a);
	rotate(&data->b);
	ft_printf("rr\n");
}