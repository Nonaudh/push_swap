/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:00:22 by ahuge             #+#    #+#             */
/*   Updated: 2024/01/31 13:00:25 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ex_first_strategy(t_stack *a, t_stack *b, int val_src, int val_dst)
{
	while (a->values[a->top] != val_src && b->values[b->top] != val_dst)
		rotate_ab(a, b);
	while (a->values[a->top] != val_src)
		rotate_a(a);
	while (b->values[b->top] != val_dst)
		rotate_b(b);
}

void	ex_second_strategy(t_stack *a, t_stack *b, int val_src, int val_dst)
{
	while (a->values[a->top] != val_src)
		rotate_a(a);
	while (b->values[b->top] != val_dst)
		r_rotate_b(b);
}

void	ex_third_strategy(t_stack *a, t_stack *b, int val_src, int val_dst)
{
	while (a->values[a->top] != val_src)
		r_rotate_a(a);
	while (b->values[b->top] != val_dst)
		rotate_b(b);
}

void	ex_fourth_strategy(t_stack *a, t_stack *b, int val_src, int val_dst)
{
	while (a->values[a->top] != val_src && b->values[b->top] != val_dst)
		r_rotate_ab(a, b);
	while (a->values[a->top] != val_src)
		r_rotate_a(a);
	while (b->values[b->top] != val_dst)
		r_rotate_b(b);
}
