#include "push_swap.h"

void	ex_first_strategy(p_s *data, stack *a, stack *b, int value_src, int value_dst)
{
	while (a->values[a->top] != value_src && b->values[b->top] != value_dst)
		rotate_ab(data);
	while (a->values[a->top] != value_src)
		rotate_a(data);
	while (b->values[b->top] != value_dst)
		rotate_b(data);
}

void	ex_second_strategy(p_s *data, stack *a, stack *b, int value_src, int value_dst)
{
	while (a->values[a->top] != value_src)
		rotate_a(data);
	while (b->values[b->top] != value_dst)
		r_rotate_b(data);
}

void	ex_third_strategy(p_s *data, stack *a, stack *b, int value_src, int value_dst)
{
	while (a->values[a->top] != value_src)
		r_rotate_a(data);
	while (b->values[b->top] != value_dst)
		rotate_b(data);
}

void	ex_fourth_strategy(p_s *data, stack *a, stack *b, int value_src, int value_dst)
{
	while (a->values[a->top] != value_src && b->values[b->top] != value_dst)
		r_rotate_ab(data);
	while (a->values[a->top] != value_src)
		r_rotate_a(data);
	while (b->values[b->top] != value_dst)
		r_rotate_b(data);
}
