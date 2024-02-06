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

# include "push_swap.h"

void	check_swap(t_ps *data, char *op);
void	check_push(t_ps *data, char *op);
void	check_rotate(t_ps *data, char *op);
void	check_reverse_rotate(t_ps *data, char *op);

void	checker(t_ps *data);
void	execute_operation(t_ps *data, char *op);

#endif
