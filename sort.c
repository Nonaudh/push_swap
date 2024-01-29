#include "push_swap.h"

void	sort_five(p_s *data, stack *a)
{
    while (a->num_entries != 3)
    {
        if (a->values[a->top] == 1 || a->values[a->top] == 2)
            push_b(data);
        
        else
            rotate_a(data);
    }
    sort_three(data, a); 
    while (!stack_full(a))
        push_a(data);
    if (a->values[a->top] > a->values[index_down(a, a->top)])
        swap_a(data);
}

void	sort_three(p_s *data, stack *a)
{
	int first;
	int	second;
	int third;

	first = a->values[a->top];
	second = a->values[index_down(a, a->top)];
	third = a->values[a->bottom];
	if (first > second && second > third && first > third)
	{
		swap_a(data);
		r_rotate_a(data);
	}
	else if (first < second && second > third && first < third)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (first > second && second < third && first < third)
		swap_a(data);
	else if (first > second && second < third && first > third)
		rotate_a(data);
	else if (first < second && second > third && first > third)
		r_rotate_a(data);
}

void    sort_two(p_s *data, stack *a)
{
    if (a->values[a->top] > a->values[index_down(a, a->top)])
        swap_a(data);
}

void	sort(p_s *data)
{
	if(is_stack_sorted(&data->a))
		return ;
	if (data->a.size == 2)
		sort_two(data, &data->a);
	if (data->a.size == 3)
		sort_three(data, &data->a);
	if (data->a.size == 5 || data->a.size == 4)
		sort_five(data, &data->a);
	if (data->a.size > 5)
		sort_hundred(data, &data->a, &data->b);
}
