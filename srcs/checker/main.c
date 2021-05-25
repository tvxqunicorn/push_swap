/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 08:56:00 by xli               #+#    #+#             */
/*   Updated: 2021/05/25 10:53:38 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*arr;
	int		arr_size;
	t_list	*operations;
	char	*line;

	arr_size = get_arr_size(&arr, ac, av);
	if (arr_size == 0)
		normal_exit();
	operations = NULL;
	while (get_next_line(0, &line) == 1)
	{
		check_operations(line);
		ft_lstadd_back(&operations, ft_lstnew(line));
	}
	if (arr_size == 0)
		normal_exit();
	else if (checker(arr, arr_size, operations))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_free_all();
	return (0);
}
