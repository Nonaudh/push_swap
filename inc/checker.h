#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	check_swap(t_ps *data, char *op);
void	check_push(t_ps *data, char *op);
void	check_rotate(t_ps *data, char *op);
void	check_reverse_rotate(t_ps *data, char *op);

void    checker(t_ps *data);
void	execute_operation(t_ps *data, char *op);

#endif