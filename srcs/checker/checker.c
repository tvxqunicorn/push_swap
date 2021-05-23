/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 08:42:16 by xli               #+#    #+#             */
/*   Updated: 2021/05/23 08:42:48 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_instructions(char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		return ;
	if (!ft_strncmp(str, "sb", 3))
		return ;
	if (!ft_strncmp(str, "ss", 3))
		return ;
	if (!ft_strncmp(str, "pa", 3))
		return ;
	if (!ft_strncmp(str, "pb", 3))
		return ;
	if (!ft_strncmp(str, "ra", 3))
		return ;
	if (!ft_strncmp(str, "rb", 3))
		return ;
	if (!ft_strncmp(str, "rr", 3))
		return ;
	if (!ft_strncmp(str, "rra", 4))
		return ;
	if (!ft_strncmp(str, "rrb", 4))
		return ;
	if (!ft_strncmp(str, "rrr", 4))
		return ;
}
