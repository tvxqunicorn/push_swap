/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:14:03 by xli               #+#    #+#             */
/*   Updated: 2021/05/11 16:12:31 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_deque *stack, int *arr, int arr_size)
{
	int	ct;

	ct = -1;
	while (++ct < arr_size)
		deque_push_back(stack, arr + ct);
}

void	assign_operation(t_deque *stack[2], void *ptr)
{
	char	*str;

	str = ptr;
	if (!ft_strncmp(str, "sa", 3))
		sa(stack);
	if (!ft_strncmp(str, "sb", 3))
		sb(stack);
	if (!ft_strncmp(str, "ss", 3))
		ss(stack);
	if (!ft_strncmp(str, "pa", 3))
		pa(stack);
	if (!ft_strncmp(str, "pb", 3))
		pb(stack);
	if (!ft_strncmp(str, "ra", 3))
		ra(stack);
	if (!ft_strncmp(str, "rb", 3))
		rb(stack);
	if (!ft_strncmp(str, "rr", 3))
		rr(stack);
	if (!ft_strncmp(str, "rra", 4))
		rra(stack);
	if (!ft_strncmp(str, "rrb", 4))
		rrb(stack);
	if (!ft_strncmp(str, "rrr", 4))
		rrr(stack);
}
