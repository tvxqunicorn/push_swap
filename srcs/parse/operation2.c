/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:11:04 by xli               #+#    #+#             */
/*   Updated: 2021/05/11 14:11:30 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->head->content;
	deque_pop_front(stack[0], NULL);
	deque_push_back(stack[0], ptr);
}

void	rrb(t_deque *stack[2])
{
	void	*ptr;

	if (stack[1]->size == 0)
		return ;
	ptr = stack[1]->head->content;
	deque_pop_front(stack[1], NULL);
	deque_push_back(stack[1], ptr);
}

void	rrr(t_deque *stack[2])
{
	rra(stack);
	rrb(stack);
}
