/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:12:24 by xli               #+#    #+#             */
/*   Updated: 2021/05/14 15:15:37 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putendl_fd("error", 2);
	ft_free_all();
	exit(EXIT_FAILURE);
}

void	normal_exit(void)
{
	ft_free_all();
	exit(EXIT_SUCCESS);
}
