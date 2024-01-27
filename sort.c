#include "push_swap.h"

void	sort(p_s *data)
{
	if(is_a_sorted(&data->a))
		return ;
	if (data->a.size == 2)
		sort_two(data, &data->a);
	if (data->a.size == 3)
		sort_three_a(data, &data->a);
	if (data->a.size == 5 || data->a.size == 4)
		sort_five(data, &data->a);
	if (data->a.size > 5)
		sort_hundred(data, &data->a, &data->b);
	
}
