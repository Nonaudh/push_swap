/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:54:12 by ahuge             #+#    #+#             */
/*   Updated: 2024/02/06 13:54:15 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define TRUE 1
# define FALSE 0
# define STRATS 4

typedef struct s_stack
{
	int	*values;
	int	bottom;
	int	top;
	int	size;
	int	num_entries;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	char	**tab;
}	t_ps;

void	init_data(t_ps *data, int argc, char **argv);
void	init_stack(t_stack *stck, int size);
void	check_values(t_ps *data, t_stack *a, int size, char **argv);

int		count_arg(char *arg, char c);
int		is_stack_sorted(t_stack *a);
int		stack_empty(t_stack *stck);
int		stack_full(t_stack *stck);

void	check_valid_arg(t_ps *data, char *arg, int *tab);
void	check_end_arg(t_ps *data, char *arg, int *tab);
void	check_duplicate(t_ps *data, int *tab, int size);
void	simplify_and_stack(int *tab, int *values, int size);

int		index_down(t_stack *stck, int index);
int		index_up(t_stack *stck, int index);

void	error(t_ps *data);
void	free_data(t_ps *data);
void	free_the_tab(char **tab, int argc);
void	error_arg(t_ps *data, int *tab);
void	no_arg(void);

void	swap(t_stack *stck);
void	push(t_stack *src, t_stack *dst);
void	rotate(t_stack *stck);
void	reverse_rotate(t_stack *stck);

void	check_swap(t_ps *data, char *op);
void	check_push(t_ps *data, char *op);
void	check_rotate(t_ps *data, char *op);
void	check_reverse_rotate(t_ps *data, char *op);

void	checker(t_ps *data);
void	execute_operation(t_ps *data, char *op);

#endif
