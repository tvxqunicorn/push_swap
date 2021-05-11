/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:35:08 by xli               #+#    #+#             */
/*   Updated: 2021/05/11 10:41:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_deque_list	*init_deque_list(void *ptr)
{
	t_deque_list	*deque_list;

	deque_list = ft_malloc(1, sizeof(t_deque_list));
	if (deque_list == NULL)
		return (NULL);
	deque_list->content = ptr;
	deque_list->next = NULL;
	deque_list->last = NULL;
	return (deque_list);
}

void	deque_clear(t_deque *deque, void (* f)(void *))
{
	while (deque->size)
		deque_pop_back(deque, f);
}
