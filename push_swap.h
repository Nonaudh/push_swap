#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/libft/libft.h"
#include "lib/ft_printf/ft_printf.h"

typedef struct s_stack
{
    int *values;
    int bottom;
    int top;
    int size;
} stack;

typedef struct push_swap
{
    stack a;
    stack b;
} p_s;


#include <stdio.h> /////////


#endif
