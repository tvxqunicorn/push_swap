/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 08:42:16 by xli               #+#    #+#             */
/*   Updated: 2021/05/23 18:21:11 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(int *arr, int arr_size, t_list *operations)
{
	t_deque	*stack[2];

	stack[0] = init_deque();
	stack[1] = init_deque();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr, arr_size);
	while (operations)
	{
		assign_operation(stack, operations->content);
		operations = operations->next;
	}
	if (stack[1]->size)
		return (0);
	if (!stack_a_is_sorted(stack))
		return (0);
	return (1);
}
