/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:02:04 by xli               #+#    #+#             */
/*   Updated: 2021/05/21 18:31:56 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_solve(t_deque *stack[2], t_deque *operations)
{
	int	max_bits;
	int	ct[2];
	int	top_nb;
	int	size;

	max_bits = 0;
	size = stack[0]->size;
	while ((1 << max_bits) < size)
		++max_bits;
	ct[0] = -1;
	while (++ct[0] < max_bits)
	{
		ct[1] = -1;
		while (++ct[1] < size)
		{
			top_nb = *(int *)stack[0]->tail->content;
			if ((top_nb >> ct[0]) & 1)
				do_operations(stack, "ra", operations);
			else
				do_operations(stack, "pb", operations);
		}
		while (stack[1]->size > 0)
			do_operations(stack, "pa", operations);
	}
}
