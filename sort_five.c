#include "push_swap.h"

void	sort_five(p_s *data, stack *a, stack *b)
{
    while (a->num_entries != 3)
    {
        if (a->values[a->top] == 1 || a->values[a->top] == 2)
            push_b(data);
        
        else
            rotate_a(data);
    }
    sort_three_a(data, a); 
    while (!stack_full(a))
        push_a(data);
    if (a->values[a->top] > a->values[index_down(a, a->top)])
        swap_a(data);
}

void    sort_two(p_s *data, stack *a)
{
    if (a->values[a->top] > a->values[index_down(a, a->top)])
        swap_a(data);
}