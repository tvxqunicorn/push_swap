/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:02:18 by xli               #+#    #+#             */
/*   Updated: 2021/05/19 09:27:42 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_nb_in_list(t_list **lst, char *str)
{
	int	*temp;

	temp = ft_malloc(1, sizeof(temp));
	while (*str)
	{
		if (ft_isspace(*str))
			str++;
		else if (ft_isdigit(*str) || *str == '+' || *str == '-')
		{
			if (temp == NULL)
				error_exit();
			*temp = ft_atoi_max(&str);
			ft_lstadd_back(lst, ft_lstnew((void *)temp));
		}
		else
			error_exit();
	}
}

int	check_duplicate(int *arr, int arr_size)
{
	int	ct[2];

	ct[0] = -1;
	while (++ct[0] < arr_size - 1)
	{
		ct[1] = ct[0];
		while (++ct[1] < arr_size)
		{
			if (arr[ct[1]] == arr[ct[0]])
				return (1);
		}
	}
	return (0);
}

int	get_arr_size(int **arr, int ac, char **av)
{
	t_list	*lst;
	int		ct;

	lst = NULL;
	if (ac == 1)
		return (0);
	ct = 0;
	while (++ct < ac)
		put_nb_in_list(&lst, av[ct]);
	*arr = ft_malloc(ft_lstsize(lst), sizeof(int));
	if (*arr == NULL)
		error_exit();
	ct = 0;
	while (lst)
	{
		arr[0][ct++] = *((int *)lst->content);
		lst = lst->next;
	}
	if (check_duplicate(arr[0], ct))
		error_exit();
	return (ct);
}

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
