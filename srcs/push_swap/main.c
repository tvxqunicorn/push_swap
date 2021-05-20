/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:14:39 by xli               #+#    #+#             */
/*   Updated: 2021/05/20 14:40:41 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ct[0] = ct;
**ct[1] = arr_size;
*/

static void	init(int ct[2], int *arr[2], t_deque *stack[2])
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
	ct[0] = -1;
	while (++ct[0] < ct[1])
		arr[1][ct[0]] = arr[0][ct[0]];
}

int	main(int ac, char **av)
{
	int		*arr[2];
	int		ct[2];
	t_deque	*stack[2];
	t_deque	*operations;

	ct[1] = get_arr_size(arr, ac, av);
	init(ct, arr, stack);
	ft_sort(arr[1], ct[1]); //sorted done
	//for (int i = 0; i < ct[1] ; i++)
	//	printf("sorted = %d\n", arr[1][i]);
	index_nb(stack[0], arr, ct[1]); //index done
	//t_deque_list	*iter = stack[0]->head;
	//while (iter)
	//{
	//	printf("indexed = %d\n", *((int*)iter->content));
	//	iter = iter->next;
	//}
	operations = push_swap(stack);
	normal_exit();
}
