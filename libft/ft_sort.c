/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:31:10 by xli               #+#    #+#             */
/*   Updated: 2021/05/20 14:22:00 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(int *arr, int arr_size)
{
	int	i;
	int	j;
	int	temp;
	int	is_sorted;

	i = -1;
	while (++i < arr_size - 1)
	{
		is_sorted = 1;
		j = -1;
		while (++j < arr_size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				is_sorted = 0;
			}
		}
		if (is_sorted)
			break ;
	}
}
