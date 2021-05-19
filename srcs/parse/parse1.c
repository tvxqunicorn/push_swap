/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:28:00 by xli               #+#    #+#             */
/*   Updated: 2021/05/19 09:36:21 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (*((int *)temp->content) != ct)
			return (0);
		temp = temp->last;
	}
	return (1);
}
