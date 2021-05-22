/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:01:42 by xli               #+#    #+#             */
/*   Updated: 2021/05/22 17:14:08 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sub(long long ct[3], char **str)
{
	ct[0] = -1LL;
	if (str[0][0] == '+' || str[0][0] == '-')
		ct[0] = 0LL;
	ct[2] = 1LL;
	if (str[0][0] == '-')
		ct[2] = -1LL;
	ct[1] = 0LL;
	if ((str[0][0] == '-' || str[0][0] == '+') && !ft_isdigit(str[0][1]))
		error_exit();
}

int	ft_atoi_with_range(char **str)
{
	long long int	ct[3];

	sub(ct, str);
	while (str[0][++ct[0]])
	{
		if (!ft_isdigit(str[0][ct[0]]))
		{
			*str += ct[0];
			if (ft_isspace(str[0][0]))
				return (ct[1] * ct[2]);
			error_exit();
		}
		ct[1] = 10LL * ct[1] + str[0][ct[0]] - '0';
		if ((ct[2] == 1LL && ct[1] > 2147483647LL) || (ct[2] == -1LL && ct[1]
				> 2147483648LL) || (ct[1] == 0LL
				&& ft_isdigit(str[0][ct[0] + 1])))
			error_exit();
	}
	*str += ct[0];
	return (ct[1] * ct[2]);
}

int get_min(t_deque *stack[2])
{
	t_deque_list	*temp;
	int				min;
	int				ct;

	temp = stack[0]->tail;
	min = 2147483647;
	ct = -1;
	while (++ct < stack[0]->size)
	{
		if (*(int *)temp->content < min)
			min = *(int *)temp->content;
		temp = temp->last;
	}
	return (min);
}

int	get_pos(int	nb, t_deque *stack[2])
{
	t_deque_list	*temp;
	int				ct;

	temp = stack[0]->tail;
	ct = 0;
	while (*((int *)temp->content) != nb)
	{
		temp = temp->last;
		ct++;
	}
	return (ct);
}
