/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:34:19 by xli               #+#    #+#             */
/*   Updated: 2021/05/11 14:10:52 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *stack[2])
{
	void	*ptr[2];

	if (stack[0]->size > 1)
	{
		ptr[0] = stack[0]->tail->content;
		deque_pop_back(stack[0], NULL);
		ptr[1] = stack[0]->tail->content;
		deque_pop_back(stack[0], NULL);
		deque_push_back(stack[0], ptr[0]);
		deque_push_back(stack[0], ptr[1]);
	}
}

void	sb(t_deque *stack[2])
{
	void	*ptr[2];

	if (stack[1]->size > 1)
	{
		ptr[0] = stack[1]->tail->content;
		deque_pop_back(stack[1], NULL);
		ptr[1] = stack[1]->tail->content;
		deque_pop_back(stack[1], NULL);
		deque_push_back(stack[1], ptr[0]);
		deque_push_back(stack[1], ptr[1]);
	}
}

void	ss(t_deque *stack[2])
{
	sa(stack);
	sb(stack);
}

void	pa(t_deque *stack[2])
{
	void	*ptr;

	if (stack[1]->size > 0)
	{
		ptr = stack[1]->tail->content;
		deque_pop_back(stack[1], NULL);
		deque_push_back(stack[0], ptr);
	}
}

void	pb(t_deque *stack[2])
{
	void	*ptr;

	if (stack[0]->size > 0)
	{
		ptr = stack[0]->tail->content;
		deque_pop_back(stack[0], NULL);
		deque_push_back(stack[1], ptr);
	}
}
