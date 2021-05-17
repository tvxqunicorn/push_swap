/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:23:52 by xli               #+#    #+#             */
/*   Updated: 2021/05/17 16:26:15 by xli              ###   ########lyon.fr   */
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
	int	*hash;
	int	*a;
	int	ct;

	hash = ft_malloc(arr_size, sizeof(int));
	if (hash == NULL)
		error_exit();
	ct = -1;
	while (++ct < arr_size)
		temp[ct] = arr[ct];
	ct = -1;
	while (++ct < arr_size)
		hash[temp[ct]] = ct;
	ct = -1;
	while (++ct < arr_size)
		arr[ct] = hash[arr[ct]];
	ct = -1;
	a = ft_malloc(arr_size, sizeof(int));
	if (a == NULL)
		error_exit();
	while (++ct < arr_size)
		a[ct] = arr[ct];
}
