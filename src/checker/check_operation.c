#include "../../inc/checker.h"

void	check_swap(t_ps *data, char *op)
{
	if (op[1] == 'a' && op[2] == '\n')
	{
		swap(&data->a);
		return ;
	}
	if (op[1] == 'b' && op[2] == '\n')
	{
		swap(&data->b);
		return ;
	}
	if (op[1] == 's' && op[2] == '\n')
	{
		swap(&data->a);
		swap(&data->b);
		return ;
	}
	free(op);
	error(data);
}

void	check_push(t_ps *data, char *op)
{
	if (op[1] == 'a' && op[2] == '\n')
	{
		push(&data->b, &data->a);
		return ;
	}

	if (op[1] == 'b' && op[2] == '\n')
	{
		push(&data->a, &data->b);
		return ;
	}
	free(op);
	error(data);
}

void	check_rotate(t_ps *data, char *op)
{
	if (op[1] == 'a' && op[2] == '\n')
	{
		rotate(&data->a);
		return ;
	}
		
	if (op[1] == 'b' && op[2] == '\n')
	{
		rotate(&data->b);
		return ;
	}
		
	if (op[1] == 'r' && op[2] == '\n')
	{
		rotate(&data->a);
		rotate(&data->b);
		return ;
	}
	free(op);
	error(data);
}

void	check_reverse_rotate(t_ps *data, char *op)
{
	if (op[2] == 'a' && op[3] == '\n')
	{
		reverse_rotate(&data->a);
		return ;
	}
		
	if (op[2] == 'b' && op[3] == '\n')
	{
		reverse_rotate(&data->b);
		return ;
	}
		
	if (op[2] == 'r' && op[3] == '\n')
	{
		reverse_rotate(&data->a);
		reverse_rotate(&data->b);
		return ;
	}
	free(op);
	error(data);
}
