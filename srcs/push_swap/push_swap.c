/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:23:52 by xli               #+#    #+#             */
/*   Updated: 2021/05/22 14:04:08 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*push_swap(t_deque *stack[2])
{
	t_deque	*operations;

	operations = init_deque();
	if (is_sorted(stack))
		return (operations);
	if (stack[0]->size <= 5)
		small_solve(stack, operations);
	else
		big_solve(stack, operations);
	return (operations);
}
