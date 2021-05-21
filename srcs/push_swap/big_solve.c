/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:02:04 by xli               #+#    #+#             */
/*   Updated: 2021/05/21 12:11:48 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_nb(t_deque *a, int *arr[2], int arr_size)
{
	int		ct[2];

	ct[0] = -1;
	while (++ct[0] < arr_size)
	{
		ct[1] = -1;
		while (++ct[1] < arr_size)
		{
			if (arr[0][ct[0]] == arr[1][ct[1]])
			{
				arr[0][ct[0]] = ct[1];
				break ;
			}
		}
	}
	a = init_deque();
	ct[0] = -1;
	while (++ct[0] < arr_size)
		deque_push_front(a, arr + ct[0]);
}

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
	//printf("max_bits: %d\n", max_bits);
	ct[0] = -1;
	while (++ct[0] < max_bits)
	{
		ct[1] = -1;
		while (++ct[1] < size)
		{
			top_nb = *(int *)stack[0]->tail->content;
			//printf("top_nb:			%d\n", top_nb);
			//printf("ct[0]:			%d\n", ct[0]);
			//printf("top_nb >> ct[0]) & 1:	%d\n", (top_nb >> ct[0]) & 1);
			if ((top_nb >> ct[0]) & 1)
			{
				do_operations(stack, "ra", operations);
				write(1, "ra\n", 3);
			}
			else
			{
				do_operations(stack, "pb", operations);
				write(1, "pb\n", 3);
			}
		}
		while (stack[1]->size > 0)
		{
			do_operations(stack, "pa", operations);
			write(1, "pa\n", 3);
		}
	}
}
