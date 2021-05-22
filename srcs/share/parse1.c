/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:28:00 by xli               #+#    #+#             */
/*   Updated: 2021/05/22 17:52:43 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_a_is_sorted(t_deque *stack[2])
{
	t_deque_list	*temp;
	int				ct;

	temp = stack[0]->tail;
	ct = -1;
	while (++ct < stack[0]->size)
	{
		if (*((int *)temp->content) > *((int *)temp->last->content))
			return (0);
		temp = temp->last;
	}
	return (1);
}

int	is_sorted(t_deque *stack[2])
{
	t_deque_list	*temp;
	int				ct;

	if (stack[1]->size != 0)
		return (0);
	temp = stack[0]->tail;
	ct = -1;
	while (++ct < stack[0]->size)
	{
		//printf("temp->content = %d\n", *(int *)temp->content);
		if (*((int *)temp->content) != ct)
			return (0);
		temp = temp->last;
	}
	return (1);
}

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	ft_free_all();
	exit(EXIT_FAILURE);
}

void	normal_exit(void)
{
	ft_free_all();
	exit(EXIT_SUCCESS);
}
