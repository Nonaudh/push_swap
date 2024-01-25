#include "push_swap.h"

bool rotate_is_more_eficient(stack *stck, int index)
{
    int i;
    int x;

    i = stck->top;
    x = 0;

    while(x < (stck->num_entries / 2) && i != index)
    {
        x++;
        i = index_down(stck, i);
        //ft_printf("i; %d\n", i);
        //ft_printf("ind; %d\n", index);
    }
    if (i == index)
        return(true);
    return(false);
}

void    push_to_index(p_s *data, stack *b, int *tab, int index)
{
   /* if (rotate_is_more_eficient(b, index))
    {
        while (b->top != index)
            rotate_b(data);
    }
    else
    {
        while (b->top != index)
            r_rotate_b(data);
    }*/
        while (b->top != index)
           rotate_b(data);

    //print_stack(&data->a);
    //print_stack(b);
    push_b(data);
}