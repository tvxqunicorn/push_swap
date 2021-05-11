/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:14:13 by xli               #+#    #+#             */
/*   Updated: 2021/05/11 09:33:32 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_deque	*init_deque(void)
{
	t_deque	*deque;

	deque = ft_malloc(1, sizeof(t_deque));
	if (deque == NULL)
		return (NULL);
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
}

void	deque_push_back(t_deque *deque, void *ptr)
{
	t_deque_list	*temp;

	(deque->size)++;
	temp = init_deque();
	if (temp == NULL)
		return ;
	if (deque->size == 1)
	{
		deque->head = temp;
		deque->tail = temp;
		return ;
	}
	temp->last = deque->tail;
	deque->tail->next = temp;
	deque->tail = deque->tail->next;
}

void	deque_push_front(t_deque *deque, void *ptr)
{
	t_deque_list	*temp;

	(deque->size)++;
	if (temp == NULL)
		return ;
	if (deque->size == 1)
	{
		deque->head = temp;
		deque->tail = temp;
		return ;
	}
	temp->next = deque->head;
	deque->head->next = temp;
	deque->head = deque->head->last;
}

void	deque_pop_back(t_deque *deque, void (* f)(void *))
{
	t_deque_list	*temp;

	if (deque->size < 1 || !deque->tail)
		return ;
	(deque->size)--;
	temp = deque->tail;
	deque->tail = deque->tail->last;
	if (deque->tail)
		deque->tail->next = NULL;
	if (f)
		f(temp->content);
	ft_free(temp);
}

void	deque_pop_front(t_deque *deque, void (* f)(void *))
{
	t_deque_list	*temp;

	if (deque->size < 1 || !deque->head)
		return ;
	(deque->size)--;
	temp = deque->head;
	deque->head = deque->head->next;
	if (deque->head)
		deque->head->last = NULL;
	if (f)
		f(temp->content);
	ft_free(temp);
}
