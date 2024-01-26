#include "push_swap.h"

bool	value_is_max(int value, int *tab, stack *b)
{
	int	i;
	int size;

	i = b->bottom;

	while (i != b->top && value > tab[i])
		i = index_up(b, i);	
	
	if (i == b->top && value > tab[i])
		return (true);
	return(false);
}

int	index_max(stack *stck)
{
	int i;
	int	index;

	i = stck->bottom;
	index = stck->bottom;

	while (i != stck->top)
	{
		if (i != index && stck->values[i] > stck->values[index])
			index = i;
		i = index_up(stck, i);
	}
	if (i != index && stck->values[i] > stck->values[index])
			index = i;
	return (index);
}

bool	value_is_min(int value, int *tab, stack *b)
{
	int	i;
	int size;

	i = b->bottom;

	while (i != b->top && value < tab[i])
		i = index_up(b, i);	
	
	if (i == b->top && value < tab[i])
		return (true);
	return(false);
}

int	index_min(stack *stck)
{
	int i;
	int	index;

	i = stck->bottom;
	index = stck->bottom;

	while (i != stck->top)
	{
		if (stck->values[i] < stck->values[index])
			index = i;
		i = index_up(stck, i);
	}
	if (stck->values[i] < stck->values[index])
			index = i;
	return (index_down(stck, index));
}

int locate_index(int value, int *tab, stack *b)
{
	int	i;

	i = b->bottom;

	while (i != b->top)
	{
		if (value > tab[i] && value < tab[index_up(b, i)])
			return (i);
		i = index_up(b, i);
	}
	if (value > tab[i] && value < tab[b->bottom])
			return (i);
	return (-1);
}

int	find_index(int value, int *tab, stack *b)
{
	if (value_is_max(value, tab, b))
		return(index_max(b));
	if (value_is_min(value, tab, b))
		return(index_min(b));
	return(locate_index(value, tab, b));
}

int	count_operations(p_s data, int index_src, int index_dst)
{
	int count;
	int i;
	int j;

	count = 0;
	j = data.a.top;
	i = data.b.top;
	/*ft_printf("src; %d\n", index_src);
	ft_printf("dst; %d\n", index_dst);
	ft_printf("val; %d\n", data->a.values[index_src]);
	print_stack(&data->a);
	print_stack(&data->b);*/

	while (j != index_src && i != index_dst)
	{
		j = index_down(&data.a, j);
		i = index_down(&data.b, i);
		count++;
	}
	while (j != index_src)
	{
		j = index_down(&data.a, j);
		count++;
	}
	while (i != index_dst)
	{
		i = index_down(&data.b, i);
		count++;
	}
	count++;
	return(count);
}

int	optimization_index_src(p_s data, stack src, stack dst)
{
	int	index_opti;
	int	index_src;
	int	index_dst;
	int	operations;
	int operations_min;

	int	x;

	index_src = src.top;
	index_opti = src.top;
	operations = 420;
	operations_min = 420;
	x = 0;

	while (x < operations)
	{
		index_dst = find_index(src.values[index_src], dst.values, &dst);
		operations = count_operations(data, index_src, index_dst);

		if (operations < operations_min)
		{
			operations_min = operations;
			index_opti = index_src;
		}
		index_src = index_down(&src, index_src);
		x++;
	}
	return(index_opti);
}

void	sort_one_hundred(p_s *data, stack *a, stack *b)
{
	int index_dst;
	int index_src;

	while (b->num_entries != 3)
		push_b(data);	
	sort_three_b(data, b);

	while (a->num_entries != 3)
	{
		//index_src = a->top;
		index_src = optimization_index_src(*data, *a, *b);
		
		index_dst = find_index(a->values[index_src], b->values, b);
		/*ft_printf("ind_s; %d  val_s %d\n", index_src, a->values[index_src]);
		ft_printf("ind_d; %d  val_d %d\n", index_dst, b->values[index_dst]);
		print_stack(a);
		print_stack(b);*/
		//printf("op; %d\n", count_operations(*data, index_src, index_dst));
		push_to_index(data, a, b, index_src, index_dst);
		
	}
	sort_three_a(data, a);
}	