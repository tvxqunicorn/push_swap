/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:23:52 by xli               #+#    #+#             */
/*   Updated: 2021/05/20 11:15:32 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_operations(t_deque *operations, int *arr, int arr_size, int fd)
{
	t_deque			*stack[2];
	t_deque_list	*iter;

	if (!(stack[0] = init_deque()))
		error_exit();
	if (!(stack[1] = init_deque()))
		error_exit();
	init_stack(stack[0], arr, arr_size);
	iter = operations->head;
	while (iter)
	{
		assign_operation(stack, iter->content);
		ft_putendl_fd(iter->content, fd);
		iter = iter->next;
	}
}

t_deque	*push_swap(t_deque *stack[2])
{
	t_deque	*operations;

	operations = init_deque();
	if (is_sorted(stack))
	{
		printf("sorted\n");
		return (operations);
	}
	if (stack[0]->size <= 5)
		printf("small solve\n");
	else
		big_solve(stack, operations);
	return (operations);
}
