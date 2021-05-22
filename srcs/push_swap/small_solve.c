/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:10:57 by xli               #+#    #+#             */
/*   Updated: 2021/05/22 22:28:40 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exception0(t_deque *stack[2], t_deque *operations)
{
	t_deque_list	*temp;

	if (stack[0]->size != 3)
		return (0);
	temp = stack[0]->tail;
	if (*((int *)temp->content) != 2)
		return (0);
	temp = temp->last;
	if (*((int *)temp->content) != 1)
		return (0);
	temp = temp->last;
	if (*((int *)temp->content) != 0)
		return (0);
	do_operations(stack, "sa", operations);
	do_operations(stack, "rra", operations);
	return (1);
}

static int	exception1(t_deque *stack[2], t_deque *operations)
{
	t_deque_list	*temp;

	if (stack[0]->size != 3)
		return (0);
	temp = stack[0]->tail;
	if (*((int *)temp->content) != 1)
		return (0);
	temp = temp->last;
	if (*((int *)temp->content) != 0)
		return (0);
	temp = temp->last;
	if (*((int *)temp->content) != 2)
		return (0);
	do_operations(stack, "sa", operations);
	return (1);
}

void	small_solve(t_deque *stack[2], t_deque *operations)
{
	if (exception0(stack, operations) || exception1(stack, operations))
		return ;
	while (stack[0]->size > 2)
	{
		if (get_pos(get_min(stack), stack) <= (stack[0]->size / 2))
		{
			if (get_min(stack) == *(int *)stack[0]->tail->content)
				do_operations(stack, "pb", operations);
			else
				do_operations(stack, "ra", operations);
		}
		else
			do_operations(stack, "rra", operations);
		if (stack_a_is_sorted(stack))
			break ;
	}
	if (!stack_a_is_sorted(stack))
		do_operations(stack, "sa", operations);
	while (stack[1]->size > 0)
		do_operations(stack, "pa", operations);
}
