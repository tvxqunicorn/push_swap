/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:10:06 by xli               #+#    #+#             */
/*   Updated: 2021/05/11 14:11:28 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->tail->content;
	deque_pop_back(stack[0], NULL);
	deque_push_front(stack[0], ptr);
}

void	rb(t_deque *stack[2])
{
	void	*ptr;

	if (stack[1]->size == 0)
		return ;
	ptr = stack[1]->tail->content;
	deque_pop_back(stack[1], NULL);
	deque_push_front(stack[1], ptr);
}

void	rr(t_deque *stack[2])
{
	ra(stack);
	rb(stack);
}
