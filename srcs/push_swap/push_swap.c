/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:23:52 by xli               #+#    #+#             */
/*   Updated: 2021/05/18 14:44:02 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_handle(int ct[2], int *arr[3], t_deque *stack[2])
{
	if (ct[1] < 2)
		normal_exit();
	if (!(stack[0] = init_deque()))
		error_exit();
	if (!(stack[1] = init_deque()))
		error_exit();
	init_stack(stack[0], arr[0], ct[1]);
	arr[1] = ft_malloc(ct[1], sizeof(int));
	if (arr[1] == NULL)
		error_exit();
}

void	index_nb(int *arr, int *temp, int arr_size)
{
	t_deque			*a;
	int				ct[2];

	ct[0] = -1;
	while (++ct[0] < arr_size)
		temp[ct[0]] = arr[ct[0]];
	ft_sort(arr, arr_size);
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
	for(int i = 0 ; i < arr_size ; ++i)
		deque_push_front(a, arr + i);
	t_deque_list	*iter = a->tail;
	while (iter)
	{
		printf("%d\n", *((int*)iter->content));
		iter = iter->last;
	}
}
