/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:10:57 by xli               #+#    #+#             */
/*   Updated: 2021/05/22 18:08:50 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_solve(t_deque *stack[2], t_deque *operations)
{
	//int	top;
	//int	bottom;
	int	ct;

	//top = *(int *)stack[0]->tail->content;
	//bottom = *(int *)stack[0]->head->content;
	ct = -1;
	while (++ct < stack[0]->size)
	{

		if (get_pos(get_min(stack), stack) <= (stack[0]->size / 2))
		{
			//printf("top: %d\n", *(int *)stack[0]->tail->content);
			if (get_min(stack) == *(int *)stack[0]->tail->content)
				do_operations(stack, "pb", operations);
			else
			{
				do_operations(stack, "ra", operations);
				do_operations(stack, "pb", operations);
			}
		}
		else
		{
			//printf("bottom: %d\n", *(int *)stack[0]->head->content);
			if (get_min(stack) == *(int *)stack[0]->head->content)
			{
				do_operations(stack, "rra", operations);
				do_operations(stack, "pb", operations);
			}
			else
				do_operations(stack, "rra", operations);
		}
		if (stack_a_is_sorted(stack))
			break ;
	}
	while (stack[1]->size > 0)
		do_operations(stack, "pa", operations);
}
