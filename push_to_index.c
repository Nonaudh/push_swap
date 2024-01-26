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

void    push_to_index(p_s *data, stack *src, stack *dst, int index_src, int index_dst)
{
        /*while (src->top != index_src && dst->top != index_dst)
         {
            rotate_ab(data);
         }*/ 

       // print_stack(&data->a);
		//print_stack(&data->b);

        while (src->top != index_src)
            rotate_a(data);

       // printf("dst; %d\n", index_dst);
       // printf("val; %d\n", src->values[index_src]);
        while (dst->top != index_dst)
        {
           rotate_b(data);
          // sleep(1);
        }
    if (src->top == index_src && dst->top == index_dst)
    {
        print_stack(&data->a);
		print_stack(&data->b);
        push_b(data);
    }
    else
        error(data);
}