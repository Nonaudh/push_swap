#include "push_swap.h"

void	sort_three_a(p_s *data, stack *a)
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

void	sort_three_b(p_s *data, stack *b)
{
	int first;
	int	second;
	int third;

	first = b->values[b->top];
	second = b->values[index_down(b, b->top)];
	third = b->values[b->bottom];

	if (first < second && second < third && first < third)
	{
		swap_b(data);
		r_rotate_b(data);
	}
	else if (first > second && second < third && first > third)
    {
		r_rotate_b(data);
        swap_b(data);
    }
    else if (first < second && second > third && first < third)
		rotate_b(data);
	else if (first > second && second < third && first < third)
		r_rotate_b(data);
	else if (first < second && second > third && first > third)
		swap_b(data);
}