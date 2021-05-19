/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:02:04 by xli               #+#    #+#             */
/*   Updated: 2021/05/19 16:49:51 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_nb(t_deque *stack, int *arr, int *temp, int arr_size)
{
	t_deque	*a;
	int		ct[2];

	(void)stack;
	ct[0] = -1;
	while (++ct[0] < arr_size)
		temp[ct[0]] = arr[ct[0]];
	//ft_sort(arr, arr_size);
	ct[0] = -1;
	while (++ct[0] < arr_size)
	{
		ct[1] = -1;
		while (++ct[1] < arr_size)
		{
			if (arr[ct[0]] == temp[ct[1]])
				arr[ct[0]] = ct[1];
		}
	}
	a = init_deque();
	ct[0] = -1;
	while (++ct[0] < arr_size)
		deque_push_front(a, arr + ct[0]);
	t_deque_list	*iter = a->tail;
	while (iter)
	{
		printf("%d\n", *((int*)iter->content));
		iter = iter->last;
	}
}

void	big_solve(t_deque *stack[2], t_deque *operations)
{
	int	max_bits;
	int	ct[2];
	int	top_nb;

	max_bits = 0;
	while ((stack[0]->size - 1) >> max_bits)
		++max_bits;
	ct[0] = -1;
	while (++ct[0] < max_bits)
	{
		ct[1] = -1;
		while (++ct[1] < stack[0]->size)
		{
			top_nb = *(int *)stack[0]->tail;
			if (top_nb >> ct[0] & 1)
				do_operations(stack, "ra", operations);
			else
				do_operations(stack, "pb", operations);
		}
		while (stack[1]->size != 0)
			do_operations(stack, "pa", operations);
	}
}
