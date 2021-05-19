/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:14:39 by xli               #+#    #+#             */
/*   Updated: 2021/05/19 16:39:23 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_handle(int ct[2], int *arr[3], t_deque *stack[2])
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

int	main(int ac, char **av)
{
	int		*arr[3];
	int		ct[2];
	t_deque	*stack[2];
	t_deque	*operations;

	ct[0] = -1;
	ct[1] = get_arr_size(arr, ac, av);
	exit_handle(ct, arr, stack);
	while (++ct[0] < ct[1])
		arr[1][ct[0]] = arr[0][ct[0]];
	arr[2] = ft_malloc(ct[1], sizeof(int));
	if (arr[2] == NULL)
		error_exit();
	ct[0] = -1;
	while (++ct[0] < ct[1])
		arr[2][ct[0]] = arr[0][ct[0]];
	ft_sort(arr[2], ct[1]);
	index_nb(stack[0], arr[0], arr[2], ct[1]);
	operations = push_swap(stack);
	normal_exit();
}
