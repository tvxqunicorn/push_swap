/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:23:52 by xli               #+#    #+#             */
/*   Updated: 2021/05/20 13:28:36 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*push_swap(t_deque *stack[2])
{
	t_deque	*operations;

	operations = init_deque();
	if (is_sorted(stack))
	{
		printf("sorted\n");
		return (operations);
	}
	if (stack[0]->size <= 5)
		printf("small solve\n");
	else
	{
		printf("big solve\n");
		big_solve(stack, operations);
	}
	return (operations);
}
