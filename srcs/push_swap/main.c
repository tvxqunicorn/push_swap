/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:14:39 by xli               #+#    #+#             */
/*   Updated: 2021/05/17 16:08:08 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*arr[3];
	int		ct[2];
	t_deque	*stack[2];

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
	ft_sort(arr[1], ct[1]);
	index_nb(arr[1], arr[2], ct[1]);
	normal_exit();
}
